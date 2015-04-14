

#include "SplashScreen.h"
#include "GameStateManager.h"

double rotate_x = 0.0;
double rotate_y = 0.0;
double rotate_z = 0.0;


double blue_rect[] = {0.2,0.4,0.8};
bool logo_done = false;
double c_sc[] = {1.0,1.0,1.0};

SplashScreen::SplashScreen(){ }

void  SplashScreen::display_screen()
{
	Point missile_pos(0,0,0);
    double d = 0;
	//glClearColor(1.0,1.0,1.0,1.0);
 //   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         
	if(!logo_done)
	{
		
			glPushMatrix();
			glColor3f(0.2,0.4,0.6);     //
			glRotatef(rotate_x,1,0,1);
			glRotatef(rotate_y,0,1,0);
			glRotatef(rotate_z,0,1,0);
			//IEntityManager::getInstance()->draw_scavs(Point(0,0,0),0);
		    glutSolidCube(0.1);
			glColor3f(1.0,1.0,1.0);   //
			glutWireCube(0.2);
			glPopMatrix();
		////////////////////////////
		  
		
		////////////////////////////
			glPushMatrix();
			glEnable(GL_BLEND);
			glColor4f(0.2,0.2,0.2,0.5);  //
			glScalef(4,0.5,1);
			glTranslatef(0,0.1,-1);
			glutSolidCube(1);
			glDisable(GL_BLEND);
			glPopMatrix(); 


			/*glPushMatrix();
			glEnable(GL_BLEND);
			glColor4f(0.2,0.2,0.2,0.5);
			glTranslatef(0.93,-0.35,-1);
		    glScalef(2,0.5,1);
			glutSolidCube(0.5);
			glDisable(GL_BLEND);
			glPopMatrix();*/

			glPushMatrix(); 
			glLoadIdentity();
			Render::getRenderInstance()->drawHudText(Point(0.2,-0.3,0.0),"#INCLUDE <studio>",c_sc);
			Render::getRenderInstance()->drawHudText(Point(0.2,-0.4,0.0),"Presents",c_sc);
			glPopMatrix();


    }
	else
	{
		glPushMatrix();
		glLoadIdentity();
		glScaled(1,2,1);
		Render::getRenderInstance()->drawHudText(Point(-0.5,0.,0.0),"V   O   Y   A   G   E   R",c_sc);
		glPopMatrix();
	}


}


void SplashScreen::idle_screen()
{
}

void SplashScreen::keyboard_screen(unsigned char key , int x , int y)
{
     
}



void SplashScreen::reshape(int& w , int& h)
{
        if(h==0){ h=1; }
        GLfloat aspect = (GLfloat)w / (GLfloat)h;
        
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w>=h){ gluOrtho2D(-1.0*aspect , 1.0*aspect , -1.0 , 1.0); }
        else { gluOrtho2D(-1.0 , 1.0 , -1.0 / aspect , 1.0 / aspect); }
        


}

void SplashScreen::loadObjects()
{

}

void SplashScreen::timer_screen(int t)
{

     if(GameStateManager::timeSinceStart/1000 > 5)
     {
		 GameStateManager::getInstance()->setGameState(_menu);
     }
	 if(GameStateManager::timeSinceStart/1000 > 2)
	 {
		 logo_done = true;
	 }
	      
     rotate_x += 1.0*2;
   /*  rotate_z += 1.0*2;
	 rotate_y += 1.0*2;*/
}


