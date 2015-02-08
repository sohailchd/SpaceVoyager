



#include "MenuScreen.h"
#include "GameStateManager.h"

double r_menu_cursor_x = 0.0;
double r_menu_cursor_y = 0.0;
double pos_menu_cursor_y = 0.119;
double cursor_shift = 0.000;
unsigned int cursor_on = 0;



void init()
{
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1.6,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt( 0.0,0.0,2.0,
               0.0,0.0,0.0,
               0.0,1.0,0.0
             );
}


double menu_bg[] = {0.2,0.4,0.8};
double c[] = {0.0,0.0,0.1};
double c_white[] = {1.0,0.9,1.0};
double c_azure[] = {0.2,0.4,0.8};

	
void  MenuScreen::display_screen()
{

    glClearColor(0.0,0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //int();

	



	glScaled(1,1,1);
	Render::getRenderInstance()->drawHudText(Point(-0.42,0.6,0.0),"  V O Y A G E R ",c_white);
   // Render::getRenderInstance()->drawHudText(Point(-0.5,0.6,0.0),"    --------------",c_white);
	Render::getRenderInstance()->drawSegment3d(Point(-0.55,0.55,0),Point(-0.1,0.55,0));
	Render::getRenderInstance()->drawSegment3d(Point(0.45,0.55,0),Point( 0.0,0.55,0));
	Render::getRenderInstance()->drawHudText(Point(-0.52,0.45,0.0),"    no man's space ",c_azure);
    
    
    //r->drawRect(Point(-0.3,0.2),0.45,0.4,0,menu_bg);
	glPushMatrix();
	glTranslatef(-0.5,0,0);
    Render::getRenderInstance()->drawHudText(Point(-0.2,0.1,0.0),"START",c_white);
    Render::getRenderInstance()->drawHudText(Point(-0.2,0.0,0.0),"EXIT",c_white);
    Render::getRenderInstance()->drawHudText(Point(-0.2,-0.1,0.0),"ABOUT",c_white);
    //r->drawHudText(b2Vec2(-0.2,-0.2),"About",c);
    


    /* Draw the cube  for selection.... */
    //glLoadIdentity();
	glPushMatrix();
    glTranslatef(-0.25, pos_menu_cursor_y - cursor_shift,0);
    glColor3f(0.8,0.8,0.8);
   // glRotatef(r_menu_cursor_x,1,0,0);
   // glRotatef(r_menu_cursor_y,0,1,0);
    glutSolidCube(0.03);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(0.04);
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(0.45, 0.55,0);
    glColor3f(0.8,0.8,0.8);
    glRotatef(r_menu_cursor_x,1,0,0);
    glRotatef(45,0,1,0);
    glutSolidCube(0.03);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(0.04);
	glPopMatrix();



	glPushMatrix();
	   glEnable(GL_BLEND);
	   glColor4f(0.2,0.2,0.6,0.4);
	   glTranslatef(-0.07, pos_menu_cursor_y - cursor_shift,0);
	   glScaled(1,0.5,1);
	   glutSolidCube(0.2);
	   glDisable(GL_BLEND);
	glPopMatrix();

	glPopMatrix();
}


void MenuScreen::idle_screen()
{
}

void MenuScreen::keyboard_screen(unsigned char& key , int& x , int& y)
{
    
    printf("%d\n",key);
    switch(_menu_current_state)
    {
        case _start:
           {
              if(key=='s'){
                 printf("%d",key);
                 cursor_shift = 0.100; 
                 _menu_current_state = _exit;
              }
              if(key==13)
              { 
				  GameStateManager::setState(GameStateManager::_inGame);
              }
              break;
           }
        case _exit:
           {
              if(key=='s'){
                 cursor_shift = 0.200; 
                 _menu_current_state = _about;
              }
              if(key=='w'){
                 cursor_shift = 0.000; 
                 _menu_current_state = _start;
              }
			  if(key==13)
			  {
				  exit(0);
			  }
              break;
           }
        case _about:
           {
              if(key=='w'){
                 cursor_shift = 0.100; 
                 _menu_current_state = _exit;
              }
              break;
           }
        default:
           break;   
    }

    glutPostRedisplay();    
}


void MenuScreen::loadObjects()
{

}


void MenuScreen::reshape(int& w , int& h)
{
        if(h==0){ h=1; }
        GLfloat aspect = (GLfloat)w / (GLfloat)h;
        
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w>=h){ gluOrtho2D(-1.0*aspect , 1.0*aspect , -1.0 , 1.0); }
        else { gluOrtho2D(-1.0 , 1.0 , -1.0 / aspect , 1.0 / aspect); }
	
}

void MenuScreen::timer_screen(int t)
{
   
     r_menu_cursor_x += 4;
     r_menu_cursor_y += 4;
	 
     glutPostRedisplay();
}





