#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <map>
#include "cocos2d.h"
#include "AnimalEntity.h"
using namespace  std;

class CPlayer:public CAnimalEntity
{
public:
	CPlayer();
	virtual ~CPlayer(){};
	virtual bool init();
	virtual emEntiryType GetEntityType(){ return emEntiryType_Player;};
public:
	virtual void	RunLeft();
	virtual void	RunRight();
	virtual void	Jump();
	virtual void	Stand();
	CREATE_FUNC(CPlayer);
private:

	BYTE	m_byDirect;
};
#endif