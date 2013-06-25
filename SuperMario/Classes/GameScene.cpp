#include "GameScene.h"
#include "Player.h"




CGameScene::CGameScene():
	m_pTileMap(NULL)
	,m_pBackground(NULL)
{

}
CGameScene::~CGameScene()
{

}

CCScene* CGameScene::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		CGameScene *layer = CGameScene::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}
bool CGameScene::load( const char * tmxFile )
{
	m_pTileMap = CCTMXTiledMap::create(tmxFile);
	//m_pBackground =  m_pTileMap->layerNamed("bakcground");

	addChild(m_pTileMap,-1);
	//= CCTMXTiledMap::initWithTMXFile(tmxFile); 
	return true;
}

bool CGameScene::init()
{
	load("data/tiledmap/mary1.tmx");
/*
	CCControlStateNormal      
		CCControlStateHighlighted 
		CCControlStateDisabled    
		CCControlStateSelected */
	/*
	CCControlEventTouchDown           = 1 << 0,    // A touch-down event in the control.
	CCControlEventTouchDragInside     = 1 << 1,    // An event where a finger is dragged inside the bounds of the control.
	CCControlEventTouchDragOutside    = 1 << 2,    // An event where a finger is dragged just outside the bounds of the control. 
	CCControlEventTouchDragEnter      = 1 << 3,    // An event where a finger is dragged into the bounds of the control.
	CCControlEventTouchDragExit       = 1 << 4,    // An event where a finger is dragged from within a control to outside its bounds.
	CCControlEventTouchUpInside       = 1 << 5,    // A touch-up event in the control where the finger is inside the bounds of the control. 
	CCControlEventTouchUpOutside      = 1 << 6,    // A touch-up event in the control where the finger is outside the bounds of the control.
	CCControlEventTouchCancel         = 1 << 7,    // A system event canceling the current touches for the control.
	CCControlEventValueChanged        = 1 << 8      // A touch dragging or otherwise manipulating a control, causing it to emit a series of different values.
	*/

	CCTexture2D *texture=CCTextureCache::sharedTextureCache()->addImage("data/control.png");
	/*
	CCControlButton *pControButton[4] = {NULL};

	pControButton[0] = CCControlButton::create();
	pControButton[0]->setBackgroundSpriteFrameForState(CCSpriteFrame::createWithTexture(texture,CCRectMake(0,0,120,120)),CCControlStateNormal);
	pControButton[0]->setBackgroundSpriteFrameForState(CCSpriteFrame::createWithTexture(texture,CCRectMake(0,0,120,120)),CCControlStateSelected);
	pControButton[0]->addTargetWithActionForControlEvents(this,cccontrol_selector(CGameScene::onLeftMenuCallBack),CCControlEventTouchDown);
	pControButton[0]->setPosition(CCPointMake(120.0f,60.0f));
	addChild(pControButton[0]);

	pControButton[1] = CCControlButton::create();
	pControButton[1]->setBackgroundSpriteFrameForState(CCSpriteFrame::createWithTexture(texture,CCRectMake(240,120,120,120)),CCControlStateNormal);
	pControButton[1]->setBackgroundSpriteFrameForState(CCSpriteFrame::createWithTexture(texture,CCRectMake(360,120,120,120)),CCControlStateSelected);
	pControButton[1]->addTargetWithActionForControlEvents(this,cccontrol_selector(CGameScene::onLeftMenuCallBack),CCControlEventTouchDown);
	pControButton[1]->setPosition(CCPointMake(120.0f,60.0f));
	addChild(pControButton[1]);

	pControButton[2] = CCControlButton::create();
	pControButton[2]->setBackgroundSpriteFrameForState(CCSpriteFrame::createWithTexture(texture,CCRectMake(240,0,120,120)),CCControlStateNormal);
	pControButton[2]->setBackgroundSpriteFrameForState(CCSpriteFrame::createWithTexture(texture,CCRectMake(360,0,120,120)),CCControlStateSelected);
	pControButton[2]->addTargetWithActionForControlEvents(this,cccontrol_selector(CGameScene::onLeftMenuCallBack),CCControlEventTouchDown);
	pControButton[2]->setPosition(CCPointMake(480,60));
	pControButton[2]->setRotation(270);
	addChild(pControButton[2]);

	pControButton[3] = CCControlButton::create();
	pControButton[3]->setBackgroundSpriteFrameForState(CCSpriteFrame::createWithTexture(texture,CCRectMake(0,120,120,120)),CCControlStateNormal);
	pControButton[3]->setBackgroundSpriteFrameForState(CCSpriteFrame::createWithTexture(texture,CCRectMake(120,120,120,120)),CCControlStateSelected);
	pControButton[3]->addTargetWithActionForControlEvents(this,cccontrol_selector(CGameScene::onLeftMenuCallBack),CCControlEventTouchDown);
	pControButton[3]->setPosition(CCPointMake(620,60));
	addChild(pControButton[3]);
	*/

	CCSpriteFrame *frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(0,0,120,120));
	CCSprite* pSpriteLeftNormal = CCSprite::createWithSpriteFrame(frame);
	frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(120,0,120,120));
	CCSprite* pSpriteLeftSelected = CCSprite::createWithSpriteFrame(frame);
	CCMenuItemSprite *pLeftMenuItem = CCMenuItemSprite::create(pSpriteLeftNormal,pSpriteLeftSelected,pSpriteLeftNormal,this,menu_selector(CGameScene::onLeftMenuCallBack));
	pLeftMenuItem->setPosition(CCPointMake(120,60));

	frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(240,120,120,120));
	CCSprite* pSpriteRightNormal = CCSprite::createWithSpriteFrame(frame);
	frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(360,120,120,120));
	CCSprite* pSpriteRightSelected = CCSprite::createWithSpriteFrame(frame);
	CCMenuItemSprite *pRightMenuItem = CCMenuItemSprite::create(pSpriteRightNormal,pSpriteRightSelected,pSpriteRightNormal,this,menu_selector(CGameScene::onRightMenuCallBack));
	pRightMenuItem->setPosition(CCPointMake(280,60));
	pRightMenuItem->setRotation(270);

	frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(240,0,120,120));
	CCSprite* pSpriteAttackNormal = CCSprite::createWithSpriteFrame(frame);
	frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(360,0,120,120));
	CCSprite* pSpriteAttackSelected = CCSprite::createWithSpriteFrame(frame);
	CCMenuItemSprite *pAttackMenuItem = CCMenuItemSprite::create(pSpriteAttackNormal,pSpriteAttackSelected,pSpriteAttackNormal,this,menu_selector(CGameScene::onAttackMenuCallBack));
	pAttackMenuItem->setPosition(CCPointMake(480,60));

	frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(0,120,120,120));
	CCSprite* pSpriteJumpNormal = CCSprite::createWithSpriteFrame(frame);
	frame =CCSpriteFrame::createWithTexture(texture,CCRectMake(120,120,120,120));
	CCSprite* pSpriteJumpSelected = CCSprite::createWithSpriteFrame(frame);
	CCMenuItemSprite *pJumpMenuItem = CCMenuItemSprite::create(pSpriteJumpNormal,pSpriteJumpSelected,pSpriteJumpNormal,this,menu_selector(CGameScene::onJumpMenuCallBack));
	pJumpMenuItem->setPosition(ccp(620,60));

	CCMenu* pMenu = CCMenu::create(pLeftMenuItem,pRightMenuItem,pAttackMenuItem,pJumpMenuItem,NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 128);

	m_pPlayer = CPlayer::create();
	m_pPlayer->setPosition(ccp(200,200));

	this->addChild(m_pPlayer, 128);

	return true;
}


void CGameScene::onLeftMenuCallBack(CCObject* pSender)
{
	CCLOG("Map X:%.1f Y:%.1f",m_pTileMap->getPositionX(),m_pTileMap->getPositionY());
	if(m_pTileMap->getPositionX()<10)
	m_pTileMap->setPositionX(m_pTileMap->getPositionX() + 10);
	m_pPlayer->Run();
}
void CGameScene::onRightMenuCallBack(CCObject* pSender)
{
	CCLOG("Map X:%.1f Y:%.1f",m_pTileMap->getPositionX(),m_pTileMap->getPositionY());
	//if(m_pTileMap->getPositionX() < 12800)
	if(m_pTileMap->getPositionX()>-12800)
	m_pTileMap->setPositionX(m_pTileMap->getPositionX() - 10); 

}
void CGameScene::onAttackMenuCallBack(CCObject* pSender)
{

}
void CGameScene::onJumpMenuCallBack(CCObject* pSender)
{

}

void CGameScene::onButtonEvent(CCObject*pSender,CCEvent event)
{


}


