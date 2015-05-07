
#ifndef _missileSystem_
#define _missileSystem_


#include "IEntityManager.h"


#include "MasterHeader.h"
#include "CollisionManager.h"

#define MAX_MISSILE      400
#define MAX_DIS_MISSILE  100000
#define MAX_DIS_MISSILE2 1500000

class missile
{
	
public:
	Point pos;
	Quad* cb_cube;
	Point origin;
	Vector forward;
	double missileSpeed;
	double dir;
	bool lifeOver;
	bool blastOff;
	GLfloat _blast;
	
public:
	missile(Point org ,Vector fwd , double speed , vector<Quad*> _list);
	
	~missile();


	
	void draw();
	void checkLifeTime();
	void update();
	void initTargetList(vector<Quad*> _list);
	void setPosition(Point p);

	vector<Quad*> _targetList;
	bool getLifeTime();
	CollisionManager* collisionManager;
	

};




class missileSystem 
{



public:
	missileSystem();
	
	~missileSystem();

	
    vector<missile*>  _listMissile;
	
	void createMissileAt(Point point , Vector forward , double speed , vector<Quad*> _list);
	void updateList_missile();
	void drawList_missile();
	void initTargetList(vector<Quad*> _list);

};




#endif