
#ifndef _exterminatore_
#define _exterminatore_

#include "Ship.h"


class Exterminatore : public Ship
{

protected:
	Point initPos;


public:
	
	Exterminatore(Point at) 
	{
		initPos = at;
		position = at;
		speed = 5000.0f;
	}
	
	void setDir()
	{

	}

	void AI_engine()
	{
		position += speed*Vector(0,0,1);

		if(position.z > 1000000.0)
		{
			position = initPos;
		}
		if(position.z > -30000 && position.z < 10000)
		{
			//msys->createMissileAt(position,Vector(0,0,-1),100);
		}

		//cout<<"position: "<< position<<endl;
	}



	void drawExterminatore()
	{
		glPushMatrix();
		    glTranslatef(position.x,position.y,position.z);
			glutSolidCube(500.0);
    	glPopMatrix();

		msys->drawList_missile();
	}




	void updateExterminatore()
	{
		AI_engine();
	}



};


class ExterminatoreNet
{

private:
	vector<Exterminatore*>	_listExterMinator;

public:
	
	void createExterminatore(Point at)
	{
		_listExterMinator.push_back(new Exterminatore(at));
	}

	void drawExterminatore()
	{
		for(unsigned int i=0;i < _listExterMinator.size();i++ )
		{
			_listExterMinator[i]->drawExterminatore();
		}
	}

	void updateExterminatore()
	{
		for(unsigned int i=0;i < _listExterMinator.size();i++ )
		{
			_listExterMinator[i]->updateExterminatore();

		}
	}

};

#endif