#include "Ship.h"
#include "SoundManager.h"


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
	isDocking = false;
	dock_reading = 0;
	shipActionDiabled = false;
	c_state = _crash;
}


void Ship::setHealth(GLfloat h)
{
	if(health>=0 && health<=10){
	health += h;
	}
	if(health<0){ health =0; }

}

void Ship::vibrateShip(bool t)
{
	    if(t)
		{
	    XInputHandler::getInstance()->controller[0]._controllerVibration.wRightMotorSpeed = 200;
		XInputHandler::getInstance()->controller[0]._controllerVibration.wLeftMotorSpeed = 120;

	    XInputSetState(0, &XInputHandler::getInstance()->controller[0]._controllerVibration);
		}
		else
		{
			/*XInputHandler::getInstance()->controller[0]._controllerVibration.wRightMotorSpeed = 0;
		    XInputHandler::getInstance()->controller[0]._controllerVibration.wLeftMotorSpeed = 0;

	    XInputSetState(0, &XInputHandler::getInstance()->controller[0]._controllerVibration);
		*/
		}
}

void Ship::fly()
{
	//cout<<" ship.cpp: Collision State: "<<collisionBox_ship->getIsColliding()<<endl;
	//cout<<"Ship position: "<<position;
	if(!collisionBox_ship->getIsColliding())
	{
	   position += speed * forward ; 
	   collisionBox_ship->setPosition(position);
	  
	}
	else
	{
		setHealth(-1);
		SoundManager::getInstance()->addCurrentPlayList(ALARM,false,ALARM_C);
		setSpeed(0.00001);
		position += -200.0f*forward;
		collisionBox_ship->setPosition(position);
		collisionBox_ship->setCollision(false);
		
	}
		
    //cout<<"Ship.h : position"<<position<<endl;
		

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
	_cockpit->shipDataUpdate(0,0,0,health,speed);
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

 	
 void Ship::normalDraw()
 {
 }
 void Ship::crashDraw()
 {
 }
 
 void Ship::stutteringDraw()
 {

 }
 double rad = 0.0f;
 void Ship::shipDraw()
 {

	 rad += 100.0f;

	 //position += Vector(sin(rad)*40.0,cos(rad)*10,2.0);
	 _cockpit->draw();


	 msys->drawList_missile();

	
 }

 void Ship::ship_handleXInput()
 {
	const double deltaSpeed = 10 ;
    const double angle      = 0.01;

	if(!shipActionDiabled)
	{
#pragma region _handle_Controller
	
    
	if(XInputHandler::getInstance()->controller->isConnected)
	{
	 //******** handle right trigger**************
	if(XInputHandler::getInstance()->getTrigerVal('R')> 30)
	{
	 // printf("Triger_R %d \n",_xinputHandler->getTrigerVal('R'));
       setSpeed(getSpeed()+10);
	  XInputHandler::getInstance()->controller[0]._controllerVibration.wRightMotorSpeed = (XInputHandler::getInstance()->getTrigerVal('R')*200);
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
#pragma endregion 
	}
	else
	{
	}

}

 void Ship::setDockingReading(int i)
 {
	 if(dock_reading>=0 &&  dock_reading<=10){
	 dock_reading += i;  
	 }
	 if(dock_reading<0){dock_reading = 0;}
	 if(dock_reading>10){ dock_reading = 10; }

	 //dock_reading = dock_reading%10;
 }

 void Ship::shipUpdate()
{
	//cout<<"speed"<<speed<<endl;
	//_cockpit->speed_cube_x =0.00076 * speed;
	fly();
	msys->updateList_missile();
	ship_handleXInput();
#pragma region connect_coockpit_toship
	_cockpit->speed = speed;
	_cockpit->health = health;
	_cockpit->position = position;
	//_cockpit->shipDataUpdate(0,0,0,health,speed);
	_cockpit->isDocked = isDocking;
	_cockpit->dock_reading = dock_reading;
	_cockpit->isLocked = shipActionDiabled;
#pragma endregion 

#pragma region ifDocking_part_one
	if(collisionBox_ship->Intersects(*dockStation)){
		isDocking = true;
	}
	else{
		dockStation->setCollision(false);
		isDocking = false;
		dock_reading = 0;
	}

	
#pragma endregion ifDockingEnd

#pragma region dock_region_part_two
	if(isDocking)
	{
			if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('Y'))
			{
				setDockingReading(1);
			}
			if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('X'))
			{
				setDockingReading(-1);
			}
	
		if(dock_reading==10)
		{
			SoundManager::getInstance()->addCurrentPlayList(DECOMPRESS,false,DECOMPRESS_C);
			shipActionDiabled = true;
		}
		if(dock_reading==0)
		{
			shipActionDiabled = false;
		}
	    
		cout<<"Dockreading: "<<dock_reading<<endl;
	}
#pragma endregion dock_region_end


}


