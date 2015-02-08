#include "Cockpit.h"


double col_h[] = { 1.0, 1.0, 1.0 };
char* speedTxt;
GLuint cockpitId;

Cockpit::Cockpit()
{
	//create(Render::getRenderInstance(),0.0f);
}


void Cockpit::create()
{
    cockpitId = glGenLists(1);
    glNewList(cockpitId, GL_COMPILE);
	 
	speedTxt = "OBJECTIVE: ISFAHANA";

	glEnable(GL_BLEND);

	Render::getRenderInstance()->drawHudText10(Point(0.3, 0.85, 0.2), speedTxt , col_h);
	Render::getRenderInstance()->drawHudText18(Point(0.4, -0.90, 0.2), "-Voyager-rFx8080", col_h);
	Render::getRenderInstance()->drawHudText(Point(-0.4, -0.90, 0.2),"SPEED-00x0",col_h);


  
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
	Render::getRenderInstance()->drawHudText(Point(-0.55, 0.03, 0), "<",col_h);
    glTranslatef(-0.5,0.05,0.0);
    glColor4f(0.2,0.8,0.2,0.2);
	glutSolidCube(0.05);
    glPopMatrix();

	glPushMatrix();
	Render::getRenderInstance()->drawHudText(Point(0.45, 0.03, 0), ">", col_h);
    glTranslatef(0.5,0.05,0.0);
	glColor4f(0.2,0.8,0.2,0.2);
	 glutSolidCube(0.05);
    glPopMatrix();
    

	glPushMatrix();
	Render::getRenderInstance()->drawHudText(Point(-0.05, 0.45, 0), "^", col_h);
    glTranslatef(0,0.3,0.0);
	glColor4f(0.2,0.8,0.2,0.2);
	glutSolidCube(0.05);
    glPopMatrix();
    
	glPushMatrix();
	Render::getRenderInstance()->drawHudText(Point(-0.05, -0.45, 0), "v", col_h);
    glTranslatef(0,-0.3,0.0);
	glColor4f(0.2,0.8,0.2,0.2);
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
    glCallList(cockpitId);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glPopMatrix();
	

	
    
}

//
//void Cockpit::printSpeed()
//{
//  r->drawHudText(Point(0.4, -0.90, 0.2), "-Voyager-rFx8080", col_h);
//  
//}
//
