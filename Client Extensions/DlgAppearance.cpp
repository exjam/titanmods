#include "main.h"
#include "Appearance.h"

CTAppearance* gAppearDialog;

CTAppearance::CTAppearance(){
	SetDialogType(DLG_TYPE_APPEARANCE);
}

CTAppearance::~CTAppearance(){
}

void CTAppearance::Draw(){
	if(!IsVision())	return;

	CTDialog::Draw();
}

unsigned int CTAppearance::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision())	return 0;

	unsigned int controlID = CTDialog::Process(uiMsg, wParam, lParam);

	if(uiMsg == WM_LBUTTONUP && controlID == RETURN)
		Hide();

	return controlID;
}

void CTAppearance::Show(){
	POINT pt;
	pt.x = (getScreenWidth() / 2) - (GetWidth() / 2);
	pt.y = (getScreenHeight() / 2) - (GetHeight() / 2);
	MoveWindow(pt);

	CTDialog::Show();
}


/*
HNODE SC_AddCreateAVT ( ZSTRING pszName, int iRace, int iFace, int iHair, 
					   int iHelmet, int iArmor, int iGauntlet, int iBoots, 
					   int iFaceItem, int iKnapsack, int iRWeapon, int iLWeapon ) {
	return CallStaticFunction<HNODE, ZSTRING, int, int, int, int, int, int, int, int, int, int, int>(0x00423A70, pszName, iRace, iFace, iHair, iHelmet, iArmor, iGauntlet, iBoots, iFaceItem, iKnapsack, iRWeapon, iLWeapon);
}

void SC_RemoveCreateAVT ( ZSTRING pszName )
{
	return CallStaticFunction<void, ZSTRING>(0x004253D0, pszName);
}
*/

static _declspec(naked) int CallLuaFunc(int pLUA, const char *szFuncName, ...){
	static int jCallLuaF = 0x004EC440;
	_asm {
		JMP jCallLuaF
	}
}

static _declspec(naked) int GetScriptPtr(){
	_asm {
		MOV EAX,DWORD PTR DS:[0x6998FC]
		MOV EAX,DWORD PTR DS:[EAX]
		TEST EAX, EAX
		JE jOVER
		MOV EAX,DWORD PTR DS:[EAX+0x8]
		RETN
jOVER:
		MOV EAX, 0
		RETN
	}
}

void StartAppearance(){
	CGameOBJ* self = CObjMGR::GetSelf();
	if(!self) return;

	NewData* selfData = self->m_Special;
	if(!selfData || !GetScriptPtr()) return;

	HNODE hAVT = CallLuaFunc(GetScriptPtr(), "SE_CreateAVT", 
									ZZ_PARAM_INT, 57, 
									ZZ_PARAM_INT, 40,	
									ZZ_PARAM_INT, selfData->mArmor.m_nItemNo, 
									ZZ_PARAM_INT, selfData->mGauntlet.m_nItemNo, 
									ZZ_PARAM_INT, selfData->mBoots.m_nItemNo, 
									ZZ_PARAM_END);

	//HNODE hCreateAvatarMotion = ::loadMotion( "CreateMotion","3DData\\Motion\\Avatar\\AVATAR_APPEARSIT_M1.zmo", 1, 4, 3, 1, 0 );
	//::attachMotion( hAVT, hCreateAvatarMotion);
	//::setScale( hAVT, 1.5f, 1.5f, 1.5f );
	//::setPosition( hAVT, 556020.0f, 524600.0f, 10.0f ); 
	//::setModelDirection( hAVT, 270.0f, false );

	//HNODE m_hNODE  = ::findNode( "avatar_camera");
	//::cameraAttachTarget   (m_hNODE, hAVT);
	//::setCameraTargetHeight( m_hNODE, 170 );
	//::setCameraFollowDistance ( m_hNODE, 100 );
	//::setCameraFollowMode     ( m_hNODE, 1 );
	//::setCameraFollowDistanceRange( m_hNODE, 300.0f, 1800.0f * 2.0f );
}

/*
0x004239D0 "SC_AddCoordinatesIndicator"
0x00423A70 "SC_AddCreateAVT"
0x00423BD0 "SC_AddNpcIndicator"
0x00423C70 "SC_AddSelectItem4CreateAvatar"
0x00423D00 "SC_AttachMotion"
0x00423D80 "SC_ChangeState"
0x00423E10 "SC_ClearSelectItem4CreateAvatar"
0x00423E70 "SC_ControlAnimation"
0x00423F00 "SC_CreateAVT"
0x00424060 "SC_CreateEventButton"
0x004240E0 "SC_DestroyAVT"
0x00424150 "SC_DoScript"
0x004241C0 "SC_EffectOnChar"
0x00424240 "SC_EffectOnObject"
0x004242D0 "SC_FindNode"
0x00424340 "SC_GF_getVariable"
0x004243D0 "SC_GF_setRevivePosition"
0x004243F0 "SC_GetAvatarEXP"
0x00424430 "SC_GetAvatarLEVEL"
0x00424470 "SC_GetBGZoneNO"
0x004244B0 "SC_GetEffectUseFile"
0x00424540 "SC_GetEffectUseIndex"
0x004245D0 "SC_GetEventObject"
0x00424670 "SC_GetEventObjectIndex"
0x004246E0 "SC_GetMotion"
0x00424760 "SC_GetSkeleton"
0x004247F0 "SC_GetTotalFrame"
0x00424880 "SC_InitGame"
0x004248A0 "SC_LoadCamera"
0x00424950 "SC_LoadModel"
0x00424A10 "SC_LoadMotion"
0x00424B10 "SC_LoadSkeleton"
0x00424BB0 "SC_LogString"
0x00424C20 "SC_OpenDialog"
0x00424C90 "SC_OpenMsgbox"
0x00424D00 "SC_QF_checkQuestCondition"
0x00424D70 "SC_QF_doQuestTrigger"
0x00424DF0 "SC_QF_findQuest"
0x00424E70 "SC_QF_getEpisodeVAR"
0x00424F00 "SC_QF_getJobVAR"
0x00424F80 "SC_QF_getNpcQuestZeroVal"
0x00424FF0 "SC_QF_getPlanetVAR"
0x00425080 "SC_QF_getQuestItemQuantity"
0x00425100 "SC_QF_getQuestSwitch"
0x004251B0 "SC_QF_getQuestVar"
0x00425250 "SC_QF_getUnionVAR"
0x004252E0 "SC_QF_getUserSwitch"
0x00425370 "SC_RemoveCoordinatesIndicator"
0x004253D0 "SC_RemoveCreateAVT"
0x00425450 "SC_RemoveNpcIndicator"
0x004254D0 "SC_RunEvent"
0x00425560 "SC_RunEventFieldWarp"
0x00425610 "SC_RunEventObjectEvent"
0x004256A0 "SC_ScreenFadeInStart"
0x004257A0 "SC_SelectItem4CreateAvatar"
0x00425810 "SC_SendMsgToWeb"
0x004258B0 "SC_SetAvatarFace"
0x00425940 "SC_SetAvatarHair"
0x004259D0 "SC_SetAvatarMotionByIndex"
0x00425A40 "SC_SetAvatarMotionByName"
0x00425AB0 "SC_SetButtonBlink"
0x00425B40 "SC_SetCameraDefault"
0x00425BD0 "SC_SetModelDirection"
0x00425C70 "SC_SetModelPosition"
0x00425D30 "SC_SetMotionFrame"
0x00425DC0 "SC_SetPosition"
0x00425E80 "SC_SetRepeatCount"
0x00425F20 "SC_SetScale"
0x00425FD0 "SC_SetVisible"
0x00426060 "SC_ShowNotifyMessage"
0x004260E0 "SC_ShowTutorialImage"
0x004261E0 "SC_UnloadNode"
*/