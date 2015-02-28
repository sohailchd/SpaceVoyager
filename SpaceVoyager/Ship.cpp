#include "Ship.h"




Ship::Ship(Point initialPosition):
       position(initialPosition),
       forward(0,0,-1),
       up(0,1,0),
       right(1,0,0),
       speed(1.5)
{
	msys = new missileSystem();
	collisionBox_ship = new Quad(position,50,50,50);
	_cockpit = new Cockpit();
	next_targetLocation = Point(0,0,0);
	health = 10;
}


void Ship::fly()
{
	if(!collisionBox_ship->getIsColliding())
	{
	   position += speed * forward ; 
	   collisionBox_ship->setPosition(position);
	}
    //printf("Ship.h : position = x:%f y:%f z:%f\n",position.x,position.y,position.z);
		
}

void Ship::init_ship()
{
	_cockpit->create();
}

 void Ship::slide(int dir)
{
    Ship::position += speed * right * dir ; 
}

 void Ship::pitch(double angle)
{
    forward = unit(forward*cos(angle) + up*sin(angle));
    up      = right.cross(forward); 
}


 void Ship::roll(double angle) 
{
     right = unit(right * cos(angle) + up * sin(angle));
     up = right.cross(forward);
}

 void Ship::yaw(double angle) 
{
     right = unit(right * cos(angle) + forward * sin(angle));
     forward = up.cross(right);
}


 


 void Ship::ship_setTarget(Point target)
 {
	 next_targetLocation = target;
 }

 void Ship::draw_target_hud()
 {
	 glPushMatrix();
	 glLineWidth(10.0);
	   Render::getRenderInstance()->drawSegment3d(Point(0 , 0 , 2000000),next_targetLocation);
	   glLineWidth(1.0);
	 glPopMatrix();

 }


 void Ship::onCollision()
 {
	 health -= 1;
 }


 void Ship::shipDraw()
 {

	 _cockpit->draw();
	 msys->drawList_missile();

	 //Draw thw target
	// draw_target_hud();
 }

 void Ship::ship_handleXInput()
 {
	const double deltaSpeed = 10 ;
    const double angle      = 0.01;

	
	
	XInputHandler::getInstance()->updateX();
    
	if(XInputHandler::getInstance()->controller->isConnected)
	{
	 //******** handle right trigger**************
	if(XInputHandler::getInstance()->getTrigerVal('R')> 30)
	{
	 // printf("Triger_R %d \n",_xinputHandler->getTrigerVal('R'));
       setSpeed(getSpeed()+10);
	  XInputHandler::getInstance()->controller[0]._controllerVibration.wRightMotorSpeed = (XInputHandler::getInstance()->getTrigerVal('R')*150);
	   XInputSetState(0, &XInputHandler::getInstance()->controller[0]._controllerVibration);

	}
	else 
	{
       XInputHandler::getInstance()->controller[0]._controllerVibration.wLeftMotorSpeed = 0;
	   XInputHandler::getInstance()->controller[0]._controllerVibration.wRightMotorSpeed = 0;

	   XInputSetState(0, &XInputHandler::getInstance()->controller[0]._controllerVibration);
	}
	//********************* end right trigger

	//******************* handle the left trigger *************
	if(XInputHandler::getInstance()->getTrigerVal('L')> 30)
	{
	  //printf("Triger_L %d \n",xinp->getTrigerVal('L'));
		setSpeed(getSpeed()-10);
	   XInputHandler::getInstance()->controller[0]._controllerVibration.wLeftMotorSpeed = (XInputHandler::getInstance()->getTrigerVal('L')*100);
	   XInputSetState(0, &XInputHandler::getInstance()->controller[0]._controllerVibration);
	}
	else 
	{
       XInputHandler::getInstance()->controller[0]._controllerVibration.wLeftMotorSpeed = 0;
	   XInputHandler::getInstance()->controller[0]._controllerVibration.wRightMotorSpeed = 0;

	   XInputSetState(0, &XInputHandler::getInstance()->controller[0]._controllerVibration);
	}
	//*********************************************************

	if(XInputHandler::getInstance()->getThumbVal('R','X')>0)
	{
		roll(-angle);
	}
	if(XInputHandler::getInstance()->getThumbVal('R','X')<0)
	{
		roll(angle);
	}

	if(XInputHandler::getInstance()->getThumbVal('L','X')<0)
	{
		yaw(angle);
	}

    if(XInputHandler::getInstance()->getThumbVal('L','X')>0)
	{
		yaw(-angle);
	}
	if(XInputHandler::getInstance()->getThumbVal('L','Y')<0)
	{
		pitch(-angle);
	}

    if(XInputHandler::getInstance()->getThumbVal('L','Y')>0)
	{
		pitch(angle);
	}

	//Handle the shoulder:
	if(XInputHandler::getInstance()->getShoulderButton('R'))
	{
		yaw(-angle*5);
	}
	if(XInputHandler::getInstance()->getShoulderButton('L'))
	{
	    yaw(angle*5);
	}
	//Shoot with a
	if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('A'))
	{
		msys->createMissileAt(position,forward ,speed);
	}

    }//// End if
}


 void Ship::shipUpdate()
{

	fly();
	msys->updateList_missile();
	ship_handleXInput();
	 if(collisionBox_ship->Intersects(new Quad(Point(-660000,-10000,-100000),445000,445000,445000)))
	   {
		   teleport(Point(0,0,2000000));
	   }

}


