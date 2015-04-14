#include "Cockpit.h"
#include <ctime>
#include "GameStateManager.h"
#include "XInputHandler.h"

double col_h[] = { 1.0, 1.0, 1.0 };
double col_hb[] = { 0.2, 0.4, 0.7 };
char locationTxt[100];
char timeElapsedStart[50];
char speedTxt[50];
char fps[50];
GLuint cockpitId;



Cockpit::Cockpit()
{
	dock_reading = 0;

}

void Cockpit::shipDataUpdate(GLfloat f , GLfloat u , GLfloat r , GLfloat  h , GLfloat spd)
{
	sForward = f;
	sUp = u;
	sRight = r;
	health = h;
	speed = spd*0.00077;
}


void Cockpit::create()
{
    cockpitId = glGenLists(1);
    glNewList(cockpitId, GL_COMPILE);
	 

	glEnable(GL_BLEND);
	//Render::getRenderInstance()->drawHudText12(Point(-0.9, 0.85, 0.2),"LOCATION:" , col_h);
	//Render::getRenderInstance()->drawHudText12(Point(-0.7, 0.01, 0.2),"[][][][][][][][][][][][][][][][][][][][]" , col_h);
	Render::getRenderInstance()->drawHudText12(Point(0.3, 0.85, 0.2),"SEQ:" , col_h);
	Render::getRenderInstance()->drawHudText18(Point(0.4, -0.90, 0.2), "-Voyager-rFx8080", col_h);
	
	Render::getRenderInstance()->drawHudText12(Point(-1.2, -0.80, 0.2),"min[-1000][------------------------------------- | -------------------------------------][1000]max ",col_h);
	//Render::getRenderInstance()->drawCircle(Point(-1.2, -0.80, 0.2),0.2);
  
    glColor3f(1.0, 1.0, 1.0);
    Render::getRenderInstance()->drawSegment3d(Point(-0.5, 0.0, 0.0), Point(0.5, 0.0, 0.0));
    Render::getRenderInstance()->drawSegment3d(Point(0.0, 0.3, 0.0), Point(0.0, -0.3, 0.0));
    glPushMatrix();
    glutWireCube(0.1);
	/*glColor4f(0.5,0.5,0.5,0.5);
	glutSolidSphere(0.05,60,60);*/
    glPopMatrix();


   
	glPushMatrix();

	glPushMatrix();
	glRotated(sForward.i,1,1,1);
	//Render::getRenderInstance()->drawHudText(Point(-0.55, 0.03, 0), "<",col_h);
    glTranslatef(-0.5f,0.05f,0.0f);
    glColor4f(0.2f,0.8f,0.2f,0.2f);
	glutSolidCube(0.05);
	glTranslatef(0.0f,-0.10f,0.0f);
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	//Render::getRenderInstance()->drawHudText(Point(0.45, 0.03, 0), ">", col_h);
    glTranslatef(0.5,0.05,0.0);
	glColor4f(0.2f,0.8f,0.2f,0.2f);
	glutSolidCube(0.05);
	glTranslatef(0.0f,-0.10f,0.0f);
	glutSolidCube(0.05);
	glPopMatrix();
    

	glPushMatrix();
	//Render::getRenderInstance()->drawHudText(Point(-0.05, 0.45, 0), "^", col_h);
    glTranslatef(0,0.3,0.0);
	glColor4f(0.4f,0.8f,0.6f,0.2f);
	glutSolidCube(0.05);
    glPopMatrix();
    
	glPushMatrix();
	Render::getRenderInstance()->drawHudText(Point(-0.05, -0.45, 0), "v", col_h);
    glTranslatef(0,-0.3,0.0);
	glColor4f(0.4f,0.8f,0.6f,0.6f);
	glutSolidCube(0.05);
    glPopMatrix();
    

	

	//****************** DARK SHADES
	glPushMatrix();
	glTranslatef(-1,-1,0.0);
	glColor4f(0.3,0.3,0.3,0.1);
	glScalef(10,0.4,1);
	glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,1,0.0);
	glColor4f(0.3,0.3,0.3,0.1);
	glScalef(10,0.4,1);
	glutSolidCube(1);
    glPopMatrix();
    //*********************************


	glDisable(GL_BLEND);
	glPopMatrix();

    glEndList();


	
    //printf("Cockpit POSITION updated.\n");
}


void Cockpit::getMechanicsOnScreen()
{

	
	//objective
    #pragma region controller_status
	//controler status
    if(XInputHandler::isConnected)
	{
		Render::getRenderInstance()->drawHudText10(Point(-0.9, -0.70, 0.2),"G-PAD:CONNECTED",col_h);
	}else
	{	
		Render::getRenderInstance()->drawHudText10(Point(-0.9, -0.70, 0.2),"G-PAD:DISCONNECTED",col_h);
	}
    #pragma endregion


    #pragma region _speedCube
	//speed cube
	glPushMatrix();
	glTranslatef(speed*0.00077, -0.77, 0.2);
	//glRotatef(speed_cube_x*GameStateManager::timeSinceStart,1,0,0);
	   glutSolidCube(0.025);
    glTranslatef(0.0, -0.04, 0.0);
	glutSolidCube(0.025);
    //glTranslatef(-speed*0.00077, -0.82, -0.2);
	glPopMatrix();

   #pragma endregion _speedCube

    #pragma region _health

	/*glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.82, -0.695, 0.2);
	glScalef(10,1.0f,1.0f);
	glutSolidCube(0.025);
	glScalef(1.0f,1.0f,1.0f);
	glPopMatrix();*/

	glPushMatrix();
    //Render::getRenderInstance()->drawHudText10(Point(0.6, -0.70, 0.195),"HEALTH:[                           ]",col_hb)
	Render::getRenderInstance()->drawHudText10(Point(0.6, -0.620, 0.195),  "HEALTH:[ | | | | | | | | | | | | | ]",col_h);;
	glTranslatef(0.82, -0.615, 0.2);
	glScalef(health,1.0f,1.0f);
	glutSolidCube(0.025);
	glScalef(1.0f,1.0f,1.0f);
	/*glTranslatef(0.05, 0, 0);
	glutSolidCube(0.025);
	*/
	/*for(GLfloat i=0.025f;i<0.25f;i+=0.025f)
		{
			glTranslatef(i, 0, 0);
			glutSolidCube(0.025);
			glTranslatef(-i, 0, 0);
		}*/
	glPopMatrix();

   #pragma endregion _health
 
	 
	drawObjective();


}


void Cockpit::drawObjective()
{

#pragma region numeric_info
	sprintf(locationTxt,"LOCATION: \n[X:%8.2f]\n[Y:%8.2f]\n[Z:%8.2f] ",position.x,position.y,position.z);
	Render::getRenderInstance()->drawHudText12(Point(-1.1, -0.90, 0.2),locationTxt,col_h);
	sprintf(timeElapsedStart,"Server Uptime: %3.0fmin %2.3fsec",GameStateManager::timeSinceStart*0.00001666666f,(GameStateManager::timeSinceStart*0.001)-((int)(GameStateManager::timeSinceStart*0.00001666666))*60);
	Render::getRenderInstance()->drawHudText12(Point(-1.05, 0.85, 0.2),timeElapsedStart,col_h);
	sprintf(speedTxt,"SPEED: %5.2f",speed);
	Render::getRenderInstance()->drawHudText18(Point(-0.3, -0.71, 0.2), speedTxt, col_h);
	sprintf(fps,"Engine: %3.3f",1000.0f/GameStateManager::deltaTime);
	Render::getRenderInstance()->drawHudText10(Point(-0.9, -0.60, 0.2),fps,col_h);
#pragma endregion

   #pragma region LOC_OBJ  
	Render::getRenderInstance()->drawHudText12(Point(0.3,-0.28,0.2),"OBJECTIVE",col_h);
	Render::getRenderInstance()->drawHudText12(Point(0.3,-0.32,0.2),"VOYAGER",col_h);
	Render::getRenderInstance()->drawHudText10(Point(0.7,-0.2,0.2),"DATE: 25-OCT-2154",col_h);


 #pragma endregion LOC_OBJ

#pragma region _dockStatus
	if(!isDocked)
	{
	 glPushMatrix();
     Render::getRenderInstance()->drawHudText10(Point(0.59, -0.590, 0.195),  "DOCKING:[ | | | | | | | | | | | | | ]",col_hb);;
	glTranslatef(0.82, -0.585, 0.2);
	glScalef(dock_reading,1.0f,1.0f);
	glutSolidCube(0.025);
	glScalef(1.0f,1.0f,1.0f);
	glPopMatrix();
	}
	else
	{
    glPushMatrix();
    Render::getRenderInstance()->drawHudText10(Point(0.59, -0.590, 0.195),  "DOCKING:[ | | | | | | | | | | | | | ]",col_h);;
	glTranslatef(0.82, -0.585, 0.2);
	glScalef(dock_reading,1.0f,1.0f);
	glutSolidCube(0.025);
	glScalef(1.0f,1.0f,1.0f);
	glPopMatrix();
	
	}
#pragma endregion _cockStatus

#pragma region locked_state
	if(isLocked)
	   {
		   Render::getRenderInstance()->drawHudText12(Point(-0.95, 0.4, 0.0),  "VOYAGER LOCKED",col_h);;
       }
#pragma endregion

	#pragma region _drawBG-CUBE
	
	glPushMatrix();
	glScalef(1.0f,1.0f,1.0f);
	glEnable(GL_BLEND);
	   glTranslatef(0.73,-0.4,0.2);
	     glColor4f(0.2f,0.2f,0.2f,0.4f);
	     glutSolidCube(0.5);
	   glTranslatef(-0.73,-0.4,-0.2);
	   glDisable(GL_BLEND);
	glPopMatrix();
#pragma endregion




}


void Cockpit::draw()
{


	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
      glDisable(GL_LIGHTING);
      glDisable(GL_LIGHT0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
	
	getMechanicsOnScreen();

	//glTranslated(sin(2.0*3.14526*GameStateManager::timeSinceLast),cos(2.0*314526*GameStateManager::timeSinceStart),0); /* Vibrator */
    glCallList(cockpitId);
    
	glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glPopMatrix();
	
	
	
    
}


