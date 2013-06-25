#pragma once
#include "BaseEntity.h"
class CAnimalEntity:
	public CBaseEntity
{
public:
	CAnimalEntity(void);
	virtual ~CAnimalEntity(void);
	virtual emEntiryType GetEntityType(){ return emEntiryType_Animal;};
private:
};

