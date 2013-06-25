#include "CImageButton.h"


CCImageButton::CCImageButton(void):
	m_nStatus(0),m_pSprite(NULL)
{
	memset(m_pSpriteFrame,0,sizeof(m_pSpriteFrame));
}


CCImageButton::~CCImageButton(void)
{
	//CC_SAFE_RELEASE_NULL(m_pSprite);
	CC_SAFE_RELEASE_NULL(m_pSpriteFrame[0]);
	CC_SAFE_RELEASE_NULL(m_pSpriteFrame[1]);
	CC_SAFE_RELEASE_NULL(m_pSpriteFrame[2]);
}

CCImageButton * CCImageButton::create( CCSpriteFrame * spriteFrameNormal,CCSpriteFrame * spriteFrameSelected,CCSpriteFrame * spriteFrameDisabled )
{
	CCImageButton *pRet = new CCImageButton();
	if(pRet->init() == false)
	{
		delete pRet;
		return NULL;
	};
	pRet->autorelease();
	pRet->SetNormalSpriteFrame(spriteFrameNormal);
	pRet->SetSelectedSpriteFrame(spriteFrameSelected ? spriteFrameSelected :spriteFrameNormal);
	pRet->SetDisabledSpriteFrame(spriteFrameDisabled ? spriteFrameDisabled :spriteFrameNormal);
	return pRet;
}

void CCImageButton::SetNormalSpriteFrame( CCSpriteFrame * spriteFrame )
{
	CC_ASSERT(spriteFrame);
	CC_SAFE_RETAIN(spriteFrame);
	CC_SAFE_RELEASE_NULL(m_pSpriteFrame[0]);
	m_pSpriteFrame[0] = spriteFrame;

	m_pSprite->setDisplayFrame(m_pSpriteFrame[0]);
	setContentSize(m_pSprite->getContentSize());
	//m_pSprite->setPosition(ccp(m_pSprite->getContentSize().width / 2,m_pSprite->getContentSize().height/2));
}

void CCImageButton::SetSelectedSpriteFrame( CCSpriteFrame * spriteFrame )
{
	CC_ASSERT(spriteFrame);
	CC_SAFE_RETAIN(spriteFrame);
	CC_SAFE_RELEASE_NULL(m_pSpriteFrame[1]);
	m_pSpriteFrame[1] = spriteFrame;
}

void CCImageButton::SetDisabledSpriteFrame( CCSpriteFrame * spriteFrame )
{
	CC_ASSERT(spriteFrame);
	CC_SAFE_RETAIN(spriteFrame);
	CC_SAFE_RELEASE_NULL(m_pSpriteFrame[2]);
	m_pSpriteFrame[2] = spriteFrame;
}

void CCImageButton::registerWithTouchDispatcher( void )
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

//用户手指第一次触摸
void CCImageButton::ccTouchesBegan(CCSet * pTouches,CCEvent * pEvent)
{
	int nTouchID = 0;
	CCTouch *pTouch = NULL;
	CCSetIterator iter = pTouches->begin();
	for (; iter!=pTouches->end(); iter++) 
	{
		pTouch = (CCTouch * )(* iter);
		if(ccTouchBegan(pTouch,NULL))
			m_nTouchID = pTouch->getID();
	}
}
void CCImageButton::ccTouchesMoved(CCSet * pTouches, CCEvent *pEvent )
{
	CCLOG("CCImageButton::ccTouchesMoved");	
	CCTouch *pTouch = NULL;
	CCSetIterator iter = pTouches->begin();
	for (; iter!=pTouches->end(); iter++) 
	{
		pTouch = (CCTouch * )(* iter);
		if(pTouch->getID() == m_nTouchID)
			ccTouchMoved(pTouch,NULL);
	}

}

void CCImageButton::ccTouchesEnded(CCSet * pTouches, CCEvent *pEvent )
{
	CCLOG("CCImageButton::ccTouchesEnded");
	CCTouch *pTouch = NULL;
	CCSetIterator iter = pTouches->begin();
	for (; iter!=pTouches->end(); iter++) 
	{
		pTouch = (CCTouch * )(* iter);
		if(pTouch->getID() == m_nTouchID)
			ccTouchEnded(pTouch,NULL);
	}
}


bool CCImageButton::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	CCLOG("CCImageButton::ccTouchBegan");
	CCPoint touchPoint = pTouch->getLocationInView();
	touchPoint = CCDirector::sharedDirector()->convertToGL( touchPoint );
	CCRect rt = boundingBox();
	rt.setRect(getPositionX() - getAnchorPoint().x * getContentSize().width,
		getPositionY() - getAnchorPoint().y * getContentSize().height,
		getContentSize().width,
		getContentSize().height
		);
	if (rt.containsPoint(touchPoint))
	{
		m_pSprite->setDisplayFrame(m_pSpriteFrame[1]);
		sendActionsForControlEvents(CCControlEventTouchDown);
		return true;
	}
	return false;
}


void CCImageButton::ccTouchMoved( CCTouch *pTouch, CCEvent *pEvent )
{
	CCLOG("CCImageButton::ccTouchMoved");
}

void CCImageButton::ccTouchEnded( CCTouch *pTouch, CCEvent *pEvent )
{
	CCLOG("CCImageButton::ccTouchEnded");
	m_pSprite->setDisplayFrame(m_pSpriteFrame[0]);
	if (isTouchInside(pTouch))
	{
		sendActionsForControlEvents(CCControlEventTouchUpInside);        
	}
	else
	{
		sendActionsForControlEvents(CCControlEventTouchUpOutside);        
	}
}

bool CCImageButton::init()
{
	memset(m_pSpriteFrame,0,sizeof(m_pSpriteFrame));

	if(CCControl::init())
	{
		m_pSprite = CCSprite::create();
		addChild(m_pSprite);
		this->setTouchEnabled(true);
		return true;
	};
	return false;
}
