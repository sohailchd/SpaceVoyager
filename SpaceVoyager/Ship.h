

#ifndef _Ship_
#define _Ship_

#include "SpaceShip.h"
#include "XInputHandler.h"
#include "MissileSystem.h"
#include "Cockpit.h"

class Ship : SpaceShip
{

protected:
	  	Point position;
	  	Vector forward , up , right;
		//XInputHandler* xinp;
		char* speedText;
		Cockpit *_cockpit;
        double speed;
		short unsigned int health;
      
public:
		//Ship();
      	Ship(Point initialPosition = Point(0,0,0));
      	Point getPositon(){ return position;}
		Vector getForward(){ return forward; }
      	void fly();
		void teleport(Point new_pos){ position = new_pos ;}
      	Vector getDirection(){ return forward; }
      	Vector getVertical(){ return up; }
      	void pitch(double angle);
      	void roll(double angle);
      	void yaw(double angle);
       	double getSpeed(){ return speed; }
      	void setSpeed(double New_speed){ speed = New_speed; }
        void slide(int dir);
		void ship_handleXInput();
		void ship_setTarget(Point target);
		void draw_target_hud();

		void init_ship();
 		void shipUpdate();
		void shipDraw();
		void onCollision();

	    missileSystem* msys;


		Quad* collisionBox_ship;
		Point next_targetLocation;
};



#endif
