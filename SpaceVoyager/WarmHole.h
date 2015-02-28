
#ifndef _WarmHole_H_
#define _WarmHole_H_

#include "MissileSystem.h"
#include <vector>
#include "CollisionManager.h"
#include "Geometry.h"

using namespace std;

class WarmHoleSequence
{
public:
	 WarmHoleSequence();
	~WarmHoleSequence();

	void draw_scene();
	void update_scene();
	void sequencer();

private:
	CollisionManager     _collisionManager_warmHole;
	   vector<Quad*>     _upCommingList;
};

#endif