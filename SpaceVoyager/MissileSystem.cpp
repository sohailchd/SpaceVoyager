
#include "MissileSystem.h"


#pragma region _missileObject

    missile::missile(Point org ,Vector fwd , double speed , vector<Quad*> _list):origin(org)
	{
		forward = fwd;
		dir = speed/speed;
		missileSpeed = 1500.00+abs(speed);

		cb_cube = new Quad(pos,6000,6000,6000);
		pos = origin;

		lifeOver = false;
		blastOff = false;
		_blast = 0.0f;

		if(_list.size()>0)
		{
		collisionManager = new CollisionManager();
		collisionManager->addAsTarget(cb_cube);
		for(GLint i=0;i<_list.size();i++)
		{
			collisionManager->addToList(_list[i]);
		}
		}
	}
	missile::~missile(){}


	void missile::setPosition(Point p)
	{
		pos = p;
		cb_cube->setPosition(pos);
	}
	void missile::draw()
	{
		glPushMatrix();
		IEntityManager::getInstance()->draw_scavs(pos,_blast);
		glPopMatrix();
    }

	void missile::initTargetList(vector<Quad*> _list)
	{
		_targetList = _list;
	}

	void missile::checkLifeTime()
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

		// if it hits sometargets
		if(cb_cube->getIsColliding())
		{
			lifeOver = true;
			cout<<"Blasted till u last"<<endl;
		}
	}


	void missile::update()
	{
		pos +=  missileSpeed *forward;
		setPosition(pos);

		checkLifeTime();
        if(blastOff){_blast += 0.2f*50;}
		collisionManager->runCollisionEngine();
	}

	
	bool missile::getLifeTime(){return lifeOver;}

#define endregion



#pragma region _missileSystem_


	missileSystem::missileSystem()
	{
	
	}
	missileSystem::~missileSystem(){};



	void missileSystem::createMissileAt(Point point , Vector forward , double speed , vector<Quad*> _list)
	{
		if(_listMissile.size()<MAX_MISSILE)
		{
		_listMissile.push_back(new missile(point,forward , speed , _list));
		}
	}

	void missileSystem::updateList_missile()
	{
		for(unsigned int i=0;i<_listMissile.size();i++)
		{
			if(_listMissile[i]->getLifeTime())
			{
				 SAFE_DELETE(_listMissile[i]->cb_cube);
				 SAFE_DELETE(_listMissile[i])
				_listMissile.erase( _listMissile.begin()+i);
			}
			else
			{
		    	_listMissile[i]->update();
			}

		}
	}

	

	void missileSystem::drawList_missile()
	{
		for(unsigned int i=0;i<_listMissile.size();i++)
		{
			_listMissile[i]->draw();
		}
	}


#pragma endregion