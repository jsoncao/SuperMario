#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class CPlayer;
class CGameScene : public cocos2d::CCLayer
{
public:
	CGameScene();
	virtual ~CGameScene();
public:
	static cocos2d::CCScene* scene();
	CREATE_FUNC(CGameScene);
	virtual bool init(); 
	bool load(const char * tmxFile);

	void onLeftMenuCallBack(CCObject* pSender);
	void onRightMenuCallBack(CCObject* pSender);
	void onAttackMenuCallBack(CCObject* pSender);
	void onJumpMenuCallBack(CCObject* pSender);

	void onButtonEvent(CCObject*pSender,CCEvent event);
private:
	CCTMXTiledMap*	m_pTileMap;
	CCTMXLayer*		m_pBackground;
	CPlayer*		m_pPlayer;
};
#endif