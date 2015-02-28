
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
	
	}
	
	void setDir()
	{

	}

	void AI_engine()
	{

	}



	void drawExterminatore()
	{
		glPushMatrix();
		    glTranslatef(position.x,position.y,position.z);
			glutSolidCube(100.0);
    	glPopMatrix();

		msys->drawList_missile();
	}




	void updateExterminatore()
	{
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