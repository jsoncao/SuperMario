#include "Player.h"
using namespace cocos2d;

CPlayer::CPlayer():m_byDirect(0)
{


}

void CPlayer::Run()
{
	CCArray* framesList = CCArray::create();    
	framesList->addObject(CCSpriteFrame::create("data/mario.png", CCRectMake(0, 0, 54, 64)));
	framesList->addObject(CCSpriteFrame::create("data/mario.png", CCRectMake(54, 0, 54, 64)));    
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(framesList, 0.1f);
	animation->setLoops(3);    
	runAction(CCAnimate::create(animation));
}

bool CPlayer::init()
{
	CCSpriteFrame* pFrame = CCSpriteFrame::create("data/mario.png", CCRectMake(0, 0, 54, 64));
	//setDisplayFrame(pFrame);
	initWithSpriteFrame(pFrame);
	return true;
}

void CPlayer::Stand()
{
	CCSpriteFrame* pFrame = CCSpriteFrame::create("data/mario.png", CCRectMake(0, 0, 54, 64));
	setDisplayFrame(pFrame);
}
