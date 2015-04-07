

#ifndef _Ship_
#define _Ship_

#include "SpaceShip.h"
#include "XInputHandler.h"
#include "MissileSystem.h"
#include "Cockpit.h"
#include <math.h>


#define min_max_speed 500.00f



class Ship : SpaceShip
{

protected:
	  	Point position;
	  	Vector forward , up , right;
		//XInputHandler* xinp;
		char* speedText;
		Cockpit *_cockpit;
        float speed;
		GLfloat health;
		bool isDocking;
		int dock_reading;
		
  

	
	void normalDraw();
    void crashDraw();
    void stutteringDraw();

    
public:

	  enum ship_state
	{
		_normal,
		_crash,
		_stuttering
	};
	ship_state c_state;
		//Ship();
      	Ship(Point initialPosition = Point(0,0,0));
      	Point getPositon(){ return position;}
		Vector getForward(){ return forward; }
		void setForward(Vector v){ forward = v; }
      	void fly();
		void teleport(Point new_pos){ position = new_pos ; collisionBox_ship->setPosition(position);collisionBox_ship->setCollision(false);}
      	Vector getDirection(){ return forward; }
      	Vector getVertical(){ return up; }
      	void pitch(double angle);
      	void roll(double angle);
      	void yaw(double angle);
       	double getSpeed(){ return speed; }
		void setSpeed(double New_speed){ /*if(speed >=-990.00 && speed <=990.0)*/ { speed = New_speed;} { if(speed<-1000.0){speed =-1000.0;}if(speed>1000){ speed=1000.0; } }   }
        void slide(int dir);
		void ship_handleXInput();
		void ship_setTarget(Point target);
		void draw_target_hud();
		void setDocking(bool b){  isDocking = b; };
		bool getDocking(){ return isDocking; }
		void init_ship();
 		void shipUpdate();
		void shipDraw();
		void onCollision();
		void vibrateShip(bool t);
		
		void setDockingReading(int i); 
		void setHealth(GLfloat f);
		int getDockingReading() { return dock_reading;  }
	
	    missileSystem* msys;


		//states
		void setCockpitState(ship_state cs){ c_state = cs;}
		ship_state getCockpitState(){return c_state;}

		Quad* collisionBox_ship;
		Point next_targetLocation;
		Quad* dockStation;
		bool shipActionDiabled;
};



#endif
