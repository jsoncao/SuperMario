#pragma once
#include "BaseEntity.h"
class CBarrierEntity:public CBaseEntity
{
public:
	CBarrierEntity(void);
	virtual ~CBarrierEntity(void);
	virtual emEntiryType GetEntityType(){ return emEntiryType_Barrier;};
};