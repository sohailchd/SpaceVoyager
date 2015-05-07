

#ifndef __Ship_
#define __Ship_
#pragma once

#include "SpaceShip.h"
#include "XInputHandler.h"
#include "MissileSystem.h"
#include "Cockpit.h"
#include <math.h>


#define MIN_MAX_SPEED 1500.00f



class Ship : SpaceShip
{

protected:
	  	Point position;
	  	Vector forward , up , right;
		char* speedText;
		Cockpit *_cockpit;
        float speed;
		GLfloat health;
		bool isDocking;
		int dock_reading;
	    GLfloat SPEED_INC;
        bool alert;

	
	void normalDraw();
    void crashDraw();
    void stutteringDraw();

    
public:

	  enum ship_state
	{
		_normal,
		_alert,
		_stuttering
	};
	ship_state c_state;
		
	   
      	Ship(Point initialPosition = Point(0,0,0));
      	Point getPositon(); 
		Vector getForward(); 
		void setForward(Vector v); 
      	void fly();
		void teleport(Point new_pos);
      	Vector getDirection(); 
      	Vector getVertical(); 
      	void pitch(double angle);
      	void roll(double angle);
      	void yaw(double angle);
       	double getSpeed();
		void setSpeed(GLfloat New_speed);
        void slide(int dir);
		void ship_handleXInput();
		void ship_setTarget(Point target);
		void draw_target_hud();
		void setDocking(bool b);
		bool getDocking();
		void init_ship();
 		void shipUpdate();
		void shipDraw();
		void onCollision();
		void vibrateShip(bool t);
		void setPosition(Point p);
		void setDockingReading(int i); 
		void setHealth(GLfloat f);
		int  getDockingReading();
	    void setAlert(bool l);
		bool getAlert();


		vector<Quad*> _shipTargetList;
        missileSystem* msys;
		void shipUpdateTargetList(vector<Quad*> _list);
		void shipCreateMissileAt();
		
		void setCockpitState(ship_state cs);
		ship_state getCockpitState(){ return _normal; }

		Quad* collisionBox_ship;
		Point next_targetLocation;
		Quad* trigger_box;


		Quad* dockStation;
		bool shipActionDiabled;
};



#endif
