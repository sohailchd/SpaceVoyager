
#ifndef _missileSystem_
#define _missileSystem_

#ifndef _IEntityManager_
#include "IEntityManager.h"
#endif

#include "MasterHeader.h"

#define MAX_MISSILE 15
#define MAX_DIS_MISSILE 50000
#define MAX_DIS_MISSILE2 90000

class missile
{
	
private:
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
	missile(Point org ,Vector fwd , double speed):origin(org)
	{
		forward = fwd;
		dir = speed/abs(speed);
		missileSpeed = speed>0?(speed+400.0):(-speed-400);

		cb_cube = new Quad(pos,0.5,0.5,0.5);
		pos = origin;

		lifeOver = false;
		blastOff = false;
		_blast = 0.0f;
	}
	~missile(){}


	
	void draw()
	{
		glPushMatrix();
		IEntityManager::getInstance()->draw_scavs(pos,_blast);
		glPopMatrix();
    }


	void checkLifeTime()
	{
		//checkp the lifeTime
		if((abs(origin.z-pos.z)>MAX_DIS_MISSILE || abs(origin.y-pos.y)>MAX_DIS_MISSILE || abs(origin.x-pos.x)>MAX_DIS_MISSILE) 
			&& !blastOff)
		{
			blastOff = true;
		}

		if((abs(origin.z-pos.z)>MAX_DIS_MISSILE2 || abs(origin.y-pos.y)>MAX_DIS_MISSILE2 || abs(origin.x-pos.x)>MAX_DIS_MISSILE2) 
			&& blastOff)
		{
			lifeOver = true;
		}

	}


	void update()
	{
		pos +=  missileSpeed *forward;
		cb_cube->setPosition(pos);

		checkLifeTime();

		if(blastOff){_blast += 0.2f*50;}
		
	}

	
	bool getLifeTime(){return lifeOver;}

};




class missileSystem 
{

	
private:
	vector<missile*>  _listMissile;

public:
	missileSystem()
	{
	}
	~missileSystem(){};

	
 
	void createMissileAt(Point point , Vector forward , double speed)
	{
		_listMissile.push_back(new missile(point,forward , speed));
	}

	void updateList_missile()
	{
		for(unsigned int i=0;i<_listMissile.size();i++)
		{
			if(_listMissile[i]->getLifeTime())
			{
				_listMissile.erase( _listMissile.begin()+i);
			}
			else
			{
		    	_listMissile[i]->update();
			}
		}
	}

	void drawList_missile()
	{
		for(unsigned int i=0;i<_listMissile.size();i++)
		{
			_listMissile[i]->draw();
		}
	}

};




#endif