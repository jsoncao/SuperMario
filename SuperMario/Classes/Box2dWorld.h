#pragma once
#include "Box2D/Box2D.h"
#define  PTM_RATIO 32.0f

struct Settings
{
	Settings() :
		viewCenter(0.0f, 360.0f),
		hz(60.0f),
		velocityIterations(8),
		positionIterations(3),
		drawShapes(1),
		drawJoints(1),
		drawAABBs(1),
		drawPairs(1),
		drawContactPoints(0),
		drawContactNormals(0),
		drawContactForces(0),
		drawFrictionForces(0),
		drawCOMs(0),
		drawStats(1),
		drawProfile(0),
		enableWarmStarting(1),
		enableContinuous(1),
		enableSubStepping(0),
		pause(0),
		singleStep(0)
	{}

	b2Vec2 viewCenter;
	float32 hz;
	int32 velocityIterations;
	int32 positionIterations;
	int32 drawShapes;
	int32 drawJoints;
	int32 drawAABBs;
	int32 drawPairs;
	int32 drawContactPoints;
	int32 drawContactNormals;
	int32 drawContactForces;
	int32 drawFrictionForces;
	int32 drawCOMs;
	int32 drawStats;
	int32 drawProfile;
	int32 enableWarmStarting;
	int32 enableContinuous;
	int32 enableSubStepping;
	int32 pause;
	int32 singleStep;
};
class CBaseEntity;
class CBox2dWorld:public b2World
{
public:
	CBox2dWorld(const b2Vec2& gravity);
	virtual ~CBox2dWorld(void);
	void	SetSize(float width,float heitht);

	void	AddEntntyForSprite(CBaseEntity* pEntity);
	Settings m_settings;

};

