

#ifndef _Cockpit_
#define _Cockpit_

#pragma once

#include "Render.h"
#include <cmath>



class Cockpit
{

private:
	bool alert;
	Vector sForward , sUp , sRight;
	
public:

    Cockpit();
    ~Cockpit(){};


    void create();
    void draw();
    void getMechanicsOnScreen();
	void shipDataUpdate(GLfloat f , GLfloat u , GLfloat r , GLfloat  h , GLfloat spd);
	void drawObjective();
	
	
	bool isDocked;
	int dock_reading;
	Point position;
	GLfloat health;
	GLfloat speed;
	bool isLocked;
 
	 
};



#endif
