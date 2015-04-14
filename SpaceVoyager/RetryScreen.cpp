

#include "RetryScreen.h"
#include "GameStateManager.h"


        double WHITE_COLOR[]        = { 0.9 , 0.9 , 0.9 };
        double BLACK_DARK_COLOR[]   = { 0.0 , 0.0 , 0.0 };
        double BLUE_AZUER_COLOR[]   = { 0.2 , 0.4 , 0.6 };
        double GREEN_AZURE_COLOR[]  = { 0.32, 0.8 , 0.5 } ; 


RetryScreen::RetryScreen()
{
	sceneInit = false;
}

RetryScreen::~RetryScreen()
{}

void  RetryScreen::display_screen()
{
	glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if(!sceneInit)
	{
		int w = glutGet(GLUT_WINDOW_WIDTH);
	    int h = glutGet(GLUT_WINDOW_HEIGHT);
		reshape(w,h);
		sceneInit = true;
	}

#pragma region Panel
	glScaled(1,1,1);
	Render::getRenderInstance()->drawHudText(Point(-0.42,0.62,0.0),"  V O Y A G E R ",WHITE_COLOR);
	Render::getRenderInstance()->drawSegment3d(Point(-0.55,0.55,0),Point(-0.1,0.55,0));
	Render::getRenderInstance()->drawSegment3d(Point(0.45,0.55,0),Point( 0.0,0.55,0));
	Render::getRenderInstance()->drawHudText(Point(-0.52,0.45,0.0),"    no man's space ",BLUE_AZUER_COLOR);
    
		//Under voyager
	glPushMatrix();//
    glTranslatef(-0.05f, 0.55f,0.0f);
    glColor3f(0.2,0.4,0.8);
    glRotatef(2.0f,1,0,0);
    glRotatef(45,0,1,0);
    glutSolidCube(0.03);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(0.04);
	glPopMatrix();//
#pragma  endregion 

	 glutPostRedisplay();
}


void RetryScreen::idle_screen()
{
}

void RetryScreen::keyboard_screen(unsigned char& key , int& x , int& y)
{
	if(key=='z')
	{ GameStateManager::getInstance()->setGameState(_menu); }
}

void RetryScreen::keyboard_screen_sp(int& key,int& x,int& y)
{
	if(key==27){ GameStateManager::getInstance()->setGameState(_menu); }
}

void RetryScreen::reshape(int& w , int& h)
{
        if(h==0){ h=1; }
        GLfloat aspect = (GLfloat)w / (GLfloat)h;
        


        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w>=h){ gluOrtho2D(-1.0*aspect , 1.0*aspect , -1.0 , 1.0); }
        else { gluOrtho2D(-1.0 , 1.0 , -1.0 / aspect , 1.0 / aspect); }
        


}

void RetryScreen::loadObjects()
{

}

void RetryScreen::timer_screen(int t)
{

}


