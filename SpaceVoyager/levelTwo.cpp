

#include "levelTwo.h"
#include "MasterHeader.h"
#include "Render.h"
#include "levelTwoScavengers.h"
#include "Exterminatore.h"



void levelTwo::initScene()
{
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);


  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (GLfloat)w*1 / (GLfloat)h, 1.0,FAR_SIGHT);
  glMatrixMode(GL_MODELVIEW);
  



   //LIGHTING
  GLfloat black[] = { 0.0, 0.0, 0.0, 1.0};
  GLfloat dark[] = { 0.2, 0.15, 0.2, 1.0};
  GLfloat white[] = { 0.7 , 0.7, 0.7, 1.0};
  GLfloat direction[] = { 0.2, 0.0, 10.5,0.0};

  //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
 // glMaterialf(GL_FRONT, GL_SHININESS, 30);
  glLightfv(GL_LIGHT0, GL_AMBIENT , white);
  glLightfv(GL_LIGHT0, GL_DIFFUSE , white);
 // glLightfv(GL_LIGHT0, GL_SPECULAR , white);
  glLightfv(GL_LIGHT0, GL_POSITION , direction);

  // Keep the lightingt ON as default setting for this sequence
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);

  _ship->init_ship();

  ifInit = true;
  
 }

levelTwo::levelTwo()
{
	_ship = new Ship(Point(0,0,2000000));
			   exterMin = new ExterminatoreNet(); 
			   planet_quad = new Quad(Point(-660000,-10000,-100000),445000,445000,445000);
			   collisionManager = new CollisionManager();
			   soundManager_ltwo = new SManager();
			  // initScene();
			   ifInit = false;
}

levelTwo::~levelTwo()
{
	soundManager_ltwo->dropSoundEngine();
}


void levelTwo::display_fn_game()
{

    if(!ifInit)
    {
        initScene();
    }
     

	//SKY BOX
     glPushMatrix();
	 glDisable(GL_LIGHTING);
	 glDisable(GL_LIGHT0);
     glTranslatef( _ship->getPositon().x+5000 , _ship->getPositon().y-5000 , _ship->getPositon().z -50000 );
	 IEntityManager::getInstance()->create_Sat_A();
     glEnable(GL_LIGHTING);
	 glEnable(GL_LIGHT0);
     glPopMatrix();
	 //end of SKY-BOX


	 //Planet - CIRYUS
	 glPushMatrix();
	 //glScalef(15,15,15);
	  glTranslatef(-60000,-1000,-10000);
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
	  glTranslatef(0,100,200);
	  IEntityManager::getInstance()->draw_colony_debris();
    glPopMatrix();
    // End unity
	
    
	//Nalanda
	glPushMatrix();
	  glTranslatef(0,0,2000000-1000);
	  IEntityManager::getInstance()->draw_nalanda();
	glPopMatrix();


	//Exter
	exterMin->drawExterminatore();
	//Exter end
	_ship->shipDraw();

	
	//test Code


	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glutSolidCube(50000);
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
     switch(key){

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

void levelTwo::timer_fn_game(int t)
{
      
	  // if(fire){pos_t += 0.2f*50;}
	   _ship->shipUpdate();

	   collisionManager->runCollisionEngine();

       Point eye(_ship->getPositon());
       Point at(_ship->getPositon() + _ship->getDirection());
       Vector up(_ship->getVertical());

		//Exterminator
	   exterMin->updateExterminatore();	
     	//Ent exter



      glLoadIdentity();
      gluLookAt(eye.x,eye.y,eye.z,
                at.x,at.y,at.z,
                up.i,up.j,up.k);
    
      glutPostRedisplay();
}



