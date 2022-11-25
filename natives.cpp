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

static cell_t CSWeaponData_Constructor(IPluginContext* pContext, const cell_t* params)
{
    CEconItemView* pView = reinterpret_cast<CEconItemView*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pView);

    return reinterpret_cast<cell_t>(GetCCSWeaponData(pView));
}

static cell_t CSWeaponData_GetByClassName(IPluginContext* pContext, const cell_t* params)
{
    char* classname = nullptr;
    pContext->LocalToString(params[1], &classname);

    for (int i = 0; i < g_CCSWeaponDataList.Count(); i++)
    {
        CCSWeaponData* pCCSWeaponData = g_CCSWeaponDataList[i];

        if (!strcmp(classname, pCCSWeaponData->GetClassName()))
        {
            return reinterpret_cast<cell_t>(pCCSWeaponData);
        }
    }

    return 0;
}

static cell_t CSWeaponData_GetByIndex(IPluginContext* pContext, const cell_t* params)
{
    int index = (int)params[1];

    if (!g_CCSWeaponDataList.IsValidIndex(index))
    {
        return pContext->ThrowNativeError("Invalid given CCSWeaponData index (%d)", index);
    }

    return reinterpret_cast<cell_t>(g_CCSWeaponDataList[index]);
}

static cell_t CSWeaponData_Count(IPluginContext* pContext, const cell_t* params)
{
    return g_CCSWeaponDataList.Count();
}

static cell_t CSWeaponData_Size(IPluginContext* pContext, const cell_t* params)
{
    return sizeof(CCSWeaponData);
}

static cell_t CSWeaponData_GetHasSilencer(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->HasSilencer();
}

static cell_t CSWeaponData_SetHasSilencer(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetHasSilencer(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetFullAuto(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->FullAuto();
}

static cell_t CSWeaponData_SetFullAuto(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetFullAuto(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetShouldUnzoomAfterShot(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->ShouldUnzoomAfterShot();
}

static cell_t CSWeaponData_SetShouldUnzoomAfterShot(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetShouldUnzoomAfterShot(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetShouldHideViewModelZoomed(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->ShouldHideViewModelZoomed();
}

static cell_t CSWeaponData_SetShouldHideViewModelZoomed(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetShouldHideViewModelZoomed(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetHasBurstMode(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->HasBurstMode();
}

static cell_t CSWeaponData_SetHasBurstMode(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetHasBurstMode(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetIsRevolver(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->IsRevolver();
}

static cell_t CSWeaponData_SetIsRevolver(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetIsRevolver(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetCannotShootUnderwater(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->CannotShootUnderwater();
}

static cell_t CSWeaponData_SetCannotShootUnderwater(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetCannotShootUnderwater(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetItemDef(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->ItemDef();
}

static cell_t CSWeaponData_SetItemDef(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetItemDef(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetMaxClip1(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->MaxClip1();
}

static cell_t CSWeaponData_SetMaxClip1(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetMaxClip1(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetMaxClip2(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->MaxClip2();
}

static cell_t CSWeaponData_SetMaxClip2(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetMaxClip2(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetDefaultClip1(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->DefaultClip1();
}

static cell_t CSWeaponData_SetDefaultClip1(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetDefaultClip1(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetDefaultClip2(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->DefaultClip2();
}

static cell_t CSWeaponData_SetDefaultClip2(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetDefaultClip2(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetPrimaryReserveAmmoMax(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->PrimaryReserveAmmoMax();
}

static cell_t CSWeaponData_SetPrimaryReserveAmmoMax(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetPrimaryReserveAmmoMax(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetSecondaryReserveAmmoMax(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->SecondaryReserveAmmoMax();
}

static cell_t CSWeaponData_SetSecondaryReserveAmmoMax(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetSecondaryReserveAmmoMax(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetWeaponPrice(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->WeaponPrice();
}

static cell_t CSWeaponData_SetWeaponPrice(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetWeaponPrice(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetKillAward(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->KillAward();
}

static cell_t CSWeaponData_SetKillAward(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetKillAward(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetDamage(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->Damage();
}

static cell_t CSWeaponData_SetDamage(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetDamage(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetBullets(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->Bullets();
}

static cell_t CSWeaponData_SetBullets(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetBullets(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetCrosshairMinDistance(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->CrosshairMinDistance();
}

static cell_t CSWeaponData_SetCrosshairMinDistance(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetCrosshairMinDistance(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetCrosshairDeltaDistance(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->CrosshairDeltaDistance();
}

static cell_t CSWeaponData_SetCrosshairDeltaDistance(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetCrosshairDeltaDistance(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetRecoilSeed(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->RecoilSeed();
}

static cell_t CSWeaponData_SetRecoilSeed(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilSeed(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetSpreadSeed(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->SpreadSeed();
}

static cell_t CSWeaponData_SetSpreadSeed(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetSpreadSeed(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetRecoveryTransitionStartBullet(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->RecoveryTransitionStartBullet();
}

static cell_t CSWeaponData_SetRecoveryTransitionStartBullet(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoveryTransitionStartBullet(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetRecoveryTransitionEndBullet(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->RecoveryTransitionEndBullet();
}

static cell_t CSWeaponData_SetRecoveryTransitionEndBullet(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoveryTransitionEndBullet(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetZoomLevels(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->ZoomLevels();
}

static cell_t CSWeaponData_SetZoomLevels(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetZoomLevels(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetZoomFov1(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->ZoomFov1();
}

static cell_t CSWeaponData_SetZoomFov1(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetZoomFov1(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetZoomFov2(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->ZoomFov2();
}

static cell_t CSWeaponData_SetZoomFov2(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetZoomFov2(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetTracerFrequency(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->TracerFrequency();
}

static cell_t CSWeaponData_SetTracerFrequency(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetTracerFrequency(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetTracerFrequencyAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->TracerFrequencyAlt();
}

static cell_t CSWeaponData_SetTracerFrequencyAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetTracerFrequencyAlt(params[2]);

    return 1;
}

static cell_t CSWeaponData_GetWeaponType(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return pCCSWeaponData->WeaponType();
}

static cell_t CSWeaponData_SetWeaponType(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetWeaponType((CSWeaponType)params[2]);

    return 1;
}

static cell_t CSWeaponData_GetCycleTime(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->CycleTime());
}

static cell_t CSWeaponData_SetCycleTime(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetCycleTime(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetCycleTimeAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->CycleTimeAlt());
}

static cell_t CSWeaponData_SetCycleTimeAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetCycleTimeAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetTimeToIdle(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->TimeToIdle());
}

static cell_t CSWeaponData_SetTimeToIdle(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetTimeToIdle(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetIdleInterval(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->IdleInterval());
}

static cell_t CSWeaponData_SetIdleInterval(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetIdleInterval(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetHeadshotMultiplier(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->HeadshotMultiplier());
}

static cell_t CSWeaponData_SetHeadshotMultiplier(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetHeadshotMultiplier(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetArmorRatio(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->ArmorRatio());
}

static cell_t CSWeaponData_SetArmorRatio(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetArmorRatio(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetPenetration(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->Penetration());
}

static cell_t CSWeaponData_SetPenetration(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetPenetration(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetFlinchVelocityModifierLarge(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->FlinchVelocityModifierLarge());
}

static cell_t CSWeaponData_SetFlinchVelocityModifierLarge(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetFlinchVelocityModifierLarge(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetFlinchVelocityModifierSmall(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->FlinchVelocityModifierSmall());
}

static cell_t CSWeaponData_SetFlinchVelocityModifierSmall(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetFlinchVelocityModifierSmall(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRange(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->Range());
}

static cell_t CSWeaponData_SetRange(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRange(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRangeModifier(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RangeModifier());
}

static cell_t CSWeaponData_SetRangeModifier(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRangeModifier(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetThrowVelocity(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->ThrowVelocity());
}

static cell_t CSWeaponData_SetThrowVelocity(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetThrowVelocity(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetMaxPlayerSpeed(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->MaxPlayerSpeed());
}

static cell_t CSWeaponData_SetMaxPlayerSpeed(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetMaxPlayerSpeed(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetMaxPlayerSpeedAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->MaxPlayerSpeedAlt());
}

static cell_t CSWeaponData_SetMaxPlayerSpeedAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetMaxPlayerSpeedAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetAttackMovespeedFactor(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->AttackMovespeedFactor());
}

static cell_t CSWeaponData_SetAttackMovespeedFactor(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetAttackMovespeedFactor(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetSpread(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->Spread());
}

static cell_t CSWeaponData_SetSpread(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetSpread(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetSpreadAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->SpreadAlt());
}

static cell_t CSWeaponData_SetSpreadAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetSpreadAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyCrouch(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyCrouch());
}

static cell_t CSWeaponData_SetInaccuracyCrouch(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyCrouch(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyCrouchAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyCrouchAlt());
}

static cell_t CSWeaponData_SetInaccuracyCrouchAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyCrouchAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyStand(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyStand());
}

static cell_t CSWeaponData_SetInaccuracyStand(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyStand(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyStandAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyStandAlt());
}

static cell_t CSWeaponData_SetInaccuracyStandAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyStandAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyJumpInitial(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyJumpInitial());
}

static cell_t CSWeaponData_SetInaccuracyJumpInitial(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyJumpInitial(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyJumpApex(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyJumpApex());
}

static cell_t CSWeaponData_SetInaccuracyJumpApex(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyJumpApex(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyJump(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyJump());
}

static cell_t CSWeaponData_SetInaccuracyJump(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyJump(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyJumpAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyJumpAlt());
}

static cell_t CSWeaponData_SetInaccuracyJumpAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyJumpAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyLand(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyLand());
}

static cell_t CSWeaponData_SetInaccuracyLand(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyLand(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyLandAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyLandAlt());
}

static cell_t CSWeaponData_SetInaccuracyLandAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyLandAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyLadder(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyLadder());
}

static cell_t CSWeaponData_SetInaccuracyLadder(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyLadder(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyLadderAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyLadderAlt());
}

static cell_t CSWeaponData_SetInaccuracyLadderAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyLadderAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyFire(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyFire());
}

static cell_t CSWeaponData_SetInaccuracyFire(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyFire(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyFireAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyFireAlt());
}

static cell_t CSWeaponData_SetInaccuracyFireAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyFireAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyMove(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyMove());
}

static cell_t CSWeaponData_SetInaccuracyMove(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyMove(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyMoveAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyMoveAlt());
}

static cell_t CSWeaponData_SetInaccuracyMoveAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyMoveAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyReload(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyReload());
}

static cell_t CSWeaponData_SetInaccuracyReload(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyReload(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoilAngle(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoilAngle());
}

static cell_t CSWeaponData_SetRecoilAngle(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilAngle(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoilAngleAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoilAngleAlt());
}

static cell_t CSWeaponData_SetRecoilAngleAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilAngleAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoilAngleVariance(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoilAngleVariance());
}

static cell_t CSWeaponData_SetRecoilAngleVariance(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilAngleVariance(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoilAngleVarianceAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoilAngleVarianceAlt());
}

static cell_t CSWeaponData_SetRecoilAngleVarianceAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilAngleVarianceAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoilMagnitude(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoilMagnitude());
}

static cell_t CSWeaponData_SetRecoilMagnitude(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilMagnitude(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoilMagnitudeAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoilMagnitudeAlt());
}

static cell_t CSWeaponData_SetRecoilMagnitudeAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilMagnitudeAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoilMagnitudeVariance(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoilMagnitudeVariance());
}

static cell_t CSWeaponData_SetRecoilMagnitudeVariance(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilMagnitudeVariance(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoilMagnitudeVarianceAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoilMagnitudeVarianceAlt());
}

static cell_t CSWeaponData_SetRecoilMagnitudeVarianceAlt(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoilMagnitudeVarianceAlt(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoveryTimeCrouch(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoveryTimeCrouch());
}

static cell_t CSWeaponData_SetRecoveryTimeCrouch(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoveryTimeCrouch(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoveryTimeStand(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoveryTimeStand());
}

static cell_t CSWeaponData_SetRecoveryTimeStand(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoveryTimeStand(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoveryTimeCrouchFinal(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoveryTimeCrouchFinal());
}

static cell_t CSWeaponData_SetRecoveryTimeCrouchFinal(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoveryTimeCrouchFinal(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetRecoveryTimeStandFinal(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->RecoveryTimeStandFinal());
}

static cell_t CSWeaponData_SetRecoveryTimeStandFinal(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetRecoveryTimeStandFinal(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetZoomTime0(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->ZoomTime0());
}

static cell_t CSWeaponData_SetZoomTime0(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetZoomTime0(sp_ctof(sp_ctof(params[2])));

    return 1;
}

static cell_t CSWeaponData_GetZoomTime1(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->ZoomTime1());
}

static cell_t CSWeaponData_SetZoomTime1(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetZoomTime1(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetZoomTime2(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->ZoomTime2());
}

static cell_t CSWeaponData_SetZoomTime2(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetZoomTime2(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetAddonScale(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->AddonScale());
}

static cell_t CSWeaponData_SetAddonScale(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetAddonScale(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetHeatPerShot(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->HeatPerShot());
}

static cell_t CSWeaponData_SetHeatPerShot(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetHeatPerShot(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracyPitchShift(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracyPitchShift());
}

static cell_t CSWeaponData_SetInaccuracyPitchShift(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracyPitchShift(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetInaccuracySoundThreshold(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->InaccuracySoundThreshold());
}

static cell_t CSWeaponData_SetInaccuracySoundThreshold(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetInaccuracySoundThreshold(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetBotAudibleRange(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    return sp_ftoc(pCCSWeaponData->BotAudibleRange());
}

static cell_t CSWeaponData_SetBotAudibleRange(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    pCCSWeaponData->SetBotAudibleRange(sp_ctof(params[2]));

    return 1;
}

static cell_t CSWeaponData_GetClassName(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;

    const char* className = pCCSWeaponData->GetClassName();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), className ? className : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetClassName(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetClassName(source);

    return numBytes;
}

static cell_t CSWeaponData_GetViewModel(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;

    const char* viewModel = pCCSWeaponData->GetViewModel();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), viewModel ? viewModel : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetViewModel(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetViewModel(source);

    return numBytes;
}

static cell_t CSWeaponData_GetWorldModel(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;

    const char* worldModel = pCCSWeaponData->GetWorldModel();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), worldModel ? worldModel : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetWorldModel(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetWorldModel(source);

    return numBytes;
}

static cell_t CSWeaponData_GetDroppedModel(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* droppedModel = pCCSWeaponData->GetDroppedModel();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), droppedModel ? droppedModel : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetDroppedModel(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetDroppedModel(source);

    return numBytes;
}

static cell_t CSWeaponData_GetShotSound(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* shotSound = pCCSWeaponData->GetShotSound();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), shotSound ? shotSound : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetShotSound(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetShotSound(source);

    return numBytes;
}

static cell_t CSWeaponData_GetEmptySound(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* emptySound = pCCSWeaponData->GetEmptySound();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), emptySound ? emptySound : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetEmptySound(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetEmptySound(source);

    return numBytes;
}

static cell_t CSWeaponData_GetBulletType(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* bulletType = pCCSWeaponData->GetBulletType();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), bulletType ? bulletType : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetBulletType(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetBulletType(source);

    return numBytes;
}

static cell_t CSWeaponData_GetHudName(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* hudName = pCCSWeaponData->GetHudName();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), hudName ? hudName : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetHudName(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetHudName(source);

    return numBytes;
}

static cell_t CSWeaponData_GetDefaultName(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* defaultName = pCCSWeaponData->GetDefaultName();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), defaultName ? defaultName : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetDefaultName(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetDefaultName(source);

    return numBytes;
}

static cell_t CSWeaponData_GetAnimationPrefix(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* animationPrefix = pCCSWeaponData->GetAnimationPrefix();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), animationPrefix ? animationPrefix : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetAnimationPrefix(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetAnimationPrefix(source);

    return numBytes;
}

static cell_t CSWeaponData_GetSilencerModel(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* silencerModel = pCCSWeaponData->GetSilencerModel();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), silencerModel ? silencerModel : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetSilencerModel(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetSilencerModel(source);

    return numBytes;
}

static cell_t CSWeaponData_GetAddonlocation(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* addonlocation = pCCSWeaponData->GetAddonlocation();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), addonlocation ? addonlocation : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetAddonlocation(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetAddonlocation(source);

    return numBytes;
}

static cell_t CSWeaponData_GetEjectBrassEffect(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* ejectBrassEffect = pCCSWeaponData->GetEjectBrassEffect();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), ejectBrassEffect ? ejectBrassEffect : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetEjectBrassEffect(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetEjectBrassEffect(source);

    return numBytes;
}

static cell_t CSWeaponData_GetTracerEffect(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* tracerEffect = pCCSWeaponData->GetTracerEffect();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), tracerEffect ? tracerEffect : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetTracerEffect(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetTracerEffect(source);

    return numBytes;
}

static cell_t CSWeaponData_GetMuzzleFlashEffect1stPerson(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* muzzleFlashEffect1stPerson = pCCSWeaponData->GetMuzzleFlashEffect1stPerson();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), muzzleFlashEffect1stPerson ? muzzleFlashEffect1stPerson : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetMuzzleFlashEffect1stPerson(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetMuzzleFlashEffect1stPerson(source);

    return numBytes;
}

static cell_t CSWeaponData_GetHeatEffect(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* heatEffect = pCCSWeaponData->GetHeatEffect();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), heatEffect ? heatEffect : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetHeatEffect(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetHeatEffect(source);

    return numBytes;
}

static cell_t CSWeaponData_GetZoomInSound(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* zoomInSound = pCCSWeaponData->GetZoomInSound();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), zoomInSound ? zoomInSound : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetZoomInSound(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetZoomInSound(source);

    return numBytes;
}

static cell_t CSWeaponData_GetZoomOutSound(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    size_t numBytes = 0;
    const char* zoomOutSound = pCCSWeaponData->GetZoomOutSound();
    pContext->StringToLocalUTF8(params[2], static_cast<size_t>(params[3]), zoomOutSound ? zoomOutSound : "", &numBytes);

    return numBytes;
}

static cell_t CSWeaponData_SetZoomOutSound(IPluginContext* pContext, const cell_t* params)
{
    CCSWeaponData* pCCSWeaponData = reinterpret_cast<CCSWeaponData*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pCCSWeaponData);

    char* source = nullptr;
    size_t numBytes = pContext->LocalToString(params[2], &source);

    pCCSWeaponData->SetZoomOutSound(source);

    return numBytes;
}

extern const sp_nativeinfo_t g_MyNatives[] =
{
    { "CSWeaponData.CSWeaponData",                          CSWeaponData_Constructor },
    { "CSWeaponData.GetByClassName",                        CSWeaponData_GetByClassName },
    { "CSWeaponData.GetByIndex",                            CSWeaponData_GetByIndex },
    { "CSWeaponData.Count",                                 CSWeaponData_Count },
    { "CSWeaponData.Size",                                  CSWeaponData_Size },
    { "CSWeaponData.HasSilencer.get",                       CSWeaponData_GetHasSilencer },
    { "CSWeaponData.HasSilencer.set",                       CSWeaponData_SetHasSilencer },
    { "CSWeaponData.FullAuto.get",                          CSWeaponData_GetFullAuto },
    { "CSWeaponData.FullAuto.set",                          CSWeaponData_SetFullAuto },
    { "CSWeaponData.ShouldUnzoomAfterShot.get",             CSWeaponData_GetShouldUnzoomAfterShot },
    { "CSWeaponData.ShouldUnzoomAfterShot.set",             CSWeaponData_SetShouldUnzoomAfterShot },
    { "CSWeaponData.ShouldHideViewModelZoomed.get",         CSWeaponData_GetShouldHideViewModelZoomed },
    { "CSWeaponData.ShouldHideViewModelZoomed.set",         CSWeaponData_SetShouldHideViewModelZoomed },
    { "CSWeaponData.HasBurstMode.get",                      CSWeaponData_GetHasBurstMode },
    { "CSWeaponData.HasBurstMode.set",                      CSWeaponData_SetHasBurstMode },
    { "CSWeaponData.IsRevolver.get",                        CSWeaponData_GetIsRevolver },
    { "CSWeaponData.IsRevolver.set",                        CSWeaponData_SetIsRevolver },
    { "CSWeaponData.CannotShootUnderwater.get",             CSWeaponData_GetCannotShootUnderwater },
    { "CSWeaponData.CannotShootUnderwater.set",             CSWeaponData_SetCannotShootUnderwater },

    { "CSWeaponData.ItemDef.get",                           CSWeaponData_GetItemDef },
    { "CSWeaponData.ItemDef.set",                           CSWeaponData_SetItemDef },
    { "CSWeaponData.MaxClip1.get",                          CSWeaponData_GetMaxClip1 },
    { "CSWeaponData.MaxClip1.set",                          CSWeaponData_SetMaxClip1 },
    { "CSWeaponData.MaxClip2.get",                          CSWeaponData_GetMaxClip2 },
    { "CSWeaponData.MaxClip2.set",                          CSWeaponData_SetMaxClip2 },
    { "CSWeaponData.DefaultClip1.get",                      CSWeaponData_GetDefaultClip1 },
    { "CSWeaponData.DefaultClip1.set",                      CSWeaponData_SetDefaultClip1 },
    { "CSWeaponData.DefaultClip2.get",                      CSWeaponData_GetDefaultClip2 },
    { "CSWeaponData.DefaultClip2.set",                      CSWeaponData_SetDefaultClip2 },
    { "CSWeaponData.PrimaryReserveAmmoMax.get",             CSWeaponData_GetPrimaryReserveAmmoMax },
    { "CSWeaponData.PrimaryReserveAmmoMax.set",             CSWeaponData_SetPrimaryReserveAmmoMax },
    { "CSWeaponData.SecondaryReserveAmmoMax.get",           CSWeaponData_GetSecondaryReserveAmmoMax },
    { "CSWeaponData.SecondaryReserveAmmoMax.set",           CSWeaponData_SetSecondaryReserveAmmoMax },
    { "CSWeaponData.WeaponPrice.get",                       CSWeaponData_GetWeaponPrice },
    { "CSWeaponData.WeaponPrice.set",                       CSWeaponData_SetWeaponPrice },
    { "CSWeaponData.KillAward.get",                         CSWeaponData_GetKillAward },
    { "CSWeaponData.KillAward.set",                         CSWeaponData_SetKillAward },
    { "CSWeaponData.Damage.get",                            CSWeaponData_GetDamage },
    { "CSWeaponData.Damage.set",                            CSWeaponData_SetDamage },
    { "CSWeaponData.Bullets.get",                           CSWeaponData_GetBullets },
    { "CSWeaponData.Bullets.set",                           CSWeaponData_SetBullets },
    { "CSWeaponData.CrosshairMinDistance.get",              CSWeaponData_GetCrosshairMinDistance },
    { "CSWeaponData.CrosshairMinDistance.set",              CSWeaponData_SetCrosshairMinDistance },
    { "CSWeaponData.CrosshairDeltaDistance.get",            CSWeaponData_GetCrosshairDeltaDistance },
    { "CSWeaponData.CrosshairDeltaDistance.set",            CSWeaponData_SetCrosshairDeltaDistance },
    { "CSWeaponData.RecoilSeed.get",                        CSWeaponData_GetRecoilSeed },
    { "CSWeaponData.RecoilSeed.set",                        CSWeaponData_SetRecoilSeed },
    { "CSWeaponData.SpreadSeed.get",                        CSWeaponData_GetSpreadSeed },
    { "CSWeaponData.SpreadSeed.set",                        CSWeaponData_SetSpreadSeed },
    { "CSWeaponData.RecoveryTransitionStartBullet.get",     CSWeaponData_GetRecoveryTransitionStartBullet },
    { "CSWeaponData.RecoveryTransitionStartBullet.set",     CSWeaponData_SetRecoveryTransitionStartBullet },
    { "CSWeaponData.RecoveryTransitionEndBullet.get",       CSWeaponData_GetRecoveryTransitionEndBullet },
    { "CSWeaponData.RecoveryTransitionEndBullet.set",       CSWeaponData_SetRecoveryTransitionEndBullet },
    { "CSWeaponData.ZoomLevels.get",                        CSWeaponData_GetZoomLevels },
    { "CSWeaponData.ZoomLevels.set",                        CSWeaponData_SetZoomLevels },
    { "CSWeaponData.ZoomFov1.get",                          CSWeaponData_GetZoomFov1 },
    { "CSWeaponData.ZoomFov1.set",                          CSWeaponData_SetZoomFov1 },
    { "CSWeaponData.ZoomFov2.get",                          CSWeaponData_GetZoomFov2 },
    { "CSWeaponData.ZoomFov2.set",                          CSWeaponData_SetZoomFov2 },
    { "CSWeaponData.TracerFrequency.get",                   CSWeaponData_GetTracerFrequency },
    { "CSWeaponData.TracerFrequency.set",                   CSWeaponData_SetTracerFrequency },
    { "CSWeaponData.TracerFrequencyAlt.get",                CSWeaponData_GetTracerFrequencyAlt },
    { "CSWeaponData.TracerFrequencyAlt.set",                CSWeaponData_SetTracerFrequencyAlt },
    { "CSWeaponData.WeaponType.get",                        CSWeaponData_GetWeaponType },
    { "CSWeaponData.WeaponType.set",                        CSWeaponData_SetWeaponType },

    { "CSWeaponData.CycleTime.get",                         CSWeaponData_GetCycleTime },
    { "CSWeaponData.CycleTime.set",                         CSWeaponData_SetCycleTime },
    { "CSWeaponData.CycleTimeAlt.get",                      CSWeaponData_GetCycleTimeAlt },
    { "CSWeaponData.CycleTimeAlt.set",                      CSWeaponData_SetCycleTimeAlt },
    { "CSWeaponData.TimeToIdle.get",                        CSWeaponData_GetTimeToIdle },
    { "CSWeaponData.TimeToIdle.set",                        CSWeaponData_SetTimeToIdle },
    { "CSWeaponData.IdleInterval.get",                      CSWeaponData_GetIdleInterval },
    { "CSWeaponData.IdleInterval.set",                      CSWeaponData_SetIdleInterval },
    { "CSWeaponData.HeadshotMultiplier.get",                CSWeaponData_GetHeadshotMultiplier },
    { "CSWeaponData.HeadshotMultiplier.set",                CSWeaponData_SetHeadshotMultiplier },
    { "CSWeaponData.ArmorRatio.get",                        CSWeaponData_GetArmorRatio },
    { "CSWeaponData.ArmorRatio.set",                        CSWeaponData_SetArmorRatio },
    { "CSWeaponData.Penetration.get",                       CSWeaponData_GetPenetration },
    { "CSWeaponData.Penetration.set",                       CSWeaponData_SetPenetration },
    { "CSWeaponData.FlinchVelocityModifierLarge.get",       CSWeaponData_GetFlinchVelocityModifierLarge },
    { "CSWeaponData.FlinchVelocityModifierLarge.set",       CSWeaponData_SetFlinchVelocityModifierLarge },
    { "CSWeaponData.FlinchVelocityModifierSmall.get",       CSWeaponData_GetFlinchVelocityModifierSmall },
    { "CSWeaponData.FlinchVelocityModifierSmall.set",       CSWeaponData_SetFlinchVelocityModifierSmall },
    { "CSWeaponData.Range.get",                             CSWeaponData_GetRange },
    { "CSWeaponData.Range.set",                             CSWeaponData_SetRange },
    { "CSWeaponData.RangeModifier.get",                     CSWeaponData_GetRangeModifier },
    { "CSWeaponData.RangeModifier.set",                     CSWeaponData_SetRangeModifier },
    { "CSWeaponData.ThrowVelocity.get",                     CSWeaponData_GetThrowVelocity },
    { "CSWeaponData.ThrowVelocity.set",                     CSWeaponData_SetThrowVelocity },
    { "CSWeaponData.MaxPlayerSpeed.get",                    CSWeaponData_GetMaxPlayerSpeed },
    { "CSWeaponData.MaxPlayerSpeed.set",                    CSWeaponData_SetMaxPlayerSpeed },
    { "CSWeaponData.MaxPlayerSpeedAlt.get",                 CSWeaponData_GetMaxPlayerSpeedAlt },
    { "CSWeaponData.MaxPlayerSpeedAlt.set",                 CSWeaponData_SetMaxPlayerSpeedAlt },
    { "CSWeaponData.AttackMovespeedFactor.get",             CSWeaponData_GetAttackMovespeedFactor },
    { "CSWeaponData.AttackMovespeedFactor.set",             CSWeaponData_SetAttackMovespeedFactor },
    { "CSWeaponData.Spread.get",                            CSWeaponData_GetSpread },
    { "CSWeaponData.Spread.set",                            CSWeaponData_SetSpread },
    { "CSWeaponData.SpreadAlt.get",                         CSWeaponData_GetSpreadAlt },
    { "CSWeaponData.SpreadAlt.set",                         CSWeaponData_SetSpreadAlt },
    { "CSWeaponData.InaccuracyCrouch.get",                  CSWeaponData_GetInaccuracyCrouch },
    { "CSWeaponData.InaccuracyCrouch.set",                  CSWeaponData_SetInaccuracyCrouch },
    { "CSWeaponData.InaccuracyCrouchAlt.get",               CSWeaponData_GetInaccuracyCrouchAlt },
    { "CSWeaponData.InaccuracyCrouchAlt.set",               CSWeaponData_SetInaccuracyCrouchAlt },
    { "CSWeaponData.InaccuracyStand.get",                   CSWeaponData_GetInaccuracyStand },
    { "CSWeaponData.InaccuracyStand.set",                   CSWeaponData_SetInaccuracyStand },
    { "CSWeaponData.InaccuracyStandAlt.get",                CSWeaponData_GetInaccuracyStandAlt },
    { "CSWeaponData.InaccuracyStandAlt.set",                CSWeaponData_SetInaccuracyStandAlt },
    { "CSWeaponData.InaccuracyJumpInitial.get",             CSWeaponData_GetInaccuracyJumpInitial },
    { "CSWeaponData.InaccuracyJumpInitial.set",             CSWeaponData_SetInaccuracyJumpInitial },
    { "CSWeaponData.InaccuracyJumpApex.get",                CSWeaponData_GetInaccuracyJumpApex },
    { "CSWeaponData.InaccuracyJumpApex.set",                CSWeaponData_SetInaccuracyJumpApex },
    { "CSWeaponData.InaccuracyJump.get",                    CSWeaponData_GetInaccuracyJump },
    { "CSWeaponData.InaccuracyJump.set",                    CSWeaponData_SetInaccuracyJump },
    { "CSWeaponData.InaccuracyJumpAlt.get",                 CSWeaponData_GetInaccuracyJumpAlt },
    { "CSWeaponData.InaccuracyJumpAlt.set",                 CSWeaponData_SetInaccuracyJumpAlt },
    { "CSWeaponData.InaccuracyLand.get",                    CSWeaponData_GetInaccuracyLand },
    { "CSWeaponData.InaccuracyLand.set",                    CSWeaponData_SetInaccuracyLand },
    { "CSWeaponData.InaccuracyLandAlt.get",                 CSWeaponData_GetInaccuracyLandAlt },
    { "CSWeaponData.InaccuracyLandAlt.set",                 CSWeaponData_SetInaccuracyLandAlt },
    { "CSWeaponData.InaccuracyLadder.get",                  CSWeaponData_GetInaccuracyLadder },
    { "CSWeaponData.InaccuracyLadder.set",                  CSWeaponData_SetInaccuracyLadder },
    { "CSWeaponData.InaccuracyLadderAlt.get",               CSWeaponData_GetInaccuracyLadderAlt },
    { "CSWeaponData.InaccuracyLadderAlt.set",               CSWeaponData_SetInaccuracyLadderAlt },
    { "CSWeaponData.InaccuracyFire.get",                    CSWeaponData_GetInaccuracyFire },
    { "CSWeaponData.InaccuracyFire.set",                    CSWeaponData_SetInaccuracyFire },
    { "CSWeaponData.InaccuracyFireAlt.get",                 CSWeaponData_GetInaccuracyFireAlt },
    { "CSWeaponData.InaccuracyFireAlt.set",                 CSWeaponData_SetInaccuracyFireAlt },
    { "CSWeaponData.InaccuracyMove.get",                    CSWeaponData_GetInaccuracyMove },
    { "CSWeaponData.InaccuracyMove.set",                    CSWeaponData_SetInaccuracyMove },
    { "CSWeaponData.InaccuracyMoveAlt.get",                 CSWeaponData_GetInaccuracyMoveAlt },
    { "CSWeaponData.InaccuracyMoveAlt.set",                 CSWeaponData_SetInaccuracyMoveAlt },
    { "CSWeaponData.InaccuracyReload.get",                  CSWeaponData_GetInaccuracyReload },
    { "CSWeaponData.InaccuracyReload.set",                  CSWeaponData_SetInaccuracyReload },
    { "CSWeaponData.RecoilAngle.get",                       CSWeaponData_GetRecoilAngle },
    { "CSWeaponData.RecoilAngle.set",                       CSWeaponData_SetRecoilAngle },
    { "CSWeaponData.RecoilAngleAlt.get",                    CSWeaponData_GetRecoilAngleAlt },
    { "CSWeaponData.RecoilAngleAlt.set",                    CSWeaponData_SetRecoilAngleAlt },
    { "CSWeaponData.RecoilAngleVariance.get",               CSWeaponData_GetRecoilAngleVariance },
    { "CSWeaponData.RecoilAngleVariance.set",               CSWeaponData_SetRecoilAngleVariance },
    { "CSWeaponData.RecoilAngleVarianceAlt.get",            CSWeaponData_GetRecoilAngleVarianceAlt },
    { "CSWeaponData.RecoilAngleVarianceAlt.set",            CSWeaponData_SetRecoilAngleVarianceAlt },
    { "CSWeaponData.RecoilMagnitude.get",                   CSWeaponData_GetRecoilMagnitude },
    { "CSWeaponData.RecoilMagnitude.set",                   CSWeaponData_SetRecoilMagnitude },
    { "CSWeaponData.RecoilMagnitudeAlt.get",                CSWeaponData_GetRecoilMagnitudeAlt },
    { "CSWeaponData.RecoilMagnitudeAlt.set",                CSWeaponData_SetRecoilMagnitudeAlt },
    { "CSWeaponData.RecoilMagnitudeVariance.get",           CSWeaponData_GetRecoilMagnitudeVariance },
    { "CSWeaponData.RecoilMagnitudeVariance.set",           CSWeaponData_SetRecoilMagnitudeVariance },
    { "CSWeaponData.RecoilMagnitudeVarianceAlt.get",        CSWeaponData_GetRecoilMagnitudeVarianceAlt },
    { "CSWeaponData.RecoilMagnitudeVarianceAlt.set",        CSWeaponData_SetRecoilMagnitudeVarianceAlt },
    { "CSWeaponData.RecoveryTimeCrouch.get",                CSWeaponData_GetRecoveryTimeCrouch },
    { "CSWeaponData.RecoveryTimeCrouch.set",                CSWeaponData_SetRecoveryTimeCrouch },
    { "CSWeaponData.RecoveryTimeStand.get",                 CSWeaponData_GetRecoveryTimeStand },
    { "CSWeaponData.RecoveryTimeStand.set",                 CSWeaponData_SetRecoveryTimeStand },
    { "CSWeaponData.RecoveryTimeCrouchFinal.get",           CSWeaponData_GetRecoveryTimeCrouchFinal },
    { "CSWeaponData.RecoveryTimeCrouchFinal.set",           CSWeaponData_SetRecoveryTimeCrouchFinal },
    { "CSWeaponData.RecoveryTimeStandFinal.get",            CSWeaponData_GetRecoveryTimeStandFinal },
    { "CSWeaponData.RecoveryTimeStandFinal.set",            CSWeaponData_SetRecoveryTimeStandFinal },
    { "CSWeaponData.ZoomTime0.get",                         CSWeaponData_GetZoomTime0 },
    { "CSWeaponData.ZoomTime0.set",                         CSWeaponData_SetZoomTime0 },
    { "CSWeaponData.ZoomTime1.get",                         CSWeaponData_GetZoomTime1 },
    { "CSWeaponData.ZoomTime1.set",                         CSWeaponData_SetZoomTime1 },
    { "CSWeaponData.ZoomTime2.get",                         CSWeaponData_GetZoomTime2 },
    { "CSWeaponData.ZoomTime2.set",                         CSWeaponData_SetZoomTime2 },
    { "CSWeaponData.AddonScale.get",                        CSWeaponData_GetAddonScale },
    { "CSWeaponData.AddonScale.set",                        CSWeaponData_SetAddonScale },
    { "CSWeaponData.HeatPerShot.get",                       CSWeaponData_GetHeatPerShot },
    { "CSWeaponData.HeatPerShot.set",                       CSWeaponData_SetHeatPerShot },
    { "CSWeaponData.InaccuracyPitchShift.get",              CSWeaponData_GetInaccuracyPitchShift },
    { "CSWeaponData.InaccuracyPitchShift.set",              CSWeaponData_SetInaccuracyPitchShift },
    { "CSWeaponData.InaccuracySoundThreshold.get",          CSWeaponData_GetInaccuracySoundThreshold },
    { "CSWeaponData.InaccuracySoundThreshold.set",          CSWeaponData_SetInaccuracySoundThreshold },
    { "CSWeaponData.BotAudibleRange.get",                   CSWeaponData_GetBotAudibleRange },
    { "CSWeaponData.BotAudibleRange.set",                   CSWeaponData_SetBotAudibleRange },

    { "CSWeaponData.GetClassName",                          CSWeaponData_GetClassName },
    { "CSWeaponData.SetClassName",                          CSWeaponData_SetClassName },
    { "CSWeaponData.GetViewModel",                          CSWeaponData_GetViewModel },
    { "CSWeaponData.SetViewModel",                          CSWeaponData_SetViewModel },
    { "CSWeaponData.GetWorldModel",                         CSWeaponData_GetWorldModel },
    { "CSWeaponData.SetWorldModel",                         CSWeaponData_SetWorldModel },
    { "CSWeaponData.GetDroppedModel",                       CSWeaponData_GetDroppedModel },
    { "CSWeaponData.SetDroppedModel",                       CSWeaponData_SetDroppedModel },
    { "CSWeaponData.GetShotSound",                          CSWeaponData_GetShotSound },
    { "CSWeaponData.SetShotSound",                          CSWeaponData_SetShotSound },
    { "CSWeaponData.GetEmptySound",                         CSWeaponData_GetEmptySound },
    { "CSWeaponData.SetEmptySound",                         CSWeaponData_SetEmptySound },
    { "CSWeaponData.GetBulletType",                         CSWeaponData_GetBulletType },
    { "CSWeaponData.SetBulletType",                         CSWeaponData_SetBulletType },
    { "CSWeaponData.GetHudName",                            CSWeaponData_GetHudName },
    { "CSWeaponData.SetHudName",                            CSWeaponData_SetHudName },
    { "CSWeaponData.GetDefaultName",                        CSWeaponData_GetDefaultName },
    { "CSWeaponData.SetDefaultName",                        CSWeaponData_SetDefaultName },
    { "CSWeaponData.GetAnimationPrefix",                    CSWeaponData_GetAnimationPrefix },
    { "CSWeaponData.SetAnimationPrefix",                    CSWeaponData_SetAnimationPrefix },
    { "CSWeaponData.GetSilencerModel",                      CSWeaponData_GetSilencerModel },
    { "CSWeaponData.SetSilencerModel",                      CSWeaponData_SetSilencerModel },
    { "CSWeaponData.GetAddonlocation",                      CSWeaponData_GetAddonlocation },
    { "CSWeaponData.SetAddonlocation",                      CSWeaponData_SetAddonlocation },
    { "CSWeaponData.GetEjectBrassEffect",                   CSWeaponData_GetEjectBrassEffect },
    { "CSWeaponData.SetEjectBrassEffect",                   CSWeaponData_SetEjectBrassEffect },
    { "CSWeaponData.GetTracerEffect",                       CSWeaponData_GetTracerEffect },
    { "CSWeaponData.SetTracerEffect",                       CSWeaponData_SetTracerEffect },
    { "CSWeaponData.GetMuzzleFlashEffect1stPerson",         CSWeaponData_GetMuzzleFlashEffect1stPerson },
    { "CSWeaponData.SetMuzzleFlashEffect1stPerson",         CSWeaponData_SetMuzzleFlashEffect1stPerson },
    { "CSWeaponData.GetHeatEffect",                         CSWeaponData_GetHeatEffect },
    { "CSWeaponData.SetHeatEffect",                         CSWeaponData_SetHeatEffect },
    { "CSWeaponData.GetZoomInSound",                        CSWeaponData_GetZoomInSound },
    { "CSWeaponData.SetZoomInSound",                        CSWeaponData_SetZoomInSound },
    { "CSWeaponData.GetZoomOutSound",                       CSWeaponData_GetZoomOutSound },
    { "CSWeaponData.SetZoomOutSound",                       CSWeaponData_SetZoomOutSound },

    { nullptr,  nullptr }
};