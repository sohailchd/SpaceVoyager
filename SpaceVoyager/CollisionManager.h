

#ifndef _collisionManager_
#define _collisionManager_

#include "MasterHeader.h"
#include <vector>

class CollisionManager
{

public:

	CollisionManager();
	~CollisionManager();

	void addToList(Quad* quad);
	void deleteFromList(Quad* quad);
	
	void runCollisionEngine();
	
	void addAsTarget(Quad* quad);
	void deleteAsTarget(Quad* quad);

private:
	std::vector<Quad*> _collisionList;
	std::vector<Quad*> _targetList;

};

#endif