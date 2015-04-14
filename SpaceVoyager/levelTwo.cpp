

#include "levelTwo.h"
#include "MasterHeader.h"
#include "Render.h"
#include "levelTwoScavengers.h"
#include "Exterminatore.h"
#include "Game.h"

#include <algorithm>


		  GLfloat fogDensity        = 0.0000000001f;
          GLfloat fogColor[4]       = {0.8,0.8,0.8,0.0};
          GLfloat unity_debrispara  = 0.0f;
          double white_l2[]         = { 0.1,0.1,0.1 };


void levelTwo::initScene()
{
	
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
    


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
  //glEnable(GL_LIGHT1);


  //fog
  //glEnable(GL_FOG);
  glFogi(GL_FOG_MODE,GL_EXP2);
  glFogfv(GL_FOG_COLOR,fogColor);
  glFogf(GL_FOG_DENSITY,fogDensity);
  glFogf(GL_FOG_START,1000000.0f);
  glHint(GL_FOG_HINT,GL_NICEST);

  level2_currentState = _reachUnity;
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




#pragma region init-collision-Quads
			   planet_quad = new Quad(Point(-660000,-10000,-100000),607000,607000,607000);
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
#pragma endregion 

			   collisionManager->addAsTarget(_ship->collisionBox_ship);
			   //collisionManager->addToList(planet_quad);
			   collisionManager->addToList(unity_collider_a);
			   collisionManager->addToList(unity_collider_b);
               collisionManager->addToList(unity_collider_c);
               collisionManager->addToList(unity_collider_d);
			   collisionManager->addToList(unity_dock_collider);
			   collisionManager->addToList(unity_collider_e);
			   collisionManager->addToList(unity_dock2_collider);
			   collisionManager->addToList(unity_dock3_collider);
			   //collisionManager->addAsTarget(_ship->msys->_listMissile[0]->cb_cube);



			   collisionManager->deleteFromList(unity_collider_a);
			   collisionManager->deleteFromList(unity_collider_d);



#pragma region sound_manager
			   
#pragma endregion sound_manager



			  /* collisionManager->deleteFromList(unity_collider_d);
			   collisionManager->deleteFromList(unity_collider_a);
               collisionManager->deleteFromList(unity_collider_c);*/


			   /*for(int i =-50000;i<500000;i+=20000)
			   {
				
				   for(int j=-15000;j<100000;j+= 10000)
				   {
					  
					   exterMin->createExterminatore(Point(i,j,rand()%(-60000)+(-2000000)));
				   
				   }
			   }*/
			  
			   /*for(int i=0;i<1000;i++)
			   {
				   exterMin->createExterminatore( Point(
					   rand()%(100000)+(-100000),
					   rand()%(100000)+(-500000),
					   rand()%(1000000)+(-600000)
					   ) );
			   }*/

			   // initScene();
			   ifInit = false;
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
    
	if(_ship->getCockpitState()==_ship->_normal)
	{
     #pragma region _normal
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
	 //glScalef(15,15,15);
	  glTranslatef(-660000,-10000,-100000);
	   glRotated(GameStateManager::timeSinceStart/1800.0,0.2,0.5,1);
      IEntityManager::getInstance()->create_planet();
	   glTranslatef(60000,1000,10000);
	 glPopMatrix();
	//Planet - end


	//
	glPushMatrix();
	glTranslatef(0,0,0);
	//IEntityManager::getInstance()->draw_dockStation();
	//glScalef(10,10,10);
	IEntityManager::getInstance()->draw_scavs(Point(0,0,0),0.0f);
	glTranslatef(0,0,0);
	glScalef(1,1,1);
	glPopMatrix();
    //
	
	//Space Station - UNITY
    glPushMatrix();
	  glTranslatef(90000,3000,200);
	  IEntityManager::getInstance()->draw_colony_debris(unity_debrispara);
    glPopMatrix();
    // End unity
	

	
    
	//Nalanda
	/*glPushMatrix();
	  glTranslatef(0,0,2000000-1000);
	  IEntityManager::getInstance()->draw_nalanda();
	glPopMatrix();*/
	///////////////////////

	//test Code


	/**
	glPushMatrix();
	glTranslatef(-660000,-10000,-100000);
	glutSolidCube(757000);
	glPopMatrix();
	**/


	//glPushMatrix();
	//glTranslatef(90000,3000,200);
	//glutSolidCube(1000);
	//glPopMatrix();
	

#pragma region unity_extension

	glPushMatrix();
	Render::getRenderInstance()->drawSegment3d(Point(90000,3000,-16000),Point(90000,-49000,-16000));
	glColor3f(0.2,0.4,0.6);
	glTranslated(90000,-49000,-16000);
	glutSolidCube(6000);
	glPopMatrix();

	///////
	//Quad(Point(90000,3000,40000),6000,40000,6000)
	glPushMatrix();
	glTranslatef(90000,49000,-16000);
	glutSolidCube(6000);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(96000,49000,-15500);
	glutSolidCube(3000);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(94000,49000,-14000);
	glutSolidCube(3000);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(90000,49000,-10000);
	glutSolidCube(400);
	glPopMatrix();

	Render::getRenderInstance()->drawSegment3d(Point(90000,49000,-16000),Point(90000,49000,-10000));

#pragma endregion unity_extension

	///////////////////
	//Exter
	exterMin->drawExterminatore();
	//Exter end

#pragma endregion
	drawOnScreen();
	_ship->shipDraw();
	
	}

else
	{
		atmosphereEntryProtocol();
	}


	

	//SoundManager::getInstance()->pauseFromPlayList(SPLASH_THEME_1_C);
	//		   SoundManager::getInstance()->addCurrentPlayList(CHASE_UNITY,true,CHASE_UNITY_C);
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

	switch (level2_currentState)
	{
	case levelTwo::_reachUnity:
		{
			if(XInputHandler::getInstance()->isDigitalButtonPressed('U'))
			{
				IEntityManager::getInstance()->draw_plane(1,1,11);

				Render::getRenderInstance()->drawHudText12(Point(-0.5,0.35,0),"REACH UNITY AND FIND DOCKING MODULE.",w);
				Render::getRenderInstance()->drawHudText12(Point(-0.5,0.25,0),"DOWNLOAD THE GENESIS FROM Qserver in UNITY.",w);

			}
		}
		break;
	case levelTwo::_docking:
		break;
	case levelTwo::_seqUpload:
		break;
	case levelTwo::_wormholeDocking:
		break;
	default:
		break;
	}

	glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glPopMatrix();
	
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
		  case 27:  exit(0);  delete[] IEntityManager::getInstance();                                     break;      
		  case 'f': _ship->msys->createMissileAt(_ship->getPositon(),_ship->getForward() ,_ship->getSpeed());break;
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
    _ship->roll(0.01);
	_ship->shipActionDiabled=true;
	glPushMatrix();
    glScaled(500,500,500);
	glTranslated(0,0,-1000);
	   IEntityManager::getInstance()->draw_plane(8000,8000,8);
	glPopMatrix();

	//draw the final ship
	_ship->shipDraw();
	}

}


void levelTwo::timer_fn_game(int t)
{
	

    if(unity_collider_a->getIsColliding()){unity_debrispara += 1.0f; }
	if(_ship->collisionBox_ship->Intersects(*planet_quad))
	{
		_ship->setSpeed(1000);
		_ship->setCockpitState(_ship->_crash); 
		_ship->teleport(Point(0,0,2000000));
		_ship->setForward(Vector(0,0,-1));
	    _ship->shipActionDiabled = true;
	}

	  
	   _ship->shipUpdate();
       collisionManager->runCollisionEngine();
	   

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



