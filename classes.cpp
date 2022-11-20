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
#include "classes.h"

CCSWeaponData* GetCCSWeaponData(CEconItemView* pView)
{
    static ICallWrapper *pWrapper = NULL;

    if (!pWrapper)
    {
        void *addr;
        if (!g_pGameConf->GetMemSig("GetCCSWeaponData", &addr) || !addr)
        {
            g_pSM->LogError(myself, "Failed to lookup GetCCSWeaponData signature.");
            return nullptr;
        }

        PassInfo retpass;
        retpass.flags = PASSFLAG_BYVAL;
        retpass.type = PassType_Basic;
        retpass.size = sizeof(CCSWeaponData *);
        pWrapper = g_pBinTools->CreateCall(addr, CallConv_ThisCall, &retpass, NULL, 0);
    }

    ArgBuffer<CEconItemView*> vstk(pView);

    CCSWeaponData *pWpnData = nullptr;
    pWrapper->Execute(vstk, &pWpnData);

    return pWpnData;
}