#include <sourcemod>
#include <sdktools>
#include <CSWeaponsAPI>

#pragma newdecls required
#pragma semicolon 1

public Plugin myinfo =
{
    name = "[CSWeaponsAPI] Tester",
    author = "KoNLiG",
    description = "",
    version = "1.0.0",
    url = "https://github.com/KoNLiG/CSWeaponsAPI"
};

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max)
{
    if (GetEngineVersion() != Engine_CSGO)
    {
        strcopy(error, err_max, "This plugin was made for use with CS:GO only.");
        return APLRes_Failure;
    }

    return APLRes_Success;
}

public void OnPluginStart()
{
    RegAdminCmd("sm_csweapon_dump", Command_CSWeaponDump, ADMFLAG_ROOT);

    // "Offline" dump.
    CSWeaponData weapon_data;
    char classname[64];

    for (int i; i < CSWeaponData.Count(); i++)
    {
        if (!(weapon_data = CSWeaponData.GetByIndex(i)))
        {
            PrintToServer("CSWeaponData.GetByIndex FAILED for index %d", i);
            continue;
        }

        weapon_data.GetClassName(classname, sizeof(classname));

        if (!CSWeaponData.GetByClassName(classname))
        {
            PrintToServer("CSWeaponData.GetByIndex FAILED for classname (%s)", classname);
            continue;
        }

        PrintToServer("[%d] classname: (%s)", i, classname);
    }
}

Action Command_CSWeaponDump(int client, int argc)
{
    if (!client)
    {
        ReplyToCommand(client, "[SM] This command is for in-game use only.");
        return Plugin_Handled;
    }

    int entity = GetClientAimTarget(client, false);
    if (entity <= 0)
    {
        ReplyToCommand(client, "[SM] No entity detected.");
        return Plugin_Handled;
    }

    CSWeaponData weapon_data = CSWeaponData.GetByEntity(entity);
    if (!weapon_data)
    {
        ReplyToCommand(client, "No 'CSWeaponData' found for entity %d", entity);
        return Plugin_Handled;
    }

    DumpWeaponData(client, weapon_data);

    return Plugin_Handled;
}

// Will be expanded later.
void DumpWeaponData(int client, CSWeaponData weapon_data)
{
    PrintToConsole(client, "HasSilencer: %d | FullAuto: %d | ShouldUnzoomAfterShot: %d | ShouldHideViewModelZoomed: %d | HasBurstMode: %d | IsRevolver: %d | CannotShootUnderwater: %d", weapon_data.HasSilencer, weapon_data.FullAuto, weapon_data.ShouldUnzoomAfterShot, weapon_data.ShouldHideViewModelZoomed, weapon_data.HasBurstMode, weapon_data.IsRevolver, weapon_data.CannotShootUnderwater);
}