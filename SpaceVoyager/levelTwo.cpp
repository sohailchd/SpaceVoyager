

#include "levelTwo.h"
#include "MasterHeader.h"
#include "Render.h"
#include "levelTwoScavengers.h"
#include "Exterminatore.h"
#include "Game.h"



void levelTwo::initScene()
{
	
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
      /*******  variables *************/
   fogDensity2       = 0.0001f;
   fogDensity        = 0.0000000001f;
   unity_debrispara  = 0.0f;
   GLdouble fogDensity3=0.0001f;
   isWormhole           = false;
   counterWormhole   = 0.0f;
  /*******************************/


  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (GLfloat)w*1.0 / (GLfloat)h, 1.0,FAR_SIGHT);
  glMatrixMode(GL_MODELVIEW);
  



   //LIGHTING
  GLfloat black[] = { 0.0, 0.0, 0.0, 1.0};
  GLfloat dark[] = { 0.2, 0.15, 0.2, 1.0};
  GLfloat white[] = { 0.7 , 0.7, 0.7, 1.0};
  GLfloat direction[] = { 0.2, 0.0, 10.5,0.0};
  
  //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
  //glMaterialf(GL_FRONT, GL_SHININESS, 8);
  glLightfv(GL_LIGHT0, GL_AMBIENT , white);
  glLightfv(GL_LIGHT0, GL_DIFFUSE , white);
  glLightfv(GL_LIGHT0, GL_SPECULAR , white);
  glLightfv(GL_LIGHT0, GL_POSITION , direction);

  // Keep the lightingt ON as default setting for this sequence
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  

 
  glFogi(GL_FOG_MODE,GL_EXP2);
  glFogfv(GL_FOG_COLOR,fogColor);
  glFogf(GL_FOG_DENSITY,fogDensity3);
  glFogf(GL_FOG_START,1000000.0f);
  glHint(GL_FOG_HINT,GL_NICEST);




  mission_currentState = _intro;
  _ship->init_ship();
  srand(GameStateManager::timeSinceStart/1000);
 
  ifInit = true;
  
 }

levelTwo::levelTwo()
{
	             


	           _ship = new Ship(Point(0,0,2000000));
               _ship->dockStation = new Quad(Point(90000,49000,-10500),1400,1400,1400);
			   collisionManager = new CollisionManager();
			   exterMin = new ExterminatoreNet(); 
			   
#pragma region init_vicinity_colliders
			   scavs_vicinity_trigger = new Quad(Point(90000,49000,-10500),40000,40000,40000);
			   atmosphere_vicinity_alert = new Quad(Point(-960000,-10000,-100000),757000,757000,757000);
#pragma endregion

#pragma region init-collision-Quads
			   planet_quad = new Quad(Point(-960000,-10000,-100000),607000,607000,607000);
			   //for the main-dock-rib
			   unity_collider_a = new Quad(Point(90000,3000,200),6000,6000,30000);
			   //for the dock extendision
			   unity_collider_b = new Quad(Point(90000.0,5000.0,-15000.0),3000.0,30000.0,6000.0);
			   //toroid - one
			   unity_collider_c = new Quad(Point(90000,3000,300),15000,15000,6000);
			   //dock exten
			   unity_collider_d = new Quad(Point(90000,3000,40000),30000,30000,6000);
			   //for the dock
			   unity_dock_collider = new Quad(Point(90000,49000,-16000),4000,4000,4000);
			   //for the rotating toroid 2
			   unity_collider_e = new Quad(Point(90000,4000,-48000),18000,18000,6000);
			   unity_dock2_collider = new Quad(Point(94000,49000,-15500),3000,3000,3000);
			   unity_dock3_collider = new Quad(Point(90000,49000,-10500),1000,1000,1000);
			   wormHole_collider   = new Quad(Point(90000,-49000,-16000),3000,3000,3000);
			   wormHole_collider_b = new Quad(Point(90000,-49000,-10000),500,500,500);
			   wormhole_collider_sensor = new Quad(Point(90000,-49000,-10000),1500,1500,1500);


			   collisionManager->addAsTarget(_ship->collisionBox_ship);
			   collisionManager->addToList(unity_collider_a);
			   collisionManager->addToList(unity_collider_b);
               collisionManager->addToList(unity_collider_c);
               collisionManager->addToList(unity_collider_d);
			   collisionManager->addToList(unity_dock_collider);
			   collisionManager->addToList(unity_collider_e);
			   collisionManager->addToList(unity_dock2_collider);
			   collisionManager->addToList(unity_dock3_collider);
			   collisionManager->addToList(wormHole_collider);
			   collisionManager->addToList(wormHole_collider_b);



			   collisionManager->deleteFromList(unity_collider_a);
			   collisionManager->deleteFromList(unity_collider_d);
#pragma endregion 	   

#pragma region trigger_manager
		 	   collisionManager->addToTriggerList(atmosphere_vicinity_alert);
			   collisionManager->addToTriggerList(scavs_vicinity_trigger);
			   collisionManager->addAsTriggerTarget(_ship->trigger_box);
#pragma endregion


#pragma region sound_manager
			   
#pragma endregion sound_manager

			   exterMin->createExterminatore(Point(9000,-49000,-8000));
		       exterMin->createExterminatore(Point(-9000,49000,-8000));
			   exterMin->createExterminatore(Point(9000,200,-20000));
			   exterMin->createExterminatore(Point(-9000,200,20000));
               exterMin->createExterminatore(Point(5000,-9000,-20000));


#pragma region missileTargetsInits
			   for(GLint i=0;i<exterMin->_listExterMinator.size();i++)
			   {
				   _missileTargets.push_back(exterMin->_listExterMinator[i]->collisionBox);
			   }
#pragma endregion

			   ifInit = false;
			   startAttack = false;
			   enterAtmosphere = false;
}

levelTwo::~levelTwo()
{

}



void levelTwo::display_fn_game()
{

    if(!ifInit)
    {
        initScene();

    }
    
	if(!enterAtmosphere)
	{
    
		drawNormal();
    }
	else
	{
		atmosphereEntryProtocol();
	}
	 SoundManager::getInstance()->removeFromPlayList(SPLASH_THEME_1_C);
	 SoundManager::getInstance()->addCurrentPlayList(LEVEL_TWO_THEME_1,true,LEVEL_TWO_THEME_1_C);
}

void levelTwo::drawUnityExtensions()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);

	//wormhole
	
	glPushMatrix();
	glTranslated(90000,-49000,-16000);
	//glutSolidCube(6000);
	IEntityManager::getInstance()->draw_cube(3000.0,3000.0,3000.0,18);
	glPopMatrix();
	//end wormhole

	///////
	//Quad(Point(90000,3000,40000),6000,40000,6000)
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	glTranslatef(90000,49000,-16000);
	glutSolidCube(6000);
	//IEntityManager::getInstance()->draw_cube(6000,6000,6000,13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(96000,49000,-15500);
	glutSolidCube(3000);
	//IEntityManager::getInstance()->draw_cube(2000.0,2000.0,2000.0,14);
	//IEntityManager::getInstance()->draw_cube(6000,6000,6000,13);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(94000,49000,-14000);
	//glutSolidCube(3000.0);
	IEntityManager::getInstance()->draw_cube(2000.0,2000.0,2000.0,13);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(90000,49000,-10000);
	glutWireCube(700.0);
	IEntityManager::getInstance()->draw_cube(400.0,400.0,400.0,12);
	glTranslatef(0.0,0.0f,-2900.0f);
	glutSolidCube(400.0);
	glPopMatrix();

	glPopMatrix();

	//wormhole docker
	glPushMatrix();
	glTranslatef(90000.0f,-49000.0f,-10000.0f);
	glutWireCube(700.0);
	IEntityManager::getInstance()->draw_cube(400.0,400.0,400.0,15);
	glTranslatef(0.0f,0.0f,-2900.0f);
	glutSolidCube(400.0);
	glPopMatrix();
	// end dockewr 
	glPushMatrix();
	glColor3f(sin(GameStateManager::timeSinceLast*0.01),sin(GameStateManager::timeSinceLast*0.01),sin(GameStateManager::timeSinceLast*0.01));
	glTranslatef(90000.0f,-40000.0f,-10000.0f);
	glutSolidCube(2000.0f);
	//glTranslatef(-90000.0f,40000.0f,10000.0f);
	glPopMatrix();

	Render::getRenderInstance()->drawSegment3d(Point(90000,-49000,-16000),Point(90000,-49000,-10000));
	Render::getRenderInstance()->drawSegment3d(Point(90000,49000,-16000),Point(90000,49000,-10000));
	Render::getRenderInstance()->drawSegment3d(Point(90000,3000,-16000),Point(90000,-49000,-16000));
	glEnable(GL_LIGHTING);
	glPopMatrix(); //end extensions
}

void levelTwo::drawOnScreen()
{
	double w[] = {1.0,1.0,1.0};
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
      glDisable(GL_LIGHTING);
      glDisable(GL_LIGHT0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();


	/*Render::getRenderInstance()->drawHudText12(Point(0.0,0.0,0.0),"REACH UNITY AND FIND DOCKING MODULE.",w);*/
#pragma region mission_objective_info
	switch (mission_currentState)
	{
	case levelTwo::_intro:
		{
			if(XInputHandler::getInstance()->isDigitalButtonPressed('U'))
			{
				//IEntityManager::getInstance()->draw_plane(1,1,11);
             	Render::getRenderInstance()->drawHudText12(Point(-0.5,0.45,0),"MISSIONS INTRO",w);
           	}
		}
		break;
	case levelTwo::_fightCuborgs:
		{
			if(XInputHandler::getInstance()->isDigitalButtonPressed('U'))
			{
			Render::getRenderInstance()->drawHudText12(Point(-0.5,0.45,0),"Kill all the Cuborgs hacking UNITY",w);
			}
		}
		break;
	case levelTwo::_docking_genesis:
		{
			if(XInputHandler::getInstance()->isDigitalButtonPressed('U'))
			{
				Render::getRenderInstance()->drawHudText12(Point(-0.5,0.45,0),"Dock to UNITY and download GENESIS code",w);
			}
		}
		break;
	case levelTwo::_wormholeDocking:
		{
			if(XInputHandler::getInstance()->isDigitalButtonPressed('U'))
			{
				Render::getRenderInstance()->drawHudText12(Point(-0.5,0.45,0),"Connect to wormhole docker",w);
			}
		}
		break;
	default:
		break;
	}
#pragma endregion

	//Vicinit sensors
	if(wormhole_collider_sensor->getTrigger())
	  {
		  Render::getRenderInstance()->drawHudText18(Point(-0.5,0.45,0),"PRESS 'Y' TO WORMHOLE TRAVEL. ",w);
		    SoundManager::getInstance()->pauseFromPlayList(LEVEL_TWO_THEME_1_C);
		  if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('Y'))
		  {
			  isWormhole = true;
			  SoundManager::getInstance()->resumeFromPlayList(LEVEL_TWO_THEME_1_C);
		  }
	  }
	//end vicinity


	glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glPopMatrix();
	
}

void levelTwo::drawNormal()
{
	
    
	//SKY BOX
     glPushMatrix();
	 glDisable(GL_LIGHTING);
	 glDisable(GL_CULL_FACE);
	 glDisable(GLU_CULLING);
	 //glDisable(GL_LIGHT0);
     glTranslatef( _ship->getPositon().x+5000 , _ship->getPositon().y-5000 , _ship->getPositon().z -50000 );
	 glRotated(GameStateManager::timeSinceStart/2000.0,0.2,0.5,1);
	 IEntityManager::getInstance()->create_Sat_A();
     glEnable(GL_LIGHTING);
	 glEnable(GL_CULL_FACE);
	 glEnable(GLU_CULLING);
	 //glEnable(GL_LIGHT0);
     glPopMatrix();
	 //end of SKY-BOX


	 //Planet - CIRYUS
	 glPushMatrix();
	 //shader.bind();
	 //glScalef(15,15,15);
	  glTranslatef(-960000,-10000,-100000);
	   glRotated(GameStateManager::timeSinceStart/1800.0,0.2,0.5,1);
      IEntityManager::getInstance()->create_planet();
	   glTranslatef(60000,1000,10000);
	   //shader.unBind();
	 glPopMatrix();
	//Planet - end

	 //Planet moon - CIRYUS
	 glPushMatrix();
	  glTranslatef(-300000,1400000,-300000);
	   glRotated(GameStateManager::timeSinceStart/1800.0,0.2,0.5,1);
      IEntityManager::getInstance()->create_planet_moon();
	   glTranslatef(60000,1000,10000);
	   //shader.unBind();
	 glPopMatrix();
	//Planet moon- end

	//
	//glPushMatrix();
	//glTranslatef(0,0,0);
	//IEntityManager::getInstance()->draw_dockStation();
	//glScalef(10,10,10);
	//IEntityManager::getInstance()->draw_scavs(Point(0,0,0),0.0f);
	//glTranslatef(0,0,0);
	//glScalef(1,1,1);
	//glPopMatrix();
    //
	
	//Space Station - UNITY
    glPushMatrix();
	  glTranslatef(90000,3000,200);
	  IEntityManager::getInstance()->draw_colony_debris(unity_debrispara);
    glPopMatrix();
    // End unity
	

	
    
	//////nalanda
	/*glPushMatrix();
	  glTranslatef(0,0,2000000-1000);
	  IEntityManager::getInstance()->draw_nalanda();
	glPopMatrix();*/
	/////////////////////


#pragma region unity_extension
	drawUnityExtensions();
#pragma endregion unity_extension

	///////////////////
	//Exter
	if(true)
	{
	   exterMin->drawExterminatore();
	}
	//Exter end

	drawOnScreen();
	_ship->shipDraw();
	
}


void levelTwo::idle_fn_game()
{
	timer_fn_game(0);
}




void levelTwo::keyboard_fn_game(unsigned char& key,int& x, int& y)
{
    const double deltaSpeed = 10 ;
    const double angle      = 0.01;
    char  speed_str[5];
    switch(key)
    {
          case 'w': _ship->setSpeed(_ship->getSpeed() + deltaSpeed);  break;
          case 's': _ship->setSpeed(_ship->getSpeed() - deltaSpeed);  break;
          case 'a': _ship->roll(angle);                              break;
          case 'd': _ship->roll(-angle);                             break;
          case 'm': _ship->slide(1);                                 break;
          case 'n': _ship->slide(-1);                                break;
          case 'r': _ship->teleport(Point(0,0,50000));               break;
		  case 27:  delete[] IEntityManager::getInstance();   GameStateManager::getInstance()->setGameState(_isExiting);break;      
		  case 'f': _ship->shipCreateMissileAt();break;
		  case 'u': exterMin->createExterminatore(_ship->getPositon());
         default:                                                   break;

    }

     glutPostRedisplay();
}


void levelTwo::special_fn_game(int& key , int& x, int& y)
{ 
    float fraction = 0.01f;
    double angle   = 0.01;
     
	switch(key)
	{

    case GLUT_KEY_LEFT :
    {
      _ship->yaw(angle);
      break;
    }
    case GLUT_KEY_RIGHT :
    {
      _ship->yaw(-angle);
      break;
    }
    case GLUT_KEY_UP :
    {
      _ship->pitch(angle);
      break;
    }
    case GLUT_KEY_DOWN :
    {
      _ship->pitch(-angle);
      break;
    }
    default: break;
    
    }

    //printf("%f\n", pos_dummy.x);
    glutPostRedisplay();
}


void levelTwo::atmosphereEntryProtocol()
{

	//glEnable(GL_FOG);
	//glEnable(GL_FOG_DENSITY);
	glDisable(GL_LIGHTING);


	if(_ship->getPositon().z < 640000.0f)
	{
		GameStateManager::getInstance()->setGameState(_retry);
	}

	else
	{
       if(_ship->getPositon().z>1500000.0)
	   {
		   glEnable(GL_FOG);
	   }
	   else
      {
		  glDisable(GL_FOG);
	  }

    _ship->roll(0.01);
	_ship->shipActionDiabled=true;
	_ship->setPosition(Point(sin(GameStateManager::timeSinceStart*0.01*100)*14000,sin(GameStateManager::timeSinceStart*0.01*100)*12000,_ship->getPositon().z));
	glPushMatrix();
    glScaled(500,500,500);
	glTranslated(0,0,-1000);
	IEntityManager::getInstance()->draw_plane(8000,8000,8);
	glPopMatrix();

	//draw the final ship
	_ship->shipDraw();
	}

}


void levelTwo::handleVicinityTriggers()
{
	if(!_ship->trigger_box->Intersects(*scavs_vicinity_trigger))
	{
	   
	}else 
	{
		if(startAttack)
		 {
			 _ship->setAlert(true);
		 }
	}



	//wormholeVicinityTriggers
	if(_ship->trigger_box->Intersects(*wormhole_collider_sensor))
	{
		_ship->trigger_box->setTrigger(true);
		wormhole_collider_sensor->setTrigger(true);
		if(isWormhole)
		{
			 _ship->shipActionDiabled=true;
			 _ship->setSpeed(0);
			 _ship->roll(counterWormhole*0.5f);
			 counterWormhole += 0.05f;
			 if(counterWormhole>10.0f)
			 {
				 GameSequenceStateManager::getInstance()->setSequenceState(inWormhole);
			 }
		}
	}else
	{
		_ship->trigger_box->setTrigger(false);
		wormhole_collider_sensor->setTrigger(false);
	}
	//
}

void levelTwo::timer_fn_game(int t)
{
	
    if(_ship->collisionBox_ship->Intersects(*planet_quad))
	{
		_ship->setSpeed(1000);
		_ship->setCockpitState(_ship->_alert); 
		_ship->teleport(Point(0,0,2000000));
		_ship->setForward(Vector(0,0,-1));
	    _ship->shipActionDiabled = true;
		enterAtmosphere = true;
	}
	handleVicinityTriggers();

	  
	   _ship->shipUpdate();
	   _ship->shipUpdateTargetList(_missileTargets);
       collisionManager->runCollisionEngine();
	   /*collisionManager->runTriggerEngine();   */

	   
	   	//Exterminator
	   exterMin->updateExterminatore();	
	   //Ent exter

#pragma region camera_setUp
       Point eye(_ship->getPositon());
       Point at(_ship->getPositon() + _ship->getDirection());
       Vector up(_ship->getVertical());


      glLoadIdentity();
      gluLookAt(eye.x,eye.y,eye.z,
                at.x,at.y,at.z,
                up.i,up.j,up.k);
#pragma endregion camera_setUp  

      glutPostRedisplay();
}



