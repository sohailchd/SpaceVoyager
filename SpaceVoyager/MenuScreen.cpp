



#include "MenuScreen.h"
#include "GameStateManager.h"
#include "XInputHandler.h"

double r_menu_cursor_x = 0.0;
double r_menu_cursor_y = 0.0;
double pos_menu_cursor_y = 0.119;
double cursor_shift = 0.000;
unsigned int cursor_on = 0;


void handleGpad()
{

}

MenuScreen::MenuScreen()
	{
      		_menu_current_state = _start;
			isLoading = false;
			loadTimer = 0.0f;
      	}

 MenuScreen::~MenuScreen(){}


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
double c_white[] = {0.9,0.9,0.9};
double c_azure[] = {0.2,0.4,0.8};


void MenuScreen::draw_light_shade()
{
	glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //int();

	

		

	glScaled(1,1,1);
	Render::getRenderInstance()->drawHudText(Point(-0.42,0.62,0.0),"  V O Y A G E R ",c_white);
	Render::getRenderInstance()->drawSegment3d(Point(-0.55,0.55,0),Point(-0.1,0.55,0));
	Render::getRenderInstance()->drawSegment3d(Point(0.45,0.55,0),Point( 0.0,0.55,0));
	Render::getRenderInstance()->drawHudText(Point(-0.52,0.45,0.0),"    no man's space ",c_azure);
    
		//Under voyager
	glPushMatrix();//
    glTranslatef(-0.05f, 0.55f+0.5f,0.0f);
    glColor3f(0.2,0.4,0.8);
    glRotatef(r_menu_cursor_x,1,0,0);
    glRotatef(45,0,1,0);
    glutSolidCube(0.03);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(0.04);
	glPopMatrix();//


    if(!isLoading)
	{
    //r->drawRect(Point(-0.3,0.2),0.45,0.4,0,menu_bg);
	glPushMatrix();
	glTranslatef(0.0f,-0.5f,0.0f);
    Render::getRenderInstance()->drawHudText(Point(-0.2,0.1,0.0),"START",c_white);
    Render::getRenderInstance()->drawHudText(Point(-0.2,0.0,0.0),"EXIT",c_white);
    Render::getRenderInstance()->drawHudText(Point(-0.2,-0.1,0.0),"ABOUT",c_white);
    //r->drawHudText(b2Vec2(-0.2,-0.2),"About",c);
    


    /* Draw the cube  for selection.... */
    //glLoadIdentity();
	
	glPushMatrix();//
    glTranslatef(-0.2, pos_menu_cursor_y - cursor_shift,0);
    glColor3f(0.8,0.8,0.8);
   // glRotatef(r_menu_cursor_x,1,0,0);
   // glRotatef(r_menu_cursor_y,0,1,0);
    glutSolidCube(0.05);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(0.04);
	glTranslatef(0.2, -(pos_menu_cursor_y - cursor_shift),0);
	glPopMatrix();//
	
	//Under voyager
	glPushMatrix();//
    glTranslatef(-0.05f, 0.55f+0.5f,0.0f);
    glColor3f(0.2,0.4,0.8);
    glRotatef(r_menu_cursor_x,1,0,0);
    glRotatef(45,0,1,0);
    glutSolidCube(0.03);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(0.04);
	glPopMatrix();//



	glPushMatrix();//
	   glEnable(GL_BLEND);
	   glColor4f(0.1,0.1,0.1,0.5);
	   glTranslatef(-0.07, pos_menu_cursor_y - cursor_shift,0);
	   glScaled(1,0.5,1);
	   glutSolidCube(0.2);
	   glDisable(GL_BLEND);
	glPopMatrix();//

	glPopMatrix();


	glPushMatrix();
			glEnable(GL_BLEND);
			glColor4f(0.1,0.1,0.1,0.5);  //
			glScalef(4,0.5,1);
			glTranslatef(0,1,-1);
			glutSolidCube(1);
			glDisable(GL_BLEND);
	glPopMatrix(); 

	}//if

	else
	{
			glClearColor(0.0,0.0,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

    glScaled(1,1,1);
	Render::getRenderInstance()->drawHudText(Point(-0.42,0.62,0.0),"  V O Y A G E R ",c_white);
	Render::getRenderInstance()->drawSegment3d(Point(-0.55,0.55,0),Point(-0.1,0.55,0));
	Render::getRenderInstance()->drawSegment3d(Point(0.45,0.55,0),Point( 0.0,0.55,0));
	Render::getRenderInstance()->drawHudText(Point(-0.52,0.45,0.0),"    no man's space ",c_azure);
   
	//under voyager
	glPushMatrix();//
    glTranslatef(-0.05f, 0.55f+0.5f,0.0f);
    glColor3f(0.2,0.4,0.8);
    glRotatef(r_menu_cursor_x,1,0,0);
    glRotatef(45,0,1,0);
    glutSolidCube(0.03);
    glColor3f(1.0,1.0,1.0);
    glutWireCube(0.04);
	glPopMatrix();//



		glTranslatef(0.0f,-0.55f,0.0f);
		Render::getRenderInstance()->drawHudText18(Point(-0.22,0.0,0.0),"Please wait",c_white);
		Render::getRenderInstance()->drawHudText18(Point(-0.32,-0.1,0.0),"Loading in progress",c_white);
		glTranslatef(0.0f,0.5f,0.0f);

			glPushMatrix();
			glEnable(GL_BLEND);
			glColor4f(0.1,0.1,0.1,0.5);  //
			glScalef(4,0.5,1);
			glTranslatef(0.0f,1.1f,-1.0f);
			glutSolidCube(1);
			glDisable(GL_BLEND);
	        glPopMatrix(); 

			
	}

	Render::getRenderInstance()->drawHudText12(Point(0.32,-0.9,0.0),"ver-0.9[GNU-GPL]",c_white);
}

	
void  MenuScreen::display_screen()
{


	draw_light_shade();

}


void MenuScreen::idle_screen()
{


}


void MenuScreen::keyboard_screen_sp(int& key,int& x,int& y)
{
	

	switch(_menu_current_state)
    {
        case _start:
           {
			   if(key== GLUT_KEY_DOWN ){
                 printf("%d",key);
                 cursor_shift = 0.100; 
                 _menu_current_state = _exit;
              }
              if(key==13)
              { 
				    isLoading=true;
				    //display_screen();
				
				  //GameStateManager::setState(GameStateManager::_inGame);
					loadTimer = GameStateManager::timeSinceStart;
              }
              break;
           }
        case _exit:
           {
              if(key== GLUT_KEY_DOWN){
                 cursor_shift = 0.200; 
                 _menu_current_state = _about;
              }
              if(key==GLUT_KEY_UP){
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
              if(key==GLUT_KEY_UP){
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
				   this->isLoading=true;
				   loadTimer = GameStateManager::timeSinceLast;
				 // GameStateManager::setState(GameStateManager::_inGame);
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
	 
	 if((GameStateManager::timeSinceStart -  loadTimer > 2000.00f) && isLoading )
	{
		GameStateManager::setState(GameStateManager::_inGame);
	}


	 //Handle GPAd
	 switch(_menu_current_state)
    {
        case _start:
           {
			   if( XInputHandler::getInstance()->isDigitalButtonPressedOnce('D') ){
                 
                 cursor_shift = 0.100; 
                 _menu_current_state = _exit;
              }
			   if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('A'))
              { 
				    isLoading=true;
				    //display_screen();
				
				  //GameStateManager::setState(GameStateManager::_inGame);
					loadTimer = GameStateManager::timeSinceStart;
              }
              break;
           }
        case _exit:
           {
			   if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('D')){
                 cursor_shift = 0.200; 
                 _menu_current_state = _about;
              }
			   if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('U')){
                 cursor_shift = 0.000; 
                 _menu_current_state = _start;
              }
			  if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('A'))
			  {
				  exit(0);
			  }
              break;
           }
        case _about:
           {
			   if(XInputHandler::getInstance()->isDigitalButtonPressedOnce('U')){
                 cursor_shift = 0.100; 
                 _menu_current_state = _exit;
              }
              break;
           }
        default:
           break;   
    }
	 // end the Gpadhandler
     glutPostRedisplay();  


}





