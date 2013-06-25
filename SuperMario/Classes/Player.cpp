#include "Player.h"
using namespace cocos2d;

CPlayer::CPlayer():m_byDirect(0)
{


}
void	CPlayer::RunLeft()
{
	CCArray* framesList = CCArray::create();  
	framesList->addObject(CCSpriteFrame::create("data/mario.png", CCRectMake(0, 0, 54, 64)));
	framesList->addObject(CCSpriteFrame::create("data/mario.png", CCRectMake(54, 0, 54, 64)));    
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(framesList, 0.1f);
	animation->setLoops(3);   
	b2Vec2 gravity = b2Vec2(-0.3f, 0.0f);
	runAction(CCAnimate::create(animation));
		GetB2Body()->SetAwake(true);
	if(m_byDirect == 0)
	{
	
		//GetB2Body()->SetLinearVelocity(gravity);
		//GetB2Body()->ApplyLinearImpulse(gravity, GetB2Body()->GetWorldCenter());
		GetB2Body()->ApplyForce(gravity, GetB2Body()->GetWorldCenter());
		
	}else
	{
		this->setRotationY(180);
		GetB2Body()->SetLinearVelocity(gravity);
	}
	
	
	m_byDirect = 0;
	//setRotation(180);
}

void CPlayer::RunRight()
{
	CCArray* framesList = CCArray::create();    
	framesList->addObject(CCSpriteFrame::create("data/mario.png", CCRectMake(0, 0, 54, 64)));
	framesList->addObject(CCSpriteFrame::create("data/mario.png", CCRectMake(54, 0, 54, 64)));    
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(framesList, 0.1f);
	animation->setLoops(3);   
	b2Vec2 gravity = b2Vec2(0.3f, 0.0f);
	runAction(CCAnimate::create(animation));
	GetB2Body()->SetAwake(true);
	if(m_byDirect == 1)
	{
		//GetB2Body()->SetLinearVelocity(gravity);
		//GetB2Body()->ApplyLinearImpulse(gravity, GetB2Body()->GetWorldCenter());
		GetB2Body()->ApplyForce(gravity, GetB2Body()->GetWorldCenter());
	}else
	{
		this->setRotationY(0);

		GetB2Body()->SetLinearVelocity(gravity);
	}
	m_byDirect = 1;
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

void CPlayer::Jump()
{
	b2Vec2 gravity = b2Vec2(0.0f, 13.0f);
	GetB2Body()->SetLinearVelocity(gravity);
	//GetB2Body()->ApplyLinearImpulse(gravity, GetB2Body()->GetWorldCenter());
}
