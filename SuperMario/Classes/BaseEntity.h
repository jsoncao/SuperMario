#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
using namespace cocos2d;
enum emEntiryType
{
	emEntiryType_Normal = 0,
	emEntiryType_Barrier = 1,
	emEntiryType_Animal = 0x10,
	emEntiryType_Player = 0x11,
	emEntiryType_Monster= 0x12,
};
class CBaseEntity:public CCSprite
{
public:
	CBaseEntity(void);
	virtual ~CBaseEntity(void);
	virtual emEntiryType GetEntityType() = 0;
	void	SetB2Body(b2Body* pBody){m_pB2Body = pBody;};
	b2Body*	GetB2Body(){return m_pB2Body;};
	private:
	b2Body*		m_pB2Body;
};

