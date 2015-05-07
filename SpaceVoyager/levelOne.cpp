

#include "levelOne.h"





bool initlevelone = false;
GLdouble night_sky_rot = 0.0f;





void levelOne::initScene()
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
  GLfloat white[] = { 1.0, 1.0, 1.0, 1.0};
  GLfloat direction[] = { 0.2, 0.0, 10.5,0.0};

  //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
  //glMaterialf(GL_FRONT, GL_SHININESS, 30);
  glLightfv(GL_LIGHT0, GL_AMBIENT , white);
  glLightfv(GL_LIGHT0, GL_DIFFUSE , white);
 // glLightfv(GL_LIGHT0, GL_SPECULAR , white);
  glLightfv(GL_LIGHT0, GL_POSITION , direction);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

 
  _ship->init_ship();
  _ship->setSpeed(0);
   initlevelone = true;
}


levelOne::levelOne()
{
	_ship = new Ship();

}

levelOne::~levelOne()
{

}

void levelOne::display_fn_game()
{
	if(!initlevelone)
	{
		initScene();
	}


	//SKY BOX
     glPushMatrix();
	 glDisable(GL_LIGHTING);
	 glDisable(GL_LIGHT0);
     glTranslatef( _ship->getPositon().x+5000 , _ship->getPositon().y-5000 , _ship->getPositon().z -50000 );
	 glRotated(GameStateManager::timeSinceStart/1000.0,0.2,0.5,1);
	 IEntityManager::getInstance()->create_Sat_A();
     glEnable(GL_LIGHTING);
	 glEnable(GL_LIGHT0);
     glPopMatrix();
	 //end of SKY-BOX

	//Planet - CIRYUS
	 glPushMatrix();
	 //glScalef(15,15,15);
	  glTranslatef(-660000,-10000,-100000);
	   glRotated(GameStateManager::timeSinceStart*2/1000.0,0.2,0.5,1);
      IEntityManager::getInstance()->create_planet();
	   glTranslatef(60000,1000,10000);
	 glPopMatrix();
	//Planet - end

	_ship->shipDraw();
}

void levelOne::idle_fn_game()
{
     
}

void levelOne::keyboard_fn_game(unsigned char& key,int& x, int& y)
{ 
    const double deltaSpeed = 10.0;
    const double angle      = 0.02;
   
  /*  switch(key)
    {
          case 'w': _ship->setSpeed(_ship->getSpeed() + deltaSpeed);  break;
          case 's': _ship->setSpeed(_ship->getSpeed() - deltaSpeed);  break;
          case 'a': _ship->roll(angle);                              break;
          case 'd': _ship->roll(-angle);                             break;
          case 'm': _ship->slide(1);                                 break;
          case 'n': _ship->slide(-1);                                break;
          case 'r': _ship->teleport(Point(0,0,10000));               break;
          case 27: exit(0);                                         break;      
         default: 
			 break;

    }*/


	if(key=='w'){ _ship->setSpeed(_ship->getSpeed()+deltaSpeed);	}
	if(key=='s'){ _ship->setSpeed(_ship->getSpeed()-deltaSpeed);	}
    if(key=='a'){ _ship->roll(angle);	}
	if(key=='d'){ _ship->roll(-angle);	}
	

     glutPostRedisplay();
}


void levelOne::special_fn_game(int& key , int& x, int& y)
{ 
    float fraction = 0.1f;
    double angle   = 0.02;
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


void levelOne::timer_fn_game(int t)
{
       
	_ship->shipUpdate();
      
	  Point eye(_ship->getPositon());
      Point at(_ship->getPositon() + _ship->getDirection());
      Vector up(_ship->getVertical());
      glLoadIdentity();
      
      gluLookAt(eye.x,eye.y,eye.z,
                at.x,at.y,at.z,
                up.i,up.j,up.k);
      glutPostRedisplay();

}