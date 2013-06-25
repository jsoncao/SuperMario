#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <map>
#include "cocos2d.h"
using namespace  std;

class CPlayer:public cocos2d::CCSprite
{
public:
	CPlayer();
	virtual ~CPlayer(){};
	virtual bool init();
public:
	virtual void	Run();
	virtual void	Jump(){};
	virtual void	Stand();
	CREATE_FUNC(CPlayer);
private:

	BYTE	m_byDirect;
};
#endif