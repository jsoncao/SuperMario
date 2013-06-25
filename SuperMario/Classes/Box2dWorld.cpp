#include "Box2dWorld.h"
#include "Box2dContact.h"
#include "BaseEntity.h"
#include "BarrierEntity.h"


CBox2dWorld::CBox2dWorld( const b2Vec2& gravity ):
	b2World(gravity)
{

}


CBox2dWorld::~CBox2dWorld(void)
{
}

void CBox2dWorld::AddEntntyForSprite( CBaseEntity* pEntity )
{
	b2Body  * _body;

	if(pEntity->GetEntityType() & emEntiryType_Animal)
	{
		b2BodyDef bd;
		bd.type =  b2_dynamicBody  ;
		bd.linearDamping = 0.3f;
		bd.fixedRotation = true;
		// start position
		bd.position.Set(pEntity->getPositionX() / PTM_RATIO, pEntity->getPositionY() / PTM_RATIO);//此为设置物体的坐标，
		//CCLOG("Barriy :x:%.1f  y:%.1f",pEntity->getPositionX() / PTM_RATIO,pEntity->getPositionY()  /PTM_RATIO);
		_body = CreateBody(&bd);

		b2CircleShape shape;//设置 形状，次为 圆形
		b2PolygonShape shape2;
		shape2.SetAsBox(8/ PTM_RATIO,16/ PTM_RATIO);

		//shape.m_radius = _radius * 1/32.0;

		b2FixtureDef fd;//
		fd.shape =  &shape2 ;
		fd.density = 1.0f/ PTM_RATIO;//质量
		fd.restitution = 0; // bounce
		fd.friction = 0;//不反弹，最大为 1 
		_body->CreateFixture(&fd);
	}
	else
	{
		b2BodyDef bd;
		bd.type =  b2_staticBody ;
		bd.linearDamping = 0.0f;
		bd.fixedRotation = true;
		// start position
		bd.position.Set(pEntity->getPositionX() / PTM_RATIO, pEntity->getPositionY() / PTM_RATIO);//此为设置物体的坐标，
		//CCLOG("Barriy :x:%.1f  y:%.1f",pEntity->getPositionX() / PTM_RATIO,pEntity->getPositionY()  /PTM_RATIO);
		_body = CreateBody(&bd);

		b2PolygonShape shape;
		shape.SetAsBox((pEntity->getContentSize().width/2) / PTM_RATIO,(pEntity->getContentSize().height / 2)/ PTM_RATIO);

		//shape.m_radius = _radius * 1/32.0;
		b2FixtureDef fd;//
		fd.shape =  &shape ;
		fd.density = 0.0f;//质量
		fd.restitution = 0; // bounce
		fd.friction = 0;//不反弹，最大为 1 
		_body->CreateFixture(&fd);
	}

	_body->SetUserData(pEntity);
	pEntity->SetB2Body(_body);

}

void CBox2dWorld::SetSize( float width,float heitht )
{
	//left
	CBarrierEntity *pBrord1 = new CBarrierEntity();
	pBrord1->setPosition(ccp(0,0));
	pBrord1->setContentSize(CCSizeMake(PTM_RATIO*2,heitht*2));
	AddEntntyForSprite(pBrord1);
	 //top
	CBarrierEntity *pBrord2 = new CBarrierEntity();
	pBrord2->setPosition(ccp(0,heitht));
	pBrord2->setContentSize(CCSizeMake(width*2,PTM_RATIO*2));
	AddEntntyForSprite(pBrord2);
	 //right
	CBarrierEntity *pBrord3 = new CBarrierEntity();
	pBrord3->setPosition(ccp(width,0));
	pBrord3->setContentSize(CCSizeMake(PTM_RATIO*2,heitht*2));
	AddEntntyForSprite(pBrord3);

	//bottom
	CBarrierEntity *pBrord4 = new CBarrierEntity();
	pBrord4->setPosition(ccp(0,0));
	pBrord4->setContentSize(CCSizeMake(width*2,PTM_RATIO*2));
	AddEntntyForSprite(pBrord4);



}
