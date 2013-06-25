#include "GameScene.h"
#include "Player.h"
#include "BaseEntity.h"
#include "BarrierEntity.h"
#include "CImageButton.h"



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
	m_pBackground =  m_pTileMap->layerNamed("barrier");

	// 根据群组名获得对象群组 ： 
	CCTMXObjectGroup* group = m_pTileMap->objectGroupNamed("barrier"); 
	// 获得群组里面的所有对象 
	//CCArray* objects = group->getObjects();
	int aa = m_pBackground->getChildrenCount();
	CCSize size = m_pBackground->getLayerSize();
	
	for (int y = 0;y < size.height;y++)
	{
		for (int x = 0;x<size.width;x++)
		{
			if( 0 == m_pBackground->tileGIDAt(ccp(x,y)))
				continue;
			CBarrierEntity *pBarrier = new CBarrierEntity();
			pBarrier->setPosition(ccp(x *32  + 16 ,(size.height - y ) * 32 - 16));
			pBarrier->setContentSize(CCSizeMake(32,32));
			m_pBox2dWorld->AddEntntyForSprite(pBarrier);
		}
	}
	addChild(m_pTileMap,-1);
	//= CCTMXTiledMap::initWithTMXFile(tmxFile); 
	return true;
}

bool CGameScene::init()
{
	b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
	m_pBox2dWorld = new CBox2dWorld(gravity);
	m_pBox2dWorld->SetAllowSleeping(false);
	m_pBox2dWorld->SetDebugDraw(&m_debugDraw);
	m_pBox2dWorld->SetSize(12800,1880);

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


	CCImageButton *pButtonLeft = CCImageButton::create(
		CCSpriteFrame::createWithTexture(texture,CCRectMake(0,0,120,120)),
		CCSpriteFrame::createWithTexture(texture,CCRectMake(120,0,120,120)),
		NULL
		);
	pButtonLeft->setTag(0);
	pButtonLeft->addTargetWithActionForControlEvents(
		this,
		cccontrol_selector(CGameScene::onButtonEvent),
		CCControlEventTouchDown|CCControlEventTouchUpInside|CCControlEventTouchUpOutside
		);
	pButtonLeft->setPosition(CCPointMake(120,60));
	addChild(pButtonLeft);

	CCImageButton *pButtonRight = CCImageButton::create(
		CCSpriteFrame::createWithTexture(texture,CCRectMake(240,120,120,120)),
		CCSpriteFrame::createWithTexture(texture,CCRectMake(360,120,120,120)),
		NULL
		);
	pButtonRight->setTag(1);
	pButtonRight->addTargetWithActionForControlEvents(
		this,
		cccontrol_selector(CGameScene::onButtonEvent),
		CCControlEventTouchDown|CCControlEventTouchUpInside|CCControlEventTouchUpOutside
		);
	pButtonRight->GetSprite()->setRotation(270);
	pButtonRight->setPosition(CCPointMake(280,60));
	addChild(pButtonRight);
	//pButtonRight->setRotationY(90);


	CCImageButton *pButtonAttack = CCImageButton::create(
		CCSpriteFrame::createWithTexture(texture,CCRectMake(240,0,120,120)),
		CCSpriteFrame::createWithTexture(texture,CCRectMake(360,0,120,120)),
		NULL
		);
	pButtonAttack->setTag(2);
	pButtonAttack->addTargetWithActionForControlEvents(
		this,
		cccontrol_selector(CGameScene::onButtonEvent),
		CCControlEventTouchDown
		);
	pButtonAttack->setPosition(CCPointMake(480,60));
	addChild(pButtonAttack);

	CCImageButton *pButtonJump = CCImageButton::create(
		CCSpriteFrame::createWithTexture(texture,CCRectMake(0,120,120,120)),
		CCSpriteFrame::createWithTexture(texture,CCRectMake(120,120,120,120)),
		NULL
		);
	pButtonJump->setTag(3);
	pButtonJump->addTargetWithActionForControlEvents(
		this,
		cccontrol_selector(CGameScene::onButtonEvent),
		CCControlEventTouchDown
		);
	pButtonJump->setPosition(CCPointMake(620,60));
	addChild(pButtonJump);


	m_pPlayer = CPlayer::create();
	m_pPlayer->setPosition(ccp(160,300));
	m_pPlayer->setAnchorPoint(ccp(0.5,0.4));

	this->addChild(m_pPlayer, 128);




	m_pBox2dWorld->AddEntntyForSprite(m_pPlayer);

	m_pBox2dContactListener = new Box2dContactListener();
	m_pBox2dWorld->SetContactListener(m_pBox2dContactListener);

	schedule(schedule_selector(CGameScene::Update),0.1f);

	return true;
}


void CGameScene::onLeftMenuCallBack(CCObject* pSender)
{
	CCLOG("Map X:%.1f Y:%.1f",m_pTileMap->getPositionX(),m_pTileMap->getPositionY());
	//if(m_pTileMap->getPositionX()<10)
	//m_pTileMap->setPositionX(m_pTileMap->getPositionX() + 10);
	m_pPlayer->RunLeft();
	float x,y,z;
	getCamera()->getCenterXYZ(&x,&y,&z);
	//getCamera()->setEyeXYZ(0,0,50);
	//getCamera()->setUpXYZ(-10,0,0);
}
void CGameScene::onRightMenuCallBack(CCObject* pSender)
{
	CCLOG("Map X:%.1f Y:%.1f",m_pTileMap->getPositionX(),m_pTileMap->getPositionY());
	//if(m_pTileMap->getPositionX() < 12800)
	//if(m_pTileMap->getPositionX()>-12800)
	//m_pTileMap->setPositionX(m_pTileMap->getPositionX() - 10); 
	m_pPlayer->RunRight();
	//getCamera()->setUpXYZ(10,0,0);

}
void CGameScene::onAttackMenuCallBack(CCObject* pSender)
{
	this->setPositionX(this->getPositionX() - 50); 
	((CCMenuItemSprite*)pSender)->setPositionX(((CCMenuItemSprite*)pSender)->getPositionX() + 50);
}
void CGameScene::onJumpMenuCallBack(CCObject* pSender)
{
	m_pPlayer->Jump();
}

void CGameScene::onButtonEvent(CCObject*pSender,CCControlEvent event)
{
	switch (((CCNode*)pSender)->getTag())
	{
	case 0:
		if (event == CCControlEventTouchDown)
			m_pPlayer->RunLeft();
		break;;
	case 1:
		if (event == CCControlEventTouchDown)
			m_pPlayer->RunRight();
		break;
	case 2:
		break;
	case 3:
		if (event == CCControlEventTouchDown)
			m_pPlayer->Jump();
		break;
	}


}

void CGameScene::addBoxBodyForSprite( CCSprite* pObject )
{

}

void CGameScene::Update( float dt )
{
	m_pBox2dWorld->Step(dt,10,10);
	uint32 flags = 0;
	flags += m_pBox2dWorld->m_settings.drawShapes            * b2Draw::e_shapeBit;
	flags += m_pBox2dWorld->m_settings.drawJoints            * b2Draw::e_jointBit;
	flags += m_pBox2dWorld->m_settings.drawAABBs            * b2Draw::e_aabbBit;
	flags += m_pBox2dWorld->m_settings.drawPairs            * b2Draw::e_pairBit;
	flags += m_pBox2dWorld->m_settings.drawCOMs                * b2Draw::e_centerOfMassBit;
	m_debugDraw.SetFlags(flags);
	//m_pBox2dWorld->DrawDebugData();
	std::list<Box2dContact>::iterator pos;
	std::list<b2Body *> toDestroy;
	for(pos=m_pBox2dContactListener->contactList.begin();pos!=m_pBox2dContactListener->contactList.end();pos++)
	{
		Box2dContact &contact=*pos;
		b2Body *bodyA=contact.fixtureA->GetBody(),*bodyB=contact.fixtureB->GetBody();
		CBaseEntity *pEntityA = (CBaseEntity*)(bodyA->GetUserData());
		CBaseEntity *pEntityB = (CBaseEntity*)(bodyB->GetUserData());
		if(pEntityA->GetEntityType() == emEntiryType_Player || pEntityB->GetEntityType() == emEntiryType_Player)
		{
			CBaseEntity *pContactTarget = (pEntityA->GetEntityType() == emEntiryType_Player) ? pEntityB : pEntityA;
			if(abs(pContactTarget->getPositionY() - m_pPlayer->getPositionY()) < m_pPlayer->getContentSize().height / 2)
			{
				
				//CCLOG("#Contact Object X: %0.1f  Y:%0.1f",pContactTarget->getPositionX(),pContactTarget->getPositionY());
			}
		}
		


		/*
		for(int i=0;i<4;i++)
		{
			if(contact.fixtureA==blockFixture<i>&&contact.fixtureB==ballFixture)
			{
				toDestroy.push_back(bodyA);
				CCLOG("ok");
			} else if(contact.fixtureB==blockFixture<i>&&contact.fixtureA==ballFixture)
			{
				CCLOG("ok");
				toDestroy.push_back(bodyB);
			}
		}*/

	}
	std::list<b2Body*>::iterator it = toDestroy.begin();
	while(it != toDestroy.end())
	{
		m_pBox2dWorld->DestroyBody(*it);
		it++;
	}
	b2Body *pBody = m_pBox2dWorld->GetBodyList();
	CBaseEntity *pEntity = NULL;// (CBaseEntity*)(bodyA->GetUserData());
	static CCSize winsize = CCDirector::sharedDirector()->getWinSize();
	CCPoint newPosiiton  = m_pTileMap->getPosition();
	CCPoint oldPosition = m_pTileMap->getPosition();
	bool bMoveMap = false;
	while (pBody)
	{
		pEntity = (CBaseEntity*)(pBody->GetUserData());
		if(pEntity->GetEntityType() & emEntiryType_Animal)
		{
			//CCLOG("Body awake:%d, X:%.3f  Y:%.3f  LVX:%.3f  LVY:%.3f ",pEntity->GetB2Body()->IsActive(), pBody->GetPosition().x * PTM_RATIO,pBody->GetPosition().y * PTM_RATIO,
				//pEntity->GetB2Body()->GetLinearVelocity().x,pEntity->GetB2Body()->GetLinearVelocity().y);
			if(pBody->GetPosition().x * PTM_RATIO >= winsize.width / 2)
			{
				bMoveMap = true;
				newPosiiton.x = winsize.width / 2 - pBody->GetPosition().x *  PTM_RATIO;
				//m_pTileMap->setPositionX(winsize.width / 2 - pBody->GetPosition().x *  PTM_RATIO );
			}else
			{
				pEntity->setPositionX(pBody->GetPosition().x * PTM_RATIO );
				newPosiiton.x = 0;
			}

			if(pBody->GetPosition().y * PTM_RATIO >= winsize.height /1.3f)
			{
				bMoveMap = true;
				newPosiiton.y = winsize.height / 1.3f - pBody->GetPosition().y *PTM_RATIO;
				//m_pTileMap->setPositionY(winsize.height / 1.3f - pBody->GetPosition().y *PTM_RATIO);
			}else
			{
				pEntity->setPositionY(pBody->GetPosition().y * PTM_RATIO);
				newPosiiton.y = 0;
			}
			//CCLOG("Player X:%.1f  Y:%.1f",pBody->GetPosition().x * PTM_RATIO,pBody->GetPosition().y *PTM_RATIO);
		}
		pBody = pBody->GetNext();
	}
	if(newPosiiton.x != oldPosition.x ||  newPosiiton.y != oldPosition.y)
		m_pTileMap->setPosition(newPosiiton);
	
}

void CGameScene::CenterView()
{
	CCSize winsize = CCDirector::sharedDirector()->getWinSize();
	CCPoint pos = m_pPlayer->getPosition();
	//if(pos - winsize.width /2 > 0)
		//m_pTileMap->setPositionX(pos.x - winsize.width /2);

}

void CGameScene::draw()
{
		CCLayer::draw();

		ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );

		kmGLPushMatrix();

		m_pBox2dWorld->DrawDebugData();

		kmGLPopMatrix();

		CHECK_GL_ERROR_DEBUG();
}


