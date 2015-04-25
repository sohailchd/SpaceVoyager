

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
	GLfloat upload_reading;
public:

    Cockpit();
    ~Cockpit(){};


    void create();
    void draw();
    void getMechanicsOnScreen();
	void shipDataUpdate(GLfloat f , GLfloat u , GLfloat r , GLfloat  h , GLfloat spd);
	void drawObjective();
	void drawSynchServer();	
	
	bool isDocked;
	GLint dock_reading;
	Point position;
	GLfloat health;
	GLfloat speed;
	bool isLocked;
	void setUploadReading(GLfloat n);
	 
};



#endif
