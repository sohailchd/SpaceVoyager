
#ifndef _exterminatore_
#define _exterminatore_

#include "Ship.h"


class Exterminatore 
{

protected:
	Point initPos;
	Point position;
	bool isAlive;


public:
	
   Exterminatore();
   ~Exterminatore();

	Exterminatore(Point at);
	
	void drawExterminatore();
	void setPosition(Point p);
	Point getPosition();
    void updateExterminatore();
	void setIsAlive(bool b);
	bool getIsAlive();
    bool isHit;
	Quad  *collisionBox;
};


class ExterminatoreNet
{

private:
	

public:
	ExterminatoreNet();
	~ExterminatoreNet();

	vector<Exterminatore*>	_listExterMinator;

	void createExterminatore(Point at);
	void drawExterminatore();
	void updateExterminatore();
	

};

#endif