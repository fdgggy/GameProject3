﻿#ifndef __WS_PLAYER_MANAGER_OBJECT_H__
#define __WS_PLAYER_MANAGER_OBJECT_H__
#include "AVLTree.h"
#include "Position.h"
#include "PlayerObject.h"

class CPlayerManager : public AVLTree<UINT64, CPlayerObject>
{
	CPlayerManager();
	~CPlayerManager();
public:
	static CPlayerManager* GetInstancePtr();

public:
	CPlayerObject*		CreatePlayer(UINT64 u64RoleID);

	CPlayerObject*		GetPlayer(UINT64 u64RoleID);

	CPlayerObject*		CreatePlayerByID(UINT64 u64RoleID);

	BOOL			    ReleasePlayer(UINT64 u64RoleID);

	BOOL				TryCleanPlayer();

	BOOL				BroadMessageToAll(UINT32 dwMsgID, const google::protobuf::Message& pdata);

public:

};

#endif //__WS_PLAYER_OBJECT_H__