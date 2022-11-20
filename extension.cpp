/**
 * CSWeaponsAPI
 * Copyright (C) 2022-2022 Omer 'KoNLiG' Ben Tzion. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "extension.h"
#include "natives.h"
#include "classes.h"

#include "detours.h"

CSWeaponsAPI g_CSWeaponsAPI;
SMEXT_LINK(&g_CSWeaponsAPI);

IBinTools *g_pBinTools;

CDetour *g_pLoadCSWeaponDataDetour = NULL;

IGameConfig* g_pGameConf;

IForward *g_pCSWeaponDataLoadedFwd = NULL;

CUtlVector<CCSWeaponData *> g_CCSWeaponDataList;

DETOUR_DECL_STATIC1(Detour_OnLoadCSWeaponData, bool, CCSWeaponData*, pCCSWeaponData)
{
    bool success = DETOUR_STATIC_CALL(Detour_OnLoadCSWeaponData)(pCCSWeaponData);

    if (success)
    {
        if (g_CCSWeaponDataList.Find(pCCSWeaponData) == g_CCSWeaponDataList.InvalidIndex())
        {
            g_CCSWeaponDataList.AddToTail(pCCSWeaponData);
        }

        if (g_pCSWeaponDataLoadedFwd->GetFunctionCount())
        {
            g_pCSWeaponDataLoadedFwd->PushCell((cell_t)pCCSWeaponData);
            g_pCSWeaponDataLoadedFwd->Execute();
        }
    }

    return success;
};

bool CSWeaponsAPI::SDK_OnLoad(char* error, size_t maxlength, bool late)
{
    char conf_error[255];

    if (!gameconfs->LoadGameConfigFile("CSWeaponsAPI.games", &g_pGameConf, conf_error, sizeof(conf_error)))
    {
        snprintf(error, maxlength, "Could not read CSWeaponsAPI.games: %s", conf_error);

        return false;
    }

    CDetourManager::Init(g_pSM->GetScriptingEngine(), g_pGameConf);

    g_pLoadCSWeaponDataDetour = DETOUR_CREATE_STATIC(Detour_OnLoadCSWeaponData, "LoadCSWeaponData");
    if (!g_pLoadCSWeaponDataDetour)
    {
        snprintf(error, maxlength, "Unable to create a detour for 'LoadCSWeaponData'");
        return false;
    }

    g_pLoadCSWeaponDataDetour->EnableDetour();

    // void OnCSWeaponDataLoaded(CSWeaponData weapon_data)
    g_pCSWeaponDataLoadedFwd = forwards->CreateForward("OnCSWeaponDataLoaded", ET_Ignore, 1, NULL, Param_Cell);

    sharesys->AddNatives(myself, g_MyNatives);
    sharesys->RegisterLibrary(myself, "CSWeaponsAPI");

    return true;
}

void CSWeaponsAPI::SDK_OnAllLoaded()
{
    SM_GET_LATE_IFACE(BINTOOLS, g_pBinTools);
}

void CSWeaponsAPI::SDK_OnUnload()
{
    gameconfs->CloseGameConfigFile(g_pGameConf);

    if (g_pLoadCSWeaponDataDetour)
    {
        g_pLoadCSWeaponDataDetour->Destroy();
        g_pLoadCSWeaponDataDetour = NULL;
    }

    forwards->ReleaseForward(g_pCSWeaponDataLoadedFwd);
}

bool CSWeaponsAPI::QueryRunning(char *error, size_t maxlength)
{
    SM_CHECK_IFACE(BINTOOLS, g_pBinTools);
    return true;
}

void CSWeaponsAPI::NotifyInterfaceDrop(SMInterface *pInterface)
{
    if(!strcmp(pInterface->GetInterfaceName(), SMINTERFACE_BINTOOLS_NAME))
    {
        g_pBinTools = NULL;
    }
}