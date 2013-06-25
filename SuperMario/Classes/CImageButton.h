#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace cocos2d::extension;
class CCImageButton  :public cocos2d::extension::CCControl
{
public:
	CCImageButton(void);
	virtual ~CCImageButton(void);
	static CCImageButton *	create(CCSpriteFrame * spriteFrameNormal,CCSpriteFrame * spriteFrameSelected = NULL,CCSpriteFrame * spriteFrameDisabled = NULL);
	virtual bool init();
	CCSprite*	GetSprite(){ return m_pSprite;};

	void	SetNormalSpriteFrame(CCSpriteFrame * spriteFrame);
	void	SetSelectedSpriteFrame(CCSpriteFrame * spriteFrame);
	void	SetDisabledSpriteFrame(CCSpriteFrame * spriteFrame);
	virtual void registerWithTouchDispatcher(void);
public:
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	virtual void ccTouchesBegan(CCSet * pTouches,CCEvent * pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
private:
	int			m_nTouchID;
	CCSprite*	m_pSprite;
	CCSpriteFrame*	m_pSpriteFrame[3];
	int		m_nStatus;

};

