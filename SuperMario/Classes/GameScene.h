#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include "Box2dContact.h"
#include "Box2dWorld.h"
#include "GLES-Render.h"

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
	bool	load(const char * tmxFile);

	void	onLeftMenuCallBack(CCObject* pSender);
	void	onRightMenuCallBack(CCObject* pSender);
	void	onAttackMenuCallBack(CCObject* pSender);
	void	onJumpMenuCallBack(CCObject* pSender);

	void	onButtonEvent(CCObject*pSender,CCControlEvent event);

	void	Update(float dt);
	void	draw();
private:
	void	CenterView();
	void	addBoxBodyForSprite(CCSprite* pObject);
	 GLESDebugDraw m_debugDraw;
private:
	CCTMXTiledMap*	m_pTileMap;
	CCTMXLayer*		m_pBackground;
	CPlayer*		m_pPlayer;

	CBox2dWorld *		m_pBox2dWorld;
	Box2dContactListener	*m_pBox2dContactListener;

};
#endif