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

#if defined _CSWeaponsAPI_included
  #endinput
#endif
#define _CSWeaponsAPI_included

enum CSWeaponType
{
	WEAPONTYPE_KNIFE = 0,	
	WEAPONTYPE_PISTOL,
	WEAPONTYPE_SUBMACHINEGUN,
	WEAPONTYPE_RIFLE,
	WEAPONTYPE_SHOTGUN,
	WEAPONTYPE_SNIPER_RIFLE,
	WEAPONTYPE_MACHINEGUN,
	WEAPONTYPE_C4,
	WEAPONTYPE_GRENADE,
	WEAPONTYPE_EQUIPMENT,
	WEAPONTYPE_STACKABLEITEM,
	WEAPONTYPE_UNKNOWN
};

// Retrieves an entity 'CEconItemView' memory address.
stock Address GetEntityItemView(int entity)
{
	static int m_ItemOffset = -1;
	
	if (m_ItemOffset == -1 && (m_ItemOffset = FindSendPropInfo("CBaseCombatWeapon", "m_Item")) <= 0)
	{
		SetFailState("Failed to find 'CBaseCombatWeapon::m_Item' offset");
	}
	
	return GetEntityAddress(entity) + view_as<Address>(m_ItemOffset);
} 

/**
 * Called after a 'CSWeaponData' object has been parsed and loaded into the game memory.
 * 
 * @param weapon_data              'CSWeaponData' object.
 */
forward void OnCSWeaponDataLoaded(CSWeaponData weapon_data);

methodmap CSWeaponData
{
    // Constructor.
    //
    // @return		'CSWeaponData' instance in the given CEconItemView, or null for an invalid CEconItemView.
    public native CSWeaponData(Address item_view);
    
    // Retrieves a 'CSWeaponData' by an entity index. (Wrapper)
    //
    // @return		'CSWeaponData' instance in the given entity index.
    // @error		Invalid entity index.
    public static CSWeaponData GetByEntity(int entity)
    {
    	return CSWeaponData(GetEntityItemView(entity));
    }
    
    // Retrieves a 'CSWeaponData' by an item classname.
    //
    // @return		'CSWeaponData' instance in the given classname, 
    // 				or 0 if no data matched with the given classname.
    public static native CSWeaponData GetByClassName(char[] classname);
    
    // Retrieves a 'CSWeaponData' by an index.
    // Use CSWeaponData.Count for the maximum available index.
    //
    // @return		'CSWeaponData' instance in the given index.
    // @error		Invalid index.
    public static native CSWeaponData GetByIndex(int index);
    
    // Retrieves the amount of avilable 'CSWeaponData'.
    // Can be used to iterate through all of them.
    //
    // @return		'CSWeaponData' count.
    public static native int Count();
    
    // Retrieves CCSWeaponData class total size.
    // Intended for developer compressions.
    //
    // @return		CCSWeaponData sizeof.
    public static native int Size();
    
    // Retrieves whether this weapon (CSWeaponData) has a silencer.
    //
    // @return             True if this weapon uses a silencer, false otherwise.
    // @error              Invalid CSWeaponData. (null)
    property bool HasSilencer
    {
        public native get();
        public native set(bool value);
    }
    
    // Retrieves whether this weapon (CSWeaponData) is fully automatic.
    //
    // @return             True if this weapon is fully automatic, false otherwise.
    // @error              Invalid CSWeaponData. (null)
    property bool FullAuto
    {
        public native get();
        public native set(bool value);
    }
    
    // Retrieves whether this weapon (CSWeaponData) should forcly unzoom after firing a shot.
    //
    // @return             True if it should, false otherwise.
    // @error              Invalid CSWeaponData. (null)
    property bool ShouldUnzoomAfterShot
    {
        public native get();
        public native set(bool value);
    }
    
    // Retrieves whether this weapon (CSWeaponData) should hide his view model while zoomed.
    //
    // @return             True if it should, false otherwise.
    // @error              Invalid CSWeaponData. (null)
    property bool ShouldHideViewModelZoomed
    {
        public native get();
        public native set(bool value);
    }
    
    // Retrieves whether this weapon (CSWeaponData) has a burst mode.
    //
    // @return             True if this weapon has a burst mode, false otherwise.
    // @error              Invalid CSWeaponData. (null)
    property bool HasBurstMode
    {
        public native get();
        public native set(bool value);
    }
    
    // Retrieves whether this weapon (CSWeaponData) is a revolver.
    //
    // @return             True if this weapon is a revolver, false otherwise.
    // @error              Invalid CSWeaponData. (null)
    property bool IsRevolver
    {
        public native get();
        public native set(bool value);
    }
    
    // Retrieves whether this weapon (CSWeaponData) is disabled while in water.
    //
    // @return             True if this weapon is disbaled while it water, false otherwise.
    // @error              Invalid CSWeaponData. (null)
    property bool CannotShootUnderwater
    {
        public native get();
        public native set(bool value);
    }
    
    // Retrieves the weapon maximum 1 clip. (m_iMaxClip1)
    //
    // @error              Invalid CSWeaponData. (null)
    property int MaxClip1
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon maximum 2 clip. (m_iMaxClip2)
    //
    // @error              Invalid CSWeaponData. (null)
    property int MaxClip2
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon default 1 clip. (m_iDefaultClip1)
    //
    // @error              Invalid CSWeaponData. (null)
    property int DefaultClip1
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon default 2 clip. (m_iDefaultClip2)
    //
    // @error              Invalid CSWeaponData. (null)
    property int DefaultClip2
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon maximum primary reserve ammo. (m_iPrimaryReserveAmmoMax)
    //
    // @error              Invalid CSWeaponData. (null)
    property int PrimaryReserveAmmoMax
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon maximum secondary reserve ammo. (m_iSecondaryReserveAmmoMax)
    //
    // @error              Invalid CSWeaponData. (null)
    property int SecondaryReserveAmmoMax
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon purchase price.
    //
    // @error              Invalid CSWeaponData. (null)
    property int WeaponPrice
    {
        public native get();
        public native set(int value);
    }
	
    // Retrieves the weapon kill award.
    //
    // @error              Invalid CSWeaponData. (null)
    property int KillAward
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon inflicted damage.
    //
    // @error              Invalid CSWeaponData. (null)
    property int Damage
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon bullets.
    //
    // @error              Invalid CSWeaponData. (null)
    property int Bullets
    {
        public native get();
        public native set(int value);
    }
      
    // Retrieves the weapon crosshair minimum distance.
    //
    // @error              Invalid CSWeaponData. (null)
    property int CrosshairMinDistance
    {
        public native get();
        public native set(int value);
    } 
    
    // Retrieves the weapon crosshair delta distance.
    //
    // @error              Invalid CSWeaponData. (null)
    property int CrosshairDeltaDistance
    {
        public native get();
        public native set(int value);
    }    
    
    // Retrieves the weapon recoil seed.
    //
    // @error              Invalid CSWeaponData. (null)
    property int RecoilSeed
    {
        public native get();
        public native set(int value);
    }
     
    // Retrieves the weapon spread seed.
    //
    // @error              Invalid CSWeaponData. (null)
    property int SpreadSeed
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon recovery transition start bullet.
    //
    // @error              Invalid CSWeaponData. (null)
    property int RecoveryTransitionStartBullet
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon recovery transition end bullet.
    //
    // @error              Invalid CSWeaponData. (null)
    property int RecoveryTransitionEndBullet
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the amount of zoom levels the weapon features.
    //
    // @error              Invalid CSWeaponData. (null)
    property int ZoomLevels
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon first zoom level FOV.
    //
    // @error              Invalid CSWeaponData. (null)
    property int ZoomFov1
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon second zoom level FOV.
    //
    // @error              Invalid CSWeaponData. (null)
    property int ZoomFov2
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon tracer frequency.
    //
    // @error              Invalid CSWeaponData. (null)
    property int TracerFrequency
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon alternate tracer frequency.
    //
    // @error              Invalid CSWeaponData. (null)
    property int TracerFrequencyAlt
    {
        public native get();
        public native set(int value);
    }
    
    // Retrieves the weapon CSWeaponType value.
    //
    // @error              Invalid CSWeaponData. (null)
    property CSWeaponType WeaponType
    {
        public native get();
        public native set(CSWeaponType value);
    }
    
    // Retrieves the weapon cycle time.
    //
    // @error              Invalid CSWeaponData. (null)
    property float CycleTime
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate cycle time.
    //
    // @error              Invalid CSWeaponData. (null)
    property float CycleTimeAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the amount of time to idle of the weapon.
    //
    // @error              Invalid CSWeaponData. (null)
    property float TimeToIdle
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon idle interval.
    //
    // @error              Invalid CSWeaponData. (null)
    property float IdleInterval
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon damage headshot multiplier.
    //
    // @error              Invalid CSWeaponData. (null)
    property float HeadshotMultiplier
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon armor ratio.
    //
    // @error              Invalid CSWeaponData. (null)
    property float ArmorRatio
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon penetration.
    //
    // @error              Invalid CSWeaponData. (null)
    property float Penetration
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon flinch velocity modifier large.
    //
    // @error              Invalid CSWeaponData. (null)
    property float FlinchVelocityModifierLarge
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon flinch velocity modifier small.
    //
    // @error              Invalid CSWeaponData. (null)
    property float FlinchVelocityModifierSmall
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon shooting range.
    //
    // @error              Invalid CSWeaponData. (null)
    property float Range
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon shooting range modifier.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RangeModifier
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon throw velocity.
    //
    // @error              Invalid CSWeaponData. (null)
    property float ThrowVelocity
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon maximum player movement speed.
    //
    // @error              Invalid CSWeaponData. (null)
    property float MaxPlayerSpeed
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate maximum player movement speed.
    //
    // @error              Invalid CSWeaponData. (null)
    property float MaxPlayerSpeedAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon attack movespeed factor.
    //
    // @error              Invalid CSWeaponData. (null)
    property float AttackMovespeedFactor
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon spread.
    //
    // @error              Invalid CSWeaponData. (null)
    property float Spread
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate spread.
    //
    // @error              Invalid CSWeaponData. (null)
    property float SpreadAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon crouch inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyCrouch
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate crouch inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyCrouchAlt
    {
        public native get();
        public native set(float value);
    }
        
    // Retrieves the weapon stand inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyStand
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate stand inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyStandAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon initial jump inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyJumpInitial
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon apex jump inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyJumpApex
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon jump inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyJump
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate jump inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyJumpAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon land inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyLand
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate land inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyLandAlt
    {
        public native get();
        public native set(float value);
    }
        
    // Retrieves the weapon ladder inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyLadder
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate ladder inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyLadderAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon fire inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyFire
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate fire inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyFireAlt
    {
        public native get();
        public native set(float value);
    }
        
    // Retrieves the weapon move inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyMove
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate move inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyMoveAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon reload inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyReload
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon recoil angle.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoilAngle
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate recoil angle.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoilAngleAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon recoil angle variance.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoilAngleVariance
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate recoil angle variance.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoilAngleVarianceAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon recoil magnitude.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoilMagnitude
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate recoil magnitude.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoilMagnitudeAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon recoil magnitude variance.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoilMagnitudeVariance
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon alternate recoil magnitude variance.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoilMagnitudeVarianceAlt
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon recovery time crouch.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoveryTimeCrouch
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon recovery time stand.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoveryTimeStand
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon recovery time crouch final.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoveryTimeCrouchFinal
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon recovery time stand final.
    //
    // @error              Invalid CSWeaponData. (null)
    property float RecoveryTimeStandFinal
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon exit zoom time.
    //
    // @error              Invalid CSWeaponData. (null)
    property float ZoomTime0
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon first stage zoom time.
    //
    // @error              Invalid CSWeaponData. (null)
    property float ZoomTime1
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon second stage zoom time.
    //
    // @error              Invalid CSWeaponData. (null)
    property float ZoomTime2
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon addon scale.
    //
    // @error              Invalid CSWeaponData. (null)
    property float AddonScale
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon heat per shot.
    //
    // @error              Invalid CSWeaponData. (null)
    property float HeatPerShot
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon pitch shift inaccuracy.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracyPitchShift
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon inaccuracy sound threshold.
    //
    // @error              Invalid CSWeaponData. (null)
    property float InaccuracySoundThreshold
    {
        public native get();
        public native set(float value);
    }
    
    // Retrieves the weapon bot audible range.
    //
    // @error              Invalid CSWeaponData. (null)
    property float BotAudibleRange
    {
        public native get();
        public native set(float value);
    }
    
	// Retrieves the weapon class name.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetClassName(char[] buffer, int maxlength);
    
    // Overrides the weapon class name.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetClassName(char[] source);

	// Retrieves the weapon view model file path.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetViewModel(char[] buffer, int maxlength);
    
    // Overrides the weapon view model.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetViewModel(char[] source);
    
    // Retrieves the weapon world model file path.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetWorldModel(char[] buffer, int maxlength);
    
    // Overrides the weapon world model.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetWorldModel(char[] source);
    
    // Retrieves the weapon dropped model file path. (Generally world model + '_dropped.mdl')
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetDroppedModel(char[] buffer, int maxlength);
    
    // Overrides the weapon dropped model.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetDroppedModel(char[] source);
    
    // Retrieves the weapon shot sound.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetShotSound(char[] buffer, int maxlength);
    
    // Overrides this weapon shot sound.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetShotSound(char[] source);

    // Retrieves the weapon empty sound.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetEmptySound(char[] buffer, int maxlength);
    
    // Overrides this weapon empty sound.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetEmptySound(char[] source);

    // Retrieves the weapon bullet type.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetBulletType(char[] buffer, int maxlength);
    
    // Overrides this weapon bullet type.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetBulletType(char[] source);

    // Retrieves the weapon hud name.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetHudName(char[] buffer, int maxlength);
    
    // Overrides this weapon hud name.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetHudName(char[] source);

    // Retrieves the weapon default name.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetDefaultName(char[] buffer, int maxlength);
    
    // Overrides this weapon default name.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetDefaultName(char[] source);

    // Retrieves the weapon animation prefix.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetAnimationPrefix(char[] buffer, int maxlength);
    
    // Overrides this weapon animation prefix.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetAnimationPrefix(char[] source);

    // Retrieves the weapon silencer model.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetSilencerModel(char[] buffer, int maxlength);
    
    // Overrides this weapon silencer model.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetSilencerModel(char[] source);

    // Retrieves the weapon addon location.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetAddonlocation(char[] buffer, int maxlength);
    
    // Overrides this weapon addon location.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetAddonlocation(char[] source);

    // Retrieves the weapon eject brass effect.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetEjectBrassEffect(char[] buffer, int maxlength);
    
    // Overrides this weapon eject brass effect.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetEjectBrassEffect(char[] source);

    // Retrieves the weapon tracer effect.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetTracerEffect(char[] buffer, int maxlength);
    
    // Overrides this weapon tracer effect.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetTracerEffect(char[] source);

    // Retrieves the weapon muzzle flash effect 1stPerson.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetMuzzleFlashEffect1stPerson(char[] buffer, int maxlength);
    
    // Overrides this weapon muzzle flash effect 1stPerson.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetMuzzleFlashEffect1stPerson(char[] source);

    // Retrieves the weapon heat effect.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetHeatEffect(char[] buffer, int maxlength);
    
    // Overrides this weapon heat effect.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetHeatEffect(char[] source);

    // Retrieves the weapon zoom in sound.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetZoomInSound(char[] buffer, int maxlength);
    
    // Overrides this weapon zoom in sound.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetZoomInSound(char[] source);

    // Retrieves the weapon zoom out sound.
	// 
	// @param buffer        Destination string buffer.
	// @param maxlength     Maximum length of output string buffer.
	// 
	// @return              Number of cells written.
	// @error              	Invalid CSWeaponData. (null)
    public native int GetZoomOutSound(char[] buffer, int maxlength);
    
    // Overrides this weapon zoom out sound.
	// 
	// @param source        Source file path.
	//
	// @return              Number of cells written.
	// @error               Invalid CSWeaponData. (null)
    public native int SetZoomOutSound(char[] source);
}

public Extension __ext_CSWeaponsAPI = 
{
    name = "CSWeaponsAPI",
    file = "CSWeaponsAPI.ext",
#if defined AUTOLOAD_EXTENSIONS
    autoload = 1,
#else
    autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
    required = 1,
#else
    required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public __ext_CSWeaponsAPI_SetNTVOptional()
{
    MarkNativeAsOptional("CSWeaponData.CSWeaponData");
    MarkNativeAsOptional("CSWeaponData.GetByClassName");
    MarkNativeAsOptional("CSWeaponData.GetByIndex");
    MarkNativeAsOptional("CSWeaponData.Count");
    MarkNativeAsOptional("CSWeaponData.Size")
    MarkNativeAsOptional("CSWeaponData.HasSilencer.get");
    MarkNativeAsOptional("CSWeaponData.HasSilencer.set");
    MarkNativeAsOptional("CSWeaponData.FullAuto.get");
    MarkNativeAsOptional("CSWeaponData.FullAuto.set");
    MarkNativeAsOptional("CSWeaponData.ShouldUnzoomAfterShot.get");
    MarkNativeAsOptional("CSWeaponData.ShouldUnzoomAfterShot.set");
    MarkNativeAsOptional("CSWeaponData.ShouldHideViewModelZoomed.get");
    MarkNativeAsOptional("CSWeaponData.ShouldHideViewModelZoomed.set");
    MarkNativeAsOptional("CSWeaponData.HasBurstMode.get");
    MarkNativeAsOptional("CSWeaponData.HasBurstMode.set");
    MarkNativeAsOptional("CSWeaponData.IsRevolver.get");
    MarkNativeAsOptional("CSWeaponData.IsRevolver.set");
    MarkNativeAsOptional("CSWeaponData.CannotShootUnderwater.get");
    MarkNativeAsOptional("CSWeaponData.CannotShootUnderwater.set");
    
    MarkNativeAsOptional("CSWeaponData.MaxClip1.get");
    MarkNativeAsOptional("CSWeaponData.MaxClip1.set");
    MarkNativeAsOptional("CSWeaponData.MaxClip2.get");
    MarkNativeAsOptional("CSWeaponData.MaxClip2.set");
    MarkNativeAsOptional("CSWeaponData.DefaultClip1.get");
    MarkNativeAsOptional("CSWeaponData.DefaultClip1.set");
    MarkNativeAsOptional("CSWeaponData.DefaultClip2.get");
    MarkNativeAsOptional("CSWeaponData.DefaultClip2.set");
    MarkNativeAsOptional("CSWeaponData.PrimaryReserveAmmoMax.get");
    MarkNativeAsOptional("CSWeaponData.PrimaryReserveAmmoMax.set");
    MarkNativeAsOptional("CSWeaponData.SecondaryReserveAmmoMax.get");
    MarkNativeAsOptional("CSWeaponData.SecondaryReserveAmmoMax.set");
    MarkNativeAsOptional("CSWeaponData.WeaponPrice.get");
    MarkNativeAsOptional("CSWeaponData.WeaponPrice.set");
    MarkNativeAsOptional("CSWeaponData.KillAward.get");
    MarkNativeAsOptional("CSWeaponData.KillAward.set");
    MarkNativeAsOptional("CSWeaponData.Damage.get");
    MarkNativeAsOptional("CSWeaponData.Damage.set");
    MarkNativeAsOptional("CSWeaponData.Bullets.get");
    MarkNativeAsOptional("CSWeaponData.Bullets.set");
    MarkNativeAsOptional("CSWeaponData.CrosshairMinDistance.get");
    MarkNativeAsOptional("CSWeaponData.CrosshairMinDistance.set");
    MarkNativeAsOptional("CSWeaponData.CrosshairDeltaDistance.get");
    MarkNativeAsOptional("CSWeaponData.CrosshairDeltaDistance.set");
    MarkNativeAsOptional("CSWeaponData.RecoilSeed.get");
    MarkNativeAsOptional("CSWeaponData.RecoilSeed.set");
    MarkNativeAsOptional("CSWeaponData.SpreadSeed.get");
    MarkNativeAsOptional("CSWeaponData.SpreadSeed.set");
    MarkNativeAsOptional("CSWeaponData.RecoveryTransitionStartBullet.get");
    MarkNativeAsOptional("CSWeaponData.RecoveryTransitionStartBullet.set");
    MarkNativeAsOptional("CSWeaponData.RecoveryTransitionEndBullet.get");
    MarkNativeAsOptional("CSWeaponData.RecoveryTransitionEndBullet.set");
    MarkNativeAsOptional("CSWeaponData.ZoomLevels.get");
    MarkNativeAsOptional("CSWeaponData.ZoomLevels.set");
    MarkNativeAsOptional("CSWeaponData.ZoomFov1.get");
    MarkNativeAsOptional("CSWeaponData.ZoomFov1.set");
    MarkNativeAsOptional("CSWeaponData.ZoomFov2.get");
    MarkNativeAsOptional("CSWeaponData.ZoomFov2.set");
    MarkNativeAsOptional("CSWeaponData.TracerFrequency.get");
    MarkNativeAsOptional("CSWeaponData.TracerFrequency.set");
    MarkNativeAsOptional("CSWeaponData.TracerFrequencyAlt.get");
    MarkNativeAsOptional("CSWeaponData.TracerFrequencyAlt.set");
    MarkNativeAsOptional("CSWeaponData.WeaponType.get");
    MarkNativeAsOptional("CSWeaponData.WeaponType.set");
    
    MarkNativeAsOptional("CSWeaponData.CycleTime.get");
    MarkNativeAsOptional("CSWeaponData.CycleTime.set");
    MarkNativeAsOptional("CSWeaponData.CycleTimeAlt.get");
    MarkNativeAsOptional("CSWeaponData.CycleTimeAlt.set");
    MarkNativeAsOptional("CSWeaponData.TimeToIdle.get");
    MarkNativeAsOptional("CSWeaponData.TimeToIdle.set");
    MarkNativeAsOptional("CSWeaponData.IdleInterval.get");
    MarkNativeAsOptional("CSWeaponData.IdleInterval.set");
    MarkNativeAsOptional("CSWeaponData.HeadshotMultiplier.get");
    MarkNativeAsOptional("CSWeaponData.HeadshotMultiplier.set");
    MarkNativeAsOptional("CSWeaponData.ArmorRatio.get");
    MarkNativeAsOptional("CSWeaponData.ArmorRatio.set");
    MarkNativeAsOptional("CSWeaponData.Penetration.get");
    MarkNativeAsOptional("CSWeaponData.Penetration.set");
    MarkNativeAsOptional("CSWeaponData.FlinchVelocityModifierLarge.get");
    MarkNativeAsOptional("CSWeaponData.FlinchVelocityModifierLarge.set");
    MarkNativeAsOptional("CSWeaponData.FlinchVelocityModifierSmall.get");
    MarkNativeAsOptional("CSWeaponData.FlinchVelocityModifierSmall.set");
    MarkNativeAsOptional("CSWeaponData.Range.get");
    MarkNativeAsOptional("CSWeaponData.Range.set");
    MarkNativeAsOptional("CSWeaponData.RangeModifier.get");
    MarkNativeAsOptional("CSWeaponData.RangeModifier.set");
    MarkNativeAsOptional("CSWeaponData.ThrowVelocity.get");
    MarkNativeAsOptional("CSWeaponData.ThrowVelocity.set");
    MarkNativeAsOptional("CSWeaponData.MaxPlayerSpeed.get");
    MarkNativeAsOptional("CSWeaponData.MaxPlayerSpeed.set");
    MarkNativeAsOptional("CSWeaponData.MaxPlayerSpeedAlt.get");
    MarkNativeAsOptional("CSWeaponData.MaxPlayerSpeedAlt.set");
    MarkNativeAsOptional("CSWeaponData.AttackMovespeedFactor.get");
    MarkNativeAsOptional("CSWeaponData.AttackMovespeedFactor.set");
    MarkNativeAsOptional("CSWeaponData.Spread.get");
    MarkNativeAsOptional("CSWeaponData.Spread.set");
    MarkNativeAsOptional("CSWeaponData.SpreadAlt.get");
    MarkNativeAsOptional("CSWeaponData.SpreadAlt.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyCrouch.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyCrouch.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyCrouchAlt.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyCrouchAlt.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyStand.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyStand.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyStandAlt.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyStandAlt.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyJumpInitial.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyJumpInitial.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyJumpApex.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyJumpApex.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyJump.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyJump.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyJumpAlt.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyJumpAlt.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyLand.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyLand.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyLandAlt.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyLandAlt.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyLadder.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyLadder.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyLadderAlt.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyLadderAlt.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyFire.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyFire.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyFireAlt.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyFireAlt.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyMove.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyMove.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyMoveAlt.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyMoveAlt.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyReload.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyReload.set");
    MarkNativeAsOptional("CSWeaponData.RecoilAngle.get");
    MarkNativeAsOptional("CSWeaponData.RecoilAngle.set");
    MarkNativeAsOptional("CSWeaponData.RecoilAngleAlt.get");
    MarkNativeAsOptional("CSWeaponData.RecoilAngleAlt.set");
    MarkNativeAsOptional("CSWeaponData.RecoilAngleVariance.get");
    MarkNativeAsOptional("CSWeaponData.RecoilAngleVariance.set");
    MarkNativeAsOptional("CSWeaponData.RecoilAngleVarianceAlt.get");
    MarkNativeAsOptional("CSWeaponData.RecoilAngleVarianceAlt.set");
    MarkNativeAsOptional("CSWeaponData.RecoilMagnitude.get");
    MarkNativeAsOptional("CSWeaponData.RecoilMagnitude.set");
    MarkNativeAsOptional("CSWeaponData.RecoilMagnitudeAlt.get");
    MarkNativeAsOptional("CSWeaponData.RecoilMagnitudeAlt.set");
    MarkNativeAsOptional("CSWeaponData.RecoilMagnitudeVariance.get");
    MarkNativeAsOptional("CSWeaponData.RecoilMagnitudeVariance.set");
    MarkNativeAsOptional("CSWeaponData.RecoilMagnitudeVarianceAlt.get");
    MarkNativeAsOptional("CSWeaponData.RecoilMagnitudeVarianceAlt.set");
    MarkNativeAsOptional("CSWeaponData.RecoveryTimeCrouch.get");
    MarkNativeAsOptional("CSWeaponData.RecoveryTimeCrouch.set");
    MarkNativeAsOptional("CSWeaponData.RecoveryTimeStand.get");
    MarkNativeAsOptional("CSWeaponData.RecoveryTimeStand.set");
    MarkNativeAsOptional("CSWeaponData.RecoveryTimeCrouchFinal.get");
    MarkNativeAsOptional("CSWeaponData.RecoveryTimeCrouchFinal.set");
    MarkNativeAsOptional("CSWeaponData.RecoveryTimeStandFinal.get");
    MarkNativeAsOptional("CSWeaponData.RecoveryTimeStandFinal.set");
    MarkNativeAsOptional("CSWeaponData.ZoomTime0.get");
    MarkNativeAsOptional("CSWeaponData.ZoomTime0.set");
    MarkNativeAsOptional("CSWeaponData.ZoomTime1.get");
    MarkNativeAsOptional("CSWeaponData.ZoomTime1.set");
    MarkNativeAsOptional("CSWeaponData.ZoomTime2.get");
    MarkNativeAsOptional("CSWeaponData.ZoomTime2.set");
    MarkNativeAsOptional("CSWeaponData.AddonScale.get");
    MarkNativeAsOptional("CSWeaponData.AddonScale.set");
    MarkNativeAsOptional("CSWeaponData.HeatPerShot.get");
    MarkNativeAsOptional("CSWeaponData.HeatPerShot.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracyPitchShift.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracyPitchShift.set");
    MarkNativeAsOptional("CSWeaponData.InaccuracySoundThreshold.get");
    MarkNativeAsOptional("CSWeaponData.InaccuracySoundThreshold.set");
    MarkNativeAsOptional("CSWeaponData.BotAudibleRange.get");
    MarkNativeAsOptional("CSWeaponData.BotAudibleRange.set");
    
    MarkNativeAsOptional("CSWeaponData.GetClassName");
    MarkNativeAsOptional("CSWeaponData.SetClassName");
    MarkNativeAsOptional("CSWeaponData.GetViewModel");
    MarkNativeAsOptional("CSWeaponData.SetViewModel");
    MarkNativeAsOptional("CSWeaponData.GetWorldModel");
    MarkNativeAsOptional("CSWeaponData.SetWorldModel");
    MarkNativeAsOptional("CSWeaponData.GetDroppedModel");
    MarkNativeAsOptional("CSWeaponData.SetDroppedModel");
    MarkNativeAsOptional("CSWeaponData.GetShotSound");
    MarkNativeAsOptional("CSWeaponData.SetShotSound");
    MarkNativeAsOptional("CSWeaponData.GetEmptySound");
    MarkNativeAsOptional("CSWeaponData.SetEmptySound");
    MarkNativeAsOptional("CSWeaponData.GetBulletType");
    MarkNativeAsOptional("CSWeaponData.SetBulletType");
    MarkNativeAsOptional("CSWeaponData.GetHudName");
    MarkNativeAsOptional("CSWeaponData.SetHudName");
    MarkNativeAsOptional("CSWeaponData.GetDefaultName");
    MarkNativeAsOptional("CSWeaponData.SetDefaultName");
    MarkNativeAsOptional("CSWeaponData.GetAnimationPrefix");
    MarkNativeAsOptional("CSWeaponData.SetAnimationPrefix");
    MarkNativeAsOptional("CSWeaponData.GetSilencerModel");
    MarkNativeAsOptional("CSWeaponData.SetSilencerModel");
    MarkNativeAsOptional("CSWeaponData.GetAddonlocation");
    MarkNativeAsOptional("CSWeaponData.SetAddonlocation");
    MarkNativeAsOptional("CSWeaponData.GetEjectBrassEffect");
    MarkNativeAsOptional("CSWeaponData.SetEjectBrassEffect");
    MarkNativeAsOptional("CSWeaponData.GetTracerEffect");
    MarkNativeAsOptional("CSWeaponData.SetTracerEffect");
    MarkNativeAsOptional("CSWeaponData.GetMuzzleFlashEffect1stPerson");
    MarkNativeAsOptional("CSWeaponData.SetMuzzleFlashEffect1stPerson");
    MarkNativeAsOptional("CSWeaponData.GetHeatEffect");
    MarkNativeAsOptional("CSWeaponData.SetHeatEffect");
    MarkNativeAsOptional("CSWeaponData.GetZoomInSound");
    MarkNativeAsOptional("CSWeaponData.SetZoomInSound");
    MarkNativeAsOptional("CSWeaponData.GetZoomOutSound");
    MarkNativeAsOptional("CSWeaponData.SetZoomOutSound");
}
#endif