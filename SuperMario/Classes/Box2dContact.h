#pragma once
#include "Box2D/Box2D.h"
#include "cocos2d.h"
#include <list>
using namespace std;
class Box2dContact
{
public :
	b2Fixture *fixtureA,*fixtureB;
	bool operator==(const Box2dContact& other) const
	{
		return (fixtureA == other.fixtureA) && (fixtureB == other.fixtureB);
	}

};
class Box2dContactListener:public b2ContactListener
{
	virtual void BeginContact(b2Contact* contact) 
	{ 
		if(contact)
		{
			Box2dContact mc;
			mc.fixtureA=contact->GetFixtureA();
			mc.fixtureB=contact->GetFixtureB();
			contactList.push_back(mc);
		}

		B2_NOT_USED(contact); 
	}

	/// Called when two fixtures cease to touch.
	virtual void EndContact(b2Contact* contact) 
	{ 
		Box2dContact mc;
		mc.fixtureA=contact->GetFixtureA();
		mc.fixtureB=contact->GetFixtureB();
		list<Box2dContact>::iterator pos;
		pos = find(contactList.begin(),contactList.end(),mc);
		if(pos!=contactList.end())
		{
			contactList.erase(pos);
		}
		B2_NOT_USED(contact); 
	}

	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(oldManifold);
	}


	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(impulse);
	}
public:
	list<Box2dContact> contactList;
};
