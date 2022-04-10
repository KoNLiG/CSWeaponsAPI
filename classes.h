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

#ifndef _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_

//-----------------------------------------------------------------------------
// A dictionary mapping from symbol to structure
//-----------------------------------------------------------------------------

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

class CEconItemView;

class CCSWeaponData
{
public:
    // Booleans 
    bool HasSilencer() const                                 { return m_bHasSilencer; }
    bool FullAuto() const                                  	 { return m_bFullAuto; }
    bool ShouldUnzoomAfterShot() const                       { return m_bUnzoomAfterShot; }
    bool ShouldHideViewModelZoomed() const                   { return m_bHideViewModelZoomed; }
    bool HasBurstMode() const                                { return m_bHasBurstMode; }
    bool IsRevolver() const                                  { return m_bIsRevolver; }
    bool CannotShootUnderwater() const                       { return m_bCannotShootUnderwater; }
	
	// Setters
	void SetHasSilencer(bool value)              	    	 { m_bHasSilencer = value; }
	void SetFullAuto(bool value)              	    	 	 { m_bFullAuto = value; }
	void SetShouldUnzoomAfterShot(bool value)              	 { m_bUnzoomAfterShot = value; }
	void SetShouldHideViewModelZoomed(bool value)            { m_bHideViewModelZoomed = value; }
	void SetHasBurstMode(bool value)              	    	 { m_bHasBurstMode = value; }
	void SetIsRevolver(bool value)              	    	 { m_bIsRevolver = value; }
	void SetCannotShootUnderwater(bool value)              	 { m_bCannotShootUnderwater = value; }

	// Integers
	int MaxClip1() const 									 { return m_iMaxClip1; }
	int MaxClip2() const 									 { return m_iMaxClip2; }
	int DefaultClip1() const 								 { return m_iDefaultClip1; }
	int DefaultClip2() const 								 { return m_iDefaultClip2; }
	int PrimaryReserveAmmoMax() const 						 { return m_iPrimaryReserveAmmoMax; }
	int SecondaryReserveAmmoMax() const 					 { return m_iSecondaryReserveAmmoMax; }
	int WeaponPrice() const 								 { return m_iWeaponPrice; }
	int KillAward() const 									 { return m_iKillAward; }
	int Damage() const 										 { return m_iDamage; }
	int Bullets() const 									 { return m_iBullets; }
	int CrosshairMinDistance() const 						 { return m_iCrosshairMinDistance; }
	int CrosshairDeltaDistance() const 						 { return m_iCrosshairDeltaDistance; }
	int RecoilSeed() const 									 { return m_iRecoilSeed; }
	int SpreadSeed() const 					 				 { return m_iSpreadSeed; }
	int RecoveryTransitionStartBullet() const 				 { return m_iRecoveryTransitionStartBullet; }
	int RecoveryTransitionEndBullet() const 				 { return m_iRecoveryTransitionEndBullet; }
	int ZoomLevels() const 									 { return m_iZoomLevels; }
	int ZoomFov1() const 									 { return m_iZoomFov1; }
	int ZoomFov2() const 									 { return m_iZoomFov2; }
	int TracerFrequency() const 							 { return m_iTracerFrequency; }
	int TracerFrequencyAlt() const 							 { return m_iTracerFrequencyAlt; }
	
	CSWeaponType WeaponType() const 						 { return m_iWeaponType; }
	
	// Setters
	void SetMaxClip1(int value) 							 { m_iMaxClip1 = value; }
	void SetMaxClip2(int value) 							 { m_iMaxClip2 = value; }
	void SetDefaultClip1(int value) 						 { m_iDefaultClip1 = value; }
	void SetDefaultClip2(int value) 						 { m_iDefaultClip2 = value; }
	void SetPrimaryReserveAmmoMax(int value) 				 { m_iPrimaryReserveAmmoMax = value; }
	void SetSecondaryReserveAmmoMax(int value) 				 { m_iSecondaryReserveAmmoMax = value; }
	void SetWeaponPrice(int value) 							 { m_iWeaponPrice = value; }
	void SetKillAward(int value) 							 { m_iKillAward = value; }
	void SetDamage(int value) 							 	 { m_iDamage = value; }
	void SetBullets(int value) 							 	 { m_iBullets = value; }
	void SetCrosshairMinDistance(int value) 				 { m_iCrosshairMinDistance = value; }
	void SetCrosshairDeltaDistance(int value) 				 { m_iCrosshairDeltaDistance = value; }
	void SetRecoilSeed(int value) 							 { m_iRecoilSeed = value; }
	void SetSpreadSeed(int value) 							 { m_iSpreadSeed = value; }
	void SetRecoveryTransitionStartBullet(int value) 		 { m_iRecoveryTransitionStartBullet = value; }
	void SetRecoveryTransitionEndBullet(int value) 			 { m_iRecoveryTransitionEndBullet = value; }
	void SetZoomLevels(int value) 							 { m_iZoomLevels = value; }
	void SetZoomFov1(int value) 							 { m_iZoomFov1 = value; }
	void SetZoomFov2(int value) 							 { m_iZoomFov2 = value; }
	void SetTracerFrequency(int value) 						 { m_iTracerFrequency = value; }
	void SetTracerFrequencyAlt(int value) 					 { m_iTracerFrequencyAlt = value; }

	void SetWeaponType(CSWeaponType value)					  { m_iWeaponType = value; }

	// Floats
	float CycleTime() const                                 { return m_flCycleTime; }
    float CycleTimeAlt() const                              { return m_flCycleTimeAlt; }
    float TimeToIdle() const                                { return m_flTimeToIdle; }
    float IdleInterval() const                              { return m_flIdleInterval; }
    float HeadshotMultiplier() const                        { return m_flHeadshotMultiplier; }
    float ArmorRatio() const                                { return m_flArmorRatio; }
    float Penetration() const                               { return m_flPenetration; }
    float FlinchVelocityModifierLarge() const               { return m_flFlinchVelocityModifierLarge; }
    float FlinchVelocityModifierSmall() const               { return m_flFlinchVelocityModifierSmall; }
    float Range() const                                 	{ return m_flRange; }
    float RangeModifier() const                             { return m_flRangeModifier; }
    float ThrowVelocity() const                             { return m_flThrowVelocity; }
    float MaxPlayerSpeed() const                            { return m_flMaxPlayerSpeed; }
    float MaxPlayerSpeedAlt() const                         { return m_flMaxPlayerSpeedAlt; }
    float AttackMovespeedFactor() const                     { return m_flAttackMovespeedFactor; }
    float Spread() const                                 	{ return m_flSpread; }
    float SpreadAlt() const                                 { return m_flSpreadAlt; }
    float InaccuracyCrouch() const                          { return m_flInaccuracyCrouch; }
    float InaccuracyCrouchAlt() const                       { return m_flInaccuracyCrouchAlt; }
    float InaccuracyStand() const                           { return m_flInaccuracyStand; }
    float InaccuracyStandAlt() const                        { return m_flInaccuracyStandAlt; }
    float InaccuracyJumpInitial() const                     { return m_flInaccuracyJumpInitial; }
    float InaccuracyJumpApex() const                        { return m_flInaccuracyJumpApex; }
    float InaccuracyJump() const                            { return m_flInaccuracyJump; }
    float InaccuracyJumpAlt() const                         { return m_flInaccuracyJumpAlt; }
    float InaccuracyLand() const                            { return m_flInaccuracyLand; }
    float InaccuracyLandAlt() const                         { return m_flInaccuracyLandAlt; }
    float InaccuracyLadder() const                          { return m_flInaccuracyLadder; }
    float InaccuracyLadderAlt() const                       { return m_flInaccuracyLadderAlt; }
    float InaccuracyFire() const                            { return m_flInaccuracyFire; }
    float InaccuracyFireAlt() const                         { return m_flInaccuracyFireAlt; }
    float InaccuracyMove() const                            { return m_flInaccuracyMove; }
    float InaccuracyMoveAlt() const                         { return m_flInaccuracyMoveAlt; }
    float InaccuracyReload() const                          { return m_flInaccuracyReload; }
    float RecoilAngle() const                               { return m_flRecoilAngle; }
	float RecoilAngleAlt() const                            { return m_flRecoilAngleAlt; }
	float RecoilAngleVariance() const                       { return m_flRecoilAngleVariance; }
	float RecoilAngleVarianceAlt() const                    { return m_flRecoilAngleVarianceAlt; }
	float RecoilMagnitude() const                           { return m_flRecoilMagnitude; }
	float RecoilMagnitudeAlt() const                        { return m_flRecoilMagnitudeAlt; }
	float RecoilMagnitudeVariance() const                   { return m_flRecoilMagnitudeVariance; }
	float RecoilMagnitudeVarianceAlt() const                { return m_flRecoilMagnitudeVarianceAlt; }
	float RecoveryTimeCrouch() const                        { return m_flRecoveryTimeCrouch; }
	float RecoveryTimeStand() const                         { return m_flRecoveryTimeStand; }
	float RecoveryTimeCrouchFinal() const                   { return m_flRecoveryTimeCrouchFinal; }
	float RecoveryTimeStandFinal() const                    { return m_flRecoveryTimeStandFinal; }
	float ZoomTime0() const                                 { return m_flZoomTime0; }
	float ZoomTime1() const                                 { return m_flZoomTime1; }
	float ZoomTime2() const                                 { return m_flZoomTime2; }
	float AddonScale() const                                { return m_flAddonScale; }
	float HeatPerShot() const                               { return m_flHeatPerShot; }
	float InaccuracyPitchShift() const                      { return m_flInaccuracyPitchShift; }
	float InaccuracySoundThreshold() const                  { return m_flInaccuracySoundThreshold; }
	float BotAudibleRange() const                           { return m_flBotAudibleRange; }

	// Setters
	void SetCycleTime(float value)                          { m_flCycleTime = value; } 
    void SetCycleTimeAlt(float value)                       { m_flCycleTimeAlt = value; } 
    void SetTimeToIdle(float value)                         { m_flTimeToIdle = value; } 
    void SetIdleInterval(float value)                       { m_flIdleInterval = value; } 
    void SetHeadshotMultiplier(float value)                 { m_flHeadshotMultiplier = value; } 
    void SetArmorRatio(float value)                         { m_flArmorRatio = value; } 
    void SetPenetration(float value)                        { m_flPenetration = value; } 
    void SetFlinchVelocityModifierLarge(float value)        { m_flFlinchVelocityModifierLarge = value; } 
    void SetFlinchVelocityModifierSmall(float value)        { m_flFlinchVelocityModifierSmall = value; } 
    void SetRange(float value)                              { m_flRange = value; } 
    void SetRangeModifier(float value)                      { m_flRangeModifier = value; } 
    void SetThrowVelocity(float value)                      { m_flThrowVelocity = value; } 
    void SetMaxPlayerSpeed(float value)                     { m_flMaxPlayerSpeed = value; } 
    void SetMaxPlayerSpeedAlt(float value)                  { m_flMaxPlayerSpeedAlt = value; } 
    void SetAttackMovespeedFactor(float value)              { m_flAttackMovespeedFactor = value; } 
    void SetSpread(float value)                             { m_flSpread = value; } 
    void SetSpreadAlt(float value)                          { m_flSpreadAlt = value; } 
    void SetInaccuracyCrouch(float value)                   { m_flInaccuracyCrouch = value; } 
    void SetInaccuracyCrouchAlt(float value)                { m_flInaccuracyCrouchAlt = value; } 
    void SetInaccuracyStand(float value)                    { m_flInaccuracyStand = value; } 
    void SetInaccuracyStandAlt(float value)                 { m_flInaccuracyStandAlt = value; } 
    void SetInaccuracyJumpInitial(float value)              { m_flInaccuracyJumpInitial = value; } 
    void SetInaccuracyJumpApex(float value)                 { m_flInaccuracyJumpApex = value; } 
    void SetInaccuracyJump(float value)                     { m_flInaccuracyJump = value; } 
    void SetInaccuracyJumpAlt(float value)                  { m_flInaccuracyJumpAlt = value; } 
    void SetInaccuracyLand(float value)                     { m_flInaccuracyLand = value; } 
    void SetInaccuracyLandAlt(float value)                  { m_flInaccuracyLandAlt = value; } 
    void SetInaccuracyLadder(float value)                   { m_flInaccuracyLadder = value; } 
    void SetInaccuracyLadderAlt(float value)                { m_flInaccuracyLadderAlt = value; } 
    void SetInaccuracyFire(float value)                     { m_flInaccuracyFire = value; } 
    void SetInaccuracyFireAlt(float value)                  { m_flInaccuracyFireAlt = value; } 
    void SetInaccuracyMove(float value)                     { m_flInaccuracyMove = value; } 
    void SetInaccuracyMoveAlt(float value)                  { m_flInaccuracyMoveAlt = value; } 
    void SetInaccuracyReload(float value)                   { m_flInaccuracyReload = value; } 
    void SetRecoilAngle(float value)                        { m_flRecoilAngle = value; } 
	void SetRecoilAngleAlt(float value)                     { m_flRecoilAngleAlt = value; } 
	void SetRecoilAngleVariance(float value)                { m_flRecoilAngleVariance = value; } 
	void SetRecoilAngleVarianceAlt(float value)             { m_flRecoilAngleVarianceAlt = value; } 
	void SetRecoilMagnitude(float value)                    { m_flRecoilMagnitude = value; } 
	void SetRecoilMagnitudeAlt(float value)                 { m_flRecoilMagnitudeAlt = value; } 
	void SetRecoilMagnitudeVariance(float value)            { m_flRecoilMagnitudeVariance = value; } 
	void SetRecoilMagnitudeVarianceAlt(float value)         { m_flRecoilMagnitudeVarianceAlt = value; } 
	void SetRecoveryTimeCrouch(float value)                 { m_flRecoveryTimeCrouch = value; } 
	void SetRecoveryTimeStand(float value)                  { m_flRecoveryTimeStand = value; } 
	void SetRecoveryTimeCrouchFinal(float value)            { m_flRecoveryTimeCrouchFinal = value; } 
	void SetRecoveryTimeStandFinal(float value)             { m_flRecoveryTimeStandFinal = value; } 
	void SetZoomTime0(float value)                          { m_flZoomTime0 = value; } 
	void SetZoomTime1(float value)                          { m_flZoomTime1 = value; } 
	void SetZoomTime2(float value)                          { m_flZoomTime2 = value; } 
	void SetAddonScale(float value)                         { m_flAddonScale = value; } 
	void SetHeatPerShot(float value)                        { m_flHeatPerShot = value; } 
	void SetInaccuracyPitchShift(float value)               { m_flInaccuracyPitchShift = value; } 
	void SetInaccuracySoundThreshold(float value)           { m_flInaccuracySoundThreshold = value; } 
	void SetBotAudibleRange(float value)                    { m_flBotAudibleRange = value; } 

    // Strings
	const char* GetClassName() const						{ return m_szClassName; }
	const char* GetViewModel() const               			{ return m_szViewModel; }
    const char* GetWorldModel() const               		{ return m_szWorldModel; }
    const char* GetDroppedModel() const               		{ return m_szDroppedModel; }
    const char* GetShotSound() const               			{ return m_szShotSound; }
    const char* GetEmptySound() const               		{ return m_szEmptySound; }
    const char* GetBulletType() const               		{ return m_szBulletType; }
    const char* GetHudName() const               			{ return m_szHudName; }
    const char* GetDefaultName() const               		{ return m_szDefaultName; }
    const char* GetAnimationPrefix() const               	{ return m_szAnimationPrefix; }
    const char* GetSilencerModel() const               		{ return m_pSilencerModel; }
    const char* GetAddonlocation() const               		{ return m_szAddonlocation; }
    const char* GetEjectBrassEffect() const               	{ return m_szEjectBrassEffect; }
    const char* GetTracerEffect() const               		{ return m_szTracerEffect; }
    const char* GetMuzzleFlashEffect1stPerson() const       { return m_szMuzzleFlashEffect1stPerson; }
    const char* GetHeatEffect() const       				{ return m_szHeatEffect; }
    const char* GetZoomInSound() const       				{ return m_szZoomInSound; }
    const char* GetZoomOutSound() const       				{ return m_szZoomOutSound; }
	
	// Setters
	void SetClassName(char* source)                			{ m_szClassName = source; }
	void SetViewModel(char* source)                			{ m_szViewModel = source; }
	void SetWorldModel(char* source)               			{ m_szWorldModel = source; }
    void SetDroppedModel(char* source)             			{ m_szDroppedModel = source; }
	void SetShotSound(char* source)				   			{ m_szShotSound = source; }
   	void SetEmptySound(char* source)				   		{ m_szEmptySound = source; }
    void SetBulletType(char* source)				   		{ m_szBulletType = source; }
    void SetHudName(char* source)             				{ m_szHudName = source; }
    void SetDefaultName(char* source)				   		{ m_szDefaultName = source; }
    void SetAnimationPrefix(char* source)             		{ m_szAnimationPrefix = source; }
    void SetSilencerModel(char* source)             		{ m_pSilencerModel = source; }
    void SetAddonlocation(char* source)             		{ m_szAddonlocation = source; }
    void SetEjectBrassEffect(char* source)             		{ m_szEjectBrassEffect = source; }
    void SetTracerEffect(char* source)				   		{ m_szTracerEffect = source; }
    void SetMuzzleFlashEffect1stPerson(char* source)		{ m_szMuzzleFlashEffect1stPerson = source; }
    void SetHeatEffect(char* source)             			{ m_szHeatEffect = source; }
    void SetZoomInSound(char* source)             			{ m_szZoomInSound = source; }
    void SetZoomOutSound(char* source)             			{ m_szZoomOutSound = source; }

private:
	void* m_pVTable;                        // 0 [4]
	char* m_szClassName;                  	// 4 [4]
	char padding[12];                       // 8 [12]
	int m_iMaxClip1;                        // 20 [4]
	int m_iMaxClip2;                        // 24 [4]
	int m_iDefaultClip1;                    // 28 [4]
	int m_iDefaultClip2;                    // 32 [4]
	int m_iPrimaryReserveAmmoMax;			// 36 [4]
	int m_iSecondaryReserveAmmoMax;		    // 40 [4]
	char* m_szWorldModel;                   // 44 [4]
	char* m_szViewModel;                    // 48 [4]
	char* m_szDroppedModel;                 // 52 [4]
	char padding_1[4];                      // 56 [4]
	char* m_szShotSound;                    // 60 [4]
	char padding_2[56];                     // 64 [56]
	char* m_szEmptySound;                   // 120 [4]
	char padding_3[4];                      // 124 [4]
	char* m_szBulletType;                   // 128 [4]
	char padding_4[4];                      // 132 [4]
	char* m_szHudName;                      // 136 [4]
	char* m_szDefaultName;                  // 140 [4]
	char padding_5[56];                     // 144 [56]
	CSWeaponType m_iWeaponType;             // 200 [4]
	char padding_6[4];                      // 204 [4]
	int m_iWeaponPrice;                     // 208 [4]
	int m_iKillAward;                       // 212 [4]
	char* m_szAnimationPrefix;              // 216 [4]
	float m_flCycleTime;                    // 220 [4]
	float m_flCycleTimeAlt;                 // 224 [4]
	float m_flTimeToIdle;                   // 228 [4]
	float m_flIdleInterval;                 // 232 [4]
	bool m_bFullAuto;                       // 236 [1]
	char padding_7[3];                      // 237 [3]
	int m_iDamage;                          // 240 [4]
	float m_flHeadshotMultiplier;			// 244 [4]
	float m_flArmorRatio;                   // 248 [4]
	int m_iBullets;                         // 252 [4]
	float m_flPenetration;                  // 256 [4]
	float m_flFlinchVelocityModifierLarge;  // 260 [4]
	float m_flFlinchVelocityModifierSmall;  // 264 [4]
	float m_flRange;                        // 268 [4]
	float m_flRangeModifier;                // 272 [4]
	float m_flThrowVelocity;                // 276 [4]
	char padding_8[12];                     // 280 [12]
	bool m_bHasSilencer;                    // 292 [1]
	char padding_9[3];                      // 293 [3]
	char* m_pSilencerModel;                 // 296 [4]
	int m_iCrosshairMinDistance;            // 300 [4]
	int m_iCrosshairDeltaDistance;          // 304 [4]
	float m_flMaxPlayerSpeed;               // 308 [4]
	float m_flMaxPlayerSpeedAlt;            // 312 [4]
	float m_flAttackMovespeedFactor;        // 316 [4]
	float m_flSpread;                       // 320 [4]
	float m_flSpreadAlt;                    // 324 [4]
	float m_flInaccuracyCrouch;             // 328 [4]
	float m_flInaccuracyCrouchAlt;          // 332 [4]
	float m_flInaccuracyStand;              // 336 [4]
	float m_flInaccuracyStandAlt;           // 340 [4]
	float m_flInaccuracyJumpInitial;        // 344 [4]
	float m_flInaccuracyJumpApex;			// 348 [4]
	float m_flInaccuracyJump;               // 352 [4]
	float m_flInaccuracyJumpAlt;            // 356 [4]
	float m_flInaccuracyLand;               // 360 [4]
	float m_flInaccuracyLandAlt;            // 364 [4]
	float m_flInaccuracyLadder;             // 368 [4]
	float m_flInaccuracyLadderAlt;          // 372 [4]
	float m_flInaccuracyFire;               // 376 [4]
	float m_flInaccuracyFireAlt;            // 380 [4]
	float m_flInaccuracyMove;               // 384 [4]
	float m_flInaccuracyMoveAlt;            // 388 [4]
	float m_flInaccuracyReload;             // 392 [4]
	int m_iRecoilSeed;                      // 396 [4]
	float m_flRecoilAngle;                  // 400 [4]
	float m_flRecoilAngleAlt;               // 404 [4]
	float m_flRecoilAngleVariance;          // 408 [4]
	float m_flRecoilAngleVarianceAlt;       // 412 [4]
	float m_flRecoilMagnitude;              // 416 [4]
	float m_flRecoilMagnitudeAlt;           // 420 [4]
	float m_flRecoilMagnitudeVariance;      // 424 [4]
	float m_flRecoilMagnitudeVarianceAlt;   // 428 [4]
	int m_iSpreadSeed;					    // 432 [4]
	float m_flRecoveryTimeCrouch;           // 436 [4]
	float m_flRecoveryTimeStand;            // 440 [4]
	float m_flRecoveryTimeCrouchFinal;      // 444 [4]
	float m_flRecoveryTimeStandFinal;       // 448 [4]
	int m_iRecoveryTransitionStartBullet;   // 452 [4]
	int m_iRecoveryTransitionEndBullet;	    // 456 [4]
	bool m_bUnzoomAfterShot;				// 460 [1]
	bool m_bHideViewModelZoomed;			// 461 [1]
	char padding_10[2];					    // 462 [2]
	int m_iZoomLevels;					    // 464 [4]
	int m_iZoomFov1;						// 468 [4]
	int m_iZoomFov2;						// 472 [4]
	float m_flZoomTime0;					// 476 [4]
	float m_flZoomTime1;					// 480 [4]
	float m_flZoomTime2;					// 484 [4]
	char* m_szAddonlocation;                // 488 [4]
	char padding_11[4];					    // 492 [4]
	float m_flAddonScale;					// 496 [4]
	char* m_szEjectBrassEffect;             // 500 [4]
	char* m_szTracerEffect;                 // 504 [4]
	int m_iTracerFrequency;                 // 508 [4]
	int m_iTracerFrequencyAlt;              // 512 [4]
	char* m_szMuzzleFlashEffect1stPerson;   // 516 [4]
	char padding_12[4];                     // 520 [4]
	char* m_szMuzzleFlashEffect3stPerson;   // 524 [4]
	char padding_13[4];                     // 528 [4]
	char* m_szHeatEffect;            		// 532 [4]
	float m_flHeatPerShot;                  // 536 [4]
	char* m_szZoomInSound;                  // 540 [4]
	char* m_szZoomOutSound;                 // 544 [4]
	float m_flInaccuracyPitchShift;         // 548 [4]
	float m_flInaccuracySoundThreshold;     // 552 [4]
	float m_flBotAudibleRange;              // 556 [4]
	char padding_14[12];                    // 560 [12]
	bool m_bHasBurstMode;                   // 572 [1]
	bool m_bIsRevolver;                     // 573 [1]
	bool m_bCannotShootUnderwater;		    // 574 [1]
	// padding 575 [1]?
	
    // Size = 576
};

CCSWeaponData* GetCCSWeaponData(CEconItemView* pView);

extern CUtlVector<CCSWeaponData *> g_CCSWeaponDataList;

#endif // _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_