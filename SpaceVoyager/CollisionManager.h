

#ifndef _collisionManager_
#define _collisionManager_

#include "MasterHeader.h"
#include <vector>

/**********************************
    _targetList    : Main objects
	_collisionList : RigidBodies

	collision is registered as
	if {Main --->>>> RigidBodies}

***********************************/

class CollisionManager
{

public:

	CollisionManager();
	~CollisionManager();

	void addToList(Quad* quad);
	void deleteFromList(Quad* quad);
	void addToTriggerList(Quad* quad);
	void deleteFromTriggerList(Quad* quad);
	

	void runCollisionEngine();
	void runTriggerEngine();
	
	void addAsTarget(Quad* quad);
	void deleteAsTarget(Quad* quad);
	void addAsTriggerTarget(Quad* quad);
	void deleteAsTriggerTarget(Quad* quad);


private:
	std::vector<Quad*> _collisionList;
	std::vector<Quad*> _targetList;

	std::vector<Quad*> _triggerList;
	std::vector<Quad*> _triggerTargetList;

};

#endif