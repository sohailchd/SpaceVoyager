#include "IEntityManager.h"

GLfloat origin[3] = {100.0,100.0,100.0};
GLfloat rot_x = 0.0f;

	

IEntityManager* IEntityManager::entityManagerInstance = NULL;

IEntityManager* IEntityManager::getInstance()
{
	if(entityManagerInstance==NULL){
		entityManagerInstance = new IEntityManager();
	}
	return entityManagerInstance;
}





void  IEntityManager::init_IEntityManager()
{


	char sname[50];
	//glNewList(gen_list+ENTITY,GL_COMPILE);

	glEnable(GL_NORMALIZE);
	quad_iem = gluNewQuadric();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(MAX_NO_TEXTURE, texture_ids);
	for (GLuint i = 0; i<MAX_NO_TEXTURE; i++)
	{
		sprintf(sname, "../images/x_%d.jpg", i + 1);

		texture_ids[i] = SOIL_load_OGL_texture(
			sname,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_POWER_OF_TWO
			| SOIL_FLAG_MIPMAPS
			//SOIL_FLAG_MIPMAPS
			//| SOIL_FLAG_MULTIPLY_ALPHA
			//| SOIL_FLAG_COMPRESS_TO_DXT
			| SOIL_FLAG_DDS_LOAD_DIRECT
			//| SOIL_FLAG_NTSC_SAFE_RGB
			//| SOIL_FLAG_CoCg_Y
			);
		if (texture_ids[i] < 0)
			printf("Error in loading %s\n", sname);
	}
	rotor_val = 0.0f;
	printf("IEntityManager init func called\n");
}
//**********************************************




//*********************************************
void IEntityManager::create_Sat_A()
{
	
	glPushMatrix();
	//draw_cube(3500000, 3500000,3500000,0);
    draw_sphere(3500000,0);
	glPopMatrix();
	
}

void IEntityManager::create_Sat_B()
{
	draw_cube(10, 10, 10, 6);	
}

void IEntityManager::create_Sat_C()
{

	GLfloat seg_sat = 72.0f;
	GLfloat inc = 2 * 3.14256 / seg_sat;
	double theta = 0.0;
	rot_x += 5.1;

	glPushMatrix();
	    draw_cube(10,10,10,1);
		Render::getRenderInstance()->drawSegment3d(Point(0.0, 0.0, 0.0), Point(0.0 + 100.0 - 1.0, 0.0, 0.0 + 100.0 + 0.0));
		glTranslatef(100-1.0,0.0,100.0+0.0);
		draw_cube(10,10,10,1);
		glTranslatef(100+1.0,0,100.0+0.0);
		Render::getRenderInstance()->drawSegment3d(Point(origin[0], origin[1], origin[2]), Point(origin[0] + 100.0 + 1.0, origin[1], origin[2] + 100.0 + 0.0));
		draw_cube(10,10,10,6);
		glRotatef(90,1.0,0.0,0.0);
		glRotatef(rot_x,0,1,0);
		draw_plane(50,100,1);
	glPopMatrix();

	glPushMatrix();
	Point center(0.0,0.0,0.0);
	//glTranslatef(-400.0,0.0,0.0);

	for (GLfloat i = 0.0; i < seg_sat; i++)
	{
	        Point cent = center + Vector(cosf(theta),sinf(theta),center.z) * 950;
         	glTranslatef(cent.x,cent.y,cent.z);
		draw_sphere(10,6);
		theta += seg_sat;
	}
	glTranslatef(0.0,0.0,0.0);
	glRotatef(rot_x, 0, 1, 0);    
	glPopMatrix();


	glPopMatrix();
	     glTranslatef(100, 200, -100);
	
	     draw_plane(50, 100, 1);
	glPushMatrix();

}






void IEntityManager::draw_sphere(int r, int tex)
{	

	glPushMatrix();
	glScaled(r,r,r);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	//glRotatef(rot_x/10.0,0.0,0.0,1.0);
	//glColor3f(0.8, 0.4, 0.2);
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_ids[tex]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quad_iem, 1);
		gluSphere(quad_iem,1,36,36);
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

   glScaled(1,1,1);

}

void IEntityManager::draw_sphere_parallel(int r,  char* fileNameConstant)
{	

	//glPushMatrix();
	//glScaled(r,r,r);
	//glRotatef(90, 1.0f, 0.0f, 0.0f);
	//glRotatef(90, 0.0f, 0.0f, 1.0f);
	////glRotatef(rot_x/10.0,0.0,0.0,1.0);
	////glColor3f(0.8, 0.4, 0.2);
	//    glEnable(GL_TEXTURE_2D);
	//	glBindTexture(GL_TEXTURE_2D, GameStateManager::_tTextureLoader[fileNameConstant]);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//	gluQuadricTexture(GameStateManager::quadMaster, 1);
	//	gluSphere(quad_iem,1,36,36);
	//    glDisable(GL_TEXTURE_2D);
 //   glPopMatrix();

 //  glScaled(1,1,1);

}


void IEntityManager::create_planet()
{
	glScalef(4,4,4);
    glScalef(15,15,15);
	draw_sphere(10000, 7);
	/*if(GameStateManager::_tTextureLoader[cyrus]!=NULL){
	draw_sphere_parallel(10000,cyrus);
	}*/
	glScaled(1,1,1);
}
void IEntityManager::create_planet_moon()
{
    glScalef(15,15,15);
	draw_sphere(10000, 22);
	/*if(GameStateManager::_tTextureLoader[cyrus]!=NULL){
	draw_sphere_parallel(10000,cyrus);
	}*/
	glScaled(1,1,1);
}


void IEntityManager::draw_plane(GLdouble w, GLdouble h, int tex)
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(2, 2, 2);
	glBindTexture(GL_TEXTURE_2D, texture_ids[tex]);
	glScaled(w, h,1);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glScaled(1,1,1);
	glPopMatrix();

}


void IEntityManager::draw_cube(GLdouble w, GLdouble h, GLdouble l, int tex_index)
{

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(2, 2, 2);
	glBindTexture(GL_TEXTURE_2D, texture_ids[tex_index]);
	glScaled(w, h, l);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	glBegin(GL_QUADS);

	// Back Face
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
	glBegin(GL_QUADS);

	// Top Face
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();
	glBegin(GL_QUADS);

	// Bottom Face
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
	glBegin(GL_QUADS);

	// Right face
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
	glBegin(GL_QUADS);

	// Left Face
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glScaled(1,1,1);
	glPopMatrix();
	//glutSwapBuffers();
}



void IEntityManager::create_genesis(Point* at)
{
    // glTranslatef(at->x,at->y,at->z);
     glPushMatrix();
	 glColor3f(0.2,0.6,0.6);
           glDisable(GL_LIGHTING);
           glDisable(GL_LIGHT0);
           //glTranslatef(at->x,at->y,at->z);
           glutSolidCube(50);
		   Render::getRenderInstance()->drawSegment3d(Point(at->x,at->y,at->z),Point(at->x,at->y+20,at->z));
              glTranslatef(at->x,at->y+20,at->z);
           glutSolidCube(1);
           glEnable(GL_LIGHTING);
           glEnable(GL_LIGHT0);           
     glPopMatrix();
         
}


Point missile_pos ;
void IEntityManager::draw_scavs(Point& p , GLfloat d)
{

 missile_pos = p;

 glPushMatrix();

    glScaled(1,1,1);
	
	//FRONT-FACE
	glPushMatrix();
		glPushMatrix();
	    glTranslatef(missile_pos.x-d,missile_pos.y+d,missile_pos.z);
    	glutSolidCube(20);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(missile_pos.x+22-d,missile_pos.y-d,missile_pos.z);
		glutSolidCube(20);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(missile_pos.x+d,missile_pos.y+22-d,missile_pos.z);
		glutSolidCube(20);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(missile_pos.x+22+d,missile_pos.y+22-d,missile_pos.z);
		glutSolidCube(20);
		glPopMatrix();
	glPopMatrix();


	//2nd
	glPushMatrix();
		glPushMatrix();
	    glTranslatef(missile_pos.x-d,missile_pos.y+d,missile_pos.z+22-d);
    	glutSolidCube(20);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(missile_pos.x+22-d,missile_pos.y-d,missile_pos.z+22-d);
		glutSolidCube(20);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(missile_pos.x+d,missile_pos.y+22-d,missile_pos.z+22-d);
		glutSolidCube(20);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(missile_pos.x+22+d,missile_pos.y+22+d,missile_pos.z+22-d);
		glutSolidCube(20);
		glPopMatrix();
	glPopMatrix();


  glPopMatrix();
}


// UNITY - DOCK
void IEntityManager::draw_colony_debris(GLfloat d)
{
	GLfloat seg_sat = 6.0f;
	GLfloat inc = 2 * 3.14256 / seg_sat;
	double theta = 0.0;
	rotor_val+= 0.1f;

	glRotatef(0,1,1,1);


	glPushMatrix();
	glScaled(1000,1000,1000);

	glPushMatrix();
	//glScaled(1000,1000,1000);

	glutSolidSphere(2,100,10);
	glutSolidTorus(2,20,100,100);
	glutWireTorus(2.2,20,100,100);

	//*************************** 1 - ONE - A ****************************
	glPushMatrix();
	glTranslatef(0,0,15);

	for(GLdouble z=-1.5;z>=-38.5;z-=4.5){
    glPushMatrix();
	glTranslatef(-1,-1,z);
	glScaled(0.1,0.1,0.05);
	draw_scavs(Point(0,0,0),d);
	glTranslatef(-60,-1,0);
	draw_scavs(Point(0,0,0),d);
	glPopMatrix();
	}
	//glTranslatef(0,0,-50);
	glPopMatrix();
	//************************************** END 1 - ONE - A ********************

	////*************************** 1 - ONE - B
	//glPushMatrix();
	//glTranslatef(0,0,15);
	////glutSolidTorus(1,1.5,100,100);
	//for(GLdouble z=-1.5;z>=-38.5;z-=4.5){
 //   glPushMatrix();
	//glTranslatef(-10,-1,z);
	//glScaled(0.1,0.1,0.05);
	//draw_scavs(Point(0,0,0),0);
	//  ///*glDisable(GL_LIGHTING);
 //  //   glDisable(GL_LIGHT0);
	//  //glEnable(GL_BLEND);
	///*  glColor4f(0.2,0.4,0.8,0.8);
	//  glutSolidSphere(20,100,100);*/
	///*  glEnable(GL_LIGHTING);
	//  glEnable(GL_LIGHT0);
	//  glDisable(GL_BLEND);*/
	//glPopMatrix();
	//
	//}
	//glTranslatef(0,0,-50);
	//glPopMatrix();
	////************************************** END 1 - ONE -B ********************


	glPushMatrix();
	glTranslatef(0,15,-15);
	//glutSolidTorus(1,1.5,100,100);
	for(GLdouble z=28.5;z>=-28.5;z-=5){
    glPushMatrix();
	glTranslatef(-1,z,-1);
	//glRotatef(rotor_val,0,0,1);
	glScaled(0.1,0.1,0.05);
	draw_scavs(Point(0,0,0),d);
	glPopMatrix();	
	}
	//glTranslatef(0,0,+15);
	glPopMatrix();

	
	glPushMatrix();
	glRotatef(90,0,0,1);
	for(GLdouble z=28.5;z>=-28.5;z-=5){
    glPushMatrix();
	glTranslatef(-1,z, 16);
	glRotatef(rotor_val,0,0,1);
	glScaled(0.1,0.1,0.05);
	draw_scavs(Point(0,0,0),d);
	glPopMatrix();	
	}
	//glTranslatef(0,0,-50);
	glPopMatrix();

	/////
	//glPushMatrix();
	//glTranslatef(0,0,15);
	////glutSolidTorus(1,1.5,100,100);
	//for(GLdouble z=28.5;z>=-28.5;z-=5){
 //   glPushMatrix();
	//glTranslatef(1,z,-24);
	//glRotatef(rotor_val,0,0,1);
	//glScaled(0.1,0.1,0.05);
	//draw_scavs(Point(0,0,0),0);
	//glPopMatrix();	
	//}
	//glTranslatef(0,0,-50);
	//glPopMatrix();

	//
	//glPushMatrix();
	//glRotatef(90,0,0,1);
	//for(GLdouble z=28.5;z>=-28.5;z-=5   ){
 //   glPushMatrix();
	//glTranslatef(1,z, -25);
	//glRotatef(rotor_val,0,0,1);
	//glScaled(0.1,0.1,0.05);
	//draw_scavs(Point(0,0,0),0);
	//glPopMatrix();	
	//}
	//glTranslatef(0,0,-50);
	//glPopMatrix();
    //////////////////





	glPushMatrix();
	glScaled(1,1,1);
	//draw_scavs(Point(0.0,0.0,0.0),0);
	Point center(0.0,0.0,0.0);
	glRotatef(rotor_val,0,0,1);
	for (GLfloat i = 0.0; i <= seg_sat; i++)
	{
	        Point cent = center + Vector(cosf(theta),sinf(theta),center.z) * 20;
			Render::getRenderInstance()->drawSegment3d(center,cent);
			theta += inc;
	}
	glPopMatrix();

	glPopMatrix();

	glTranslatef(0,0,-50);
	
	 
	/////////////   CYLINDER  /////////////

	//glPushMatrix();
	//glRotatef(90,1,0,0);
	//glTranslatef(0,+30,30);
	//for(GLfloat i=0 ; i<20;i+=2)
	//{
	//	glTranslatef(0,0,i);
	//    glutSolidCylinder(10,1,50,10);
	//	glTranslatef(0,0,-i);
	//    
	//}
	//glTranslatef(0,0,-60);
	//for(GLfloat i=0 ; i>-20;i-=2)
	//{
	//	glTranslatef(0,0,i);
	//    glutSolidCylinder(10,1,50,10);
	//	glTranslatef(0,0,-i);
	//    
	//}
	////draw_cube(1,10,1,0);
	//glPopMatrix();
	  

	////////////////





	/*******************************  SECOND DECK **************/

	glPushMatrix();

	glutSolidSphere(2,100,10);
	glutSolidTorus(2,20,100,100);
	glutWireTorus(2.2,20,100,100);


	//*******************************  1-ONE
	glPushMatrix();
	glTranslatef(0,0,15);
	//glutSolidTorus(1,1.5,100,100);
	for(GLdouble z=10.5;z>=-28.5;z-=4.5){
    glPushMatrix();
	glTranslatef(-1,-1,z);
	glScaled(0.1,0.1,0.05);
	draw_scavs(Point(0,0,0),d);
	glTranslatef(60,-1,0);
	draw_scavs(Point(0,0,0),d);
	
	glPopMatrix();
	}
	//glTranslatef(0,0,-50);
	glPopMatrix();


	//********************************** 2 - TWO
	//glPushMatrix();
	//glTranslatef(0,0,15);
	////glutSolidTorus(1,1.5,100,100);
	//for(GLdouble z=28.5;z>=-28.5;z-=5){
 //   glPushMatrix();
	//glTranslatef(-1,z,-1);
	//glRotatef(rotor_val,0,0,1);
	//glScaled(0.1,0.1,0.05);
	//draw_scavs(Point(0,0,0),0);
	//glPopMatrix();	
	//}
	//glTranslatef(0,0,-50);
	//glPopMatrix();

	//
	////******************************** 3 - THREE
	//glPushMatrix();
	//glRotatef(90,0,0,1);
	//for(GLdouble z=28.5;z>=-28.5;z-=5){
 //   glPushMatrix();
	//glTranslatef(-1,z, 16);
	//glRotatef(rotor_val,0,0,1);
	//glScaled(0.1,0.1,0.05);
	//draw_scavs(Point(0,0,0),0);
	//glPopMatrix();	
	//}
	//glTranslatef(0,0,-50);
	//glPopMatrix();


	/////// ********************************* 4 - FOUR
	glPushMatrix();
	glTranslatef(0,0,15);
	//glutSolidTorus(1,1.5,100,100);
	for(GLdouble z=28.5;z>=-28.5;z-=5){
    glPushMatrix();
	glTranslatef(1,z,-26);
	glRotatef(rotor_val,0,0,1);
	glScaled(0.1,0.1,0.05);
	draw_scavs(Point(0,0,0),d);
	glPopMatrix();	
	}
	//glTranslatef(0,0,-50);
	glPopMatrix();

	
	//*************************** 5 - FIVE
	glPushMatrix();
	glRotatef(90,0,0,1);
	for(GLdouble z=28.5;z>=-28.5;z-=5){
    glPushMatrix();
	glTranslatef(1,z,-18);
	glRotatef(rotor_val,0,0,1);
	glScaled(0.1,0.1,0.05);
	draw_scavs(Point(0,0,0),d);
	glPopMatrix();	
	}
	glPopMatrix();
    //////////////////




	glPushMatrix();
	glScaled(1,1,1);
	//draw_scavs(Point(0.0,0.0,0.0),0);
	Point center2(0.0,0.0,0.0);
	glRotatef(rotor_val,0,0,1);
	for (GLfloat i = 0.0; i <= seg_sat; i++)
	{
	        Point cent = center2 + Vector(cosf(theta),sinf(theta),center2.z) * 20;
			Render::getRenderInstance()->drawSegment3d(center2,cent);
			theta += inc;
	}
	glPopMatrix();
	glPopMatrix();

	//LAST POP
	glPopMatrix();


	glScaled(1,1,1);

}
void IEntityManager::call_draw_colony_debris()
{
	glCallList(gen_list+ENTITY_UNITY);
}



void IEntityManager::draw_FusionShip()
{


	glPushMatrix();
	     
     	glPushMatrix();
		draw_plane(10,10,1);
	    glPopMatrix();

	glPopMatrix();

}


void IEntityManager::draw_tunnelBoundary()
{

	glRotatef(0,1,1,1);


	glPushMatrix();
	glScaled(1000,1000,1000);


	
	////*************************** 1 - ONE - A ****************************
	//glPushMatrix();
	//glTranslatef(0,0,15);

	//for(GLdouble z=-1.5;z>=-128.5;z-=4.5){
 //   glPushMatrix();
	//glTranslatef(-1,-1,z*25);
	////glScaled(0.1,0.1,0.05);
	//draw_scavs(Point(0,0,0),0);
	//glTranslatef(-70,-1,0);
	//draw_scavs(Point(0,0,0),0);
	//glPopMatrix();
	//}
	//glPopMatrix();
	////************************************** END 1 - ONE - A ********************

#pragma top
	glPushMatrix();
	for(GLdouble z=-37.5;z>=-1212.5;z-=40.5){
    glPushMatrix();
	glTranslatef(-1,-1,z);
	//glScaled(0.1,0.1,0.05);
	draw_scavs(Point(0,0,0),0);
	glTranslatef(-80,-1,0);
	draw_scavs(Point(0,0,0),0);
	glPopMatrix();
	}
	glPopMatrix();
#pragma endregion

	glTranslatef(-40,43,0);

#pragma top down
	glPushMatrix();
	for(GLdouble z=-37.5;z>=-3212.5;z-=40.5){
    glPushMatrix();
	glTranslatef(-1,-1,z);
	//glScaled(0.1,0.1,0.05);
	draw_scavs(Point(0,0,0),0);
	glTranslatef(0,-85,0);
	draw_scavs(Point(0,0,0),0);
	glPopMatrix();
	}
	glPopMatrix();

#pragma endregion




	//LAST POP
	glPopMatrix();


	glScaled(1,1,1);

}


void IEntityManager::draw_nalanda()
{


	glPushMatrix();
	{
	
	glScalef(1000,1000,1000);


    glPushMatrix();
	glTranslatef(0,0,15);
    for(GLdouble z=-10.5;z>=-68.5;z-=4.5)
	{
		{
			glPushMatrix();
			glTranslatef(-1,-1,z);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glutSolidSphere(5.0,50,50);

			glPushMatrix();
			glTranslatef(z,-1,0);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glPushMatrix();
			glTranslatef(1,1,-z);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glPushMatrix();
			glTranslatef(-z,1,0);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glPushMatrix();
			glTranslatef(1.0,-z,0);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glPushMatrix();
			glTranslatef(1.0,z,0);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

		}

	} //for_end
	glPopMatrix();

	glTranslatef(0,0,-15);

	glutSolidCube(8.0);

	//second
	glPushMatrix();
	glTranslatef(0,0,-35);
    for(GLdouble z=-10.5;z>=-68.5;z-=4.5)
	{
		{
			glPushMatrix();
			glTranslatef(-1,-1,z);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glutSolidSphere(5.0,50,50);

			glPushMatrix();
			glTranslatef(z,-1,0);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glPushMatrix();
			glTranslatef(1,1,-z);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glPushMatrix();
			glTranslatef(-z,1,0);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glPushMatrix();
			glTranslatef(1.0,-z,0);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

			glPushMatrix();
			glTranslatef(1.0,z,0);
			glScaled(0.1,0.1,0.05);
			draw_scavs(Point(0,0,0),0);
			draw_scavs(Point(0,0,0),0);
			glPopMatrix(); 

		}

	} //for_end
	glPopMatrix();


	}


	glPopMatrix();
	glScaled(1,1,1);

}



void IEntityManager::draw_dockStation()
{
	GLfloat seg_sat = 10.0f;
	GLfloat inc = 2 * 3.14256 / seg_sat;
	double theta = 0.0;

	glPushMatrix();
	glScaled(100,100,100);
	Point center(0.0,0.0,0.0);
	//glRotatef(rotor_val,0,0,0);
	for (GLfloat i = 0.0; i <= seg_sat; i++)
	{
	        Point cent = center + Vector(cosf(theta),sinf(theta),center.z) * 80;
			glTranslatef(cent.x,cent.y,cent.z);
			draw_scavs(Point(0,0,0),0);
			theta += inc;
	}  
	glPopMatrix();

	glScaled(1,1,1);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma region camera

MainCamera* MainCamera::instance = NULL;




MainCamera* MainCamera::getInsatance()
{
	if(instance==NULL)
	{
		instance = new MainCamera();
	}

	return instance;
}


MainCamera::MainCamera()
{}


MainCamera::~MainCamera()
{
}

void MainCamera::setCamera2d()
{
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);

	  if(h==0){ h=1; }
        GLfloat aspect = (GLfloat)w / (GLfloat)h;
        
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w>=h){ gluOrtho2D(-1.0*aspect , 1.0*aspect , -1.0 , 1.0); }
        else { gluOrtho2D(-1.0 , 1.0 , -1.0 / aspect , 1.0 / aspect); }
}

void MainCamera::setCamera3d()
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
 // glMaterialf(GL_FRONT, GL_SHININESS, 30);
  glLightfv(GL_LIGHT0, GL_AMBIENT , white);
  glLightfv(GL_LIGHT0, GL_DIFFUSE , white);
 // glLightfv(GL_LIGHT0, GL_SPECULAR , white);
  glLightfv(GL_LIGHT0, GL_POSITION , direction);

  // Keep the lightingt ON as default setting for this sequence
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
}


#pragma endregion