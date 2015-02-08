
#define _CRTDEBUG_MAP_ALLOC

#include "MasterHeader.h"
#include "Game.h"
#include "GameStateManager.h"


#include <thread>


#ifdef _DEBUG   
#ifndef DBG_NEW      
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )     
#define new DBG_NEW   
#endif
#endif




const unsigned int FPS = 60;




void display_cb()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      

    Game::getInstance()->display_fn_game();

    glFlush();
    glutSwapBuffers();

}


void keyboard_cb(unsigned char key , int x , int y)
{
     Game::getInstance()->keyboard_fn_game(key,x,y);
}

void special_cb(int key,int x , int y)
{
     Game::getInstance()->keyboard_fn_game_sp(key,x,y);
}

void idle_cb()
{
     Game::getInstance()->idle_fn_game();
}


void joystick_fn(unsigned int buttons , int xaxis , int yaxis , int zaxis)
{
     /*   if(buttons && GLUT_JOYSTICK_BUTTON_A)
        {
          printf("\n JS Button : %d  \n",buttons);
          printf("\n JS Xaxis :  %d \n",xaxis);
        }*/
        
}
void timer_cb(int t)
{
        Game::getInstance()->timer_fn_game(t);
       // glutPostRedisplay();
       
		GameStateManager::timeSinceStart = (float) glutGet(GLUT_ELAPSED_TIME);
        GameStateManager::deltaTime = GameStateManager::timeSinceStart - GameStateManager::timeSinceLast;
        GameStateManager::timeSinceLast = GameStateManager::timeSinceStart;
       
		printf("----FPS : %f \n",1000/GameStateManager::deltaTime);
        
		if(1.0f*1000/GameStateManager::deltaTime > 30)
		{
			//exit(1);
		}
		glutPostRedisplay();
        glutTimerFunc(1000/FPS,timer_cb,0);
		

}



void reshape(int w, int h)
{

	Game::getInstance()->reshape(w,h);

}


void jsInfo()
{/*
      printf(" js - %i   buttons  %i - axes - %i " , glutDeviceGet(GLUT_HAS_JOYSTICK) ,
                                                       glutDeviceGet(GLUT_JOYSTICK_BUTTONS),
                                                       glutDeviceGet(GLUT_JOYSTICK_AXES) 
                                                       );*/
}




int main(int argv , char* args[]){

	  _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
      _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);


      glutInit(&argv,args);
	  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);
      glutInitWindowPosition(50,100);
      glutInitWindowSize(1200,700);
      glutCreateWindow("TheVoyager");
      glEnable(GL_DEPTH_TEST);
	  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  

	   

	  //glutFullScreen();
      glutDisplayFunc(display_cb);
      glutSpecialFunc(special_cb);
      glutIdleFunc(idle_cb);
      glutKeyboardFunc(keyboard_cb);
      //glutJoystickFunc(joystick_fn,200);
      glutReshapeFunc(reshape);
      glutTimerFunc(1000/FPS,timer_cb,0);
      
      jsInfo();
	  glutMainLoop();

	return 0;
}
