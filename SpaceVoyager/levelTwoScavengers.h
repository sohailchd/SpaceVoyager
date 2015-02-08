

#ifndef _levelTwoEnemy_
#define _levelTwoEnemy_

#include "MasterHeader.h"
#include "Geometry.h"




class ScavengersArmy
{

      public:
          ScavengersArmy(){}
          ~ScavengersArmy(){}
          
  
};



class Scavengers
{
         public:
			 Scavengers(Point& pos){
				 scav_state = false;
				 missile_pos = pos;
				 drift_val = 0;
				 rot_face = 0.0f;
			}

            ~Scavengers(){};

            Point missile_pos;
			bool scav_state ;
			Quad* scav_boundingBox;
			GLdouble drift_val;
			GLfloat rot_face;

			//void draw_scavs(Point& p , GLfloat d);
            void display_scavengers()
            {
				if(!scav_state)
				 {
					 draw_scavs(missile_pos,drift_val);
				 }
           
            }



            void ai_engine()
            {
				//KEEP MOVING FORWARD
				missile_pos.z += 0.5; 
	        }



            void update_scavengers()
            {
				if(scav_state)
				{
					drift_val += 50;
				}
				else
				{
					rot_face +=10.0f;
				}


            }
            
			

void draw_scavs(Point& p , GLfloat d)
{

 missile_pos = p;
 glPushMatrix();
    glScaled(1,1,1);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	glPushMatrix();
	glColor4f(0.2,0.4,0.8,0.8);
	   glTranslatef(missile_pos.x-d+12,missile_pos.y+d+12,missile_pos.z+30);
	   glScaled(1,1,3);
	   glutSolidCube(15);
	glPopMatrix();

	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

	//FRONT-FACE
	glPushMatrix();


		glPushMatrix();
		glTranslatef(0,20,0);
		glRotatef(rot_face,0,0,1);
		glTranslatef(0,-20,0);
	    glTranslatef(missile_pos.x-d,missile_pos.y+d,missile_pos.z);
    	glutSolidCube(20);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0,20,0);
		glRotatef(rot_face,0,0,1);
		glTranslatef(0,-20,0);
		glTranslatef(missile_pos.x+22-d,missile_pos.y-d,missile_pos.z);
		glutSolidCube(20);
		glPopMatrix();


		glPushMatrix();
	    glTranslatef(0,20,0);
		glRotatef(rot_face,0,0,1);
		glTranslatef(0,-20,0);
	    glTranslatef(missile_pos.x+d,missile_pos.y+22-d,missile_pos.z);
		glutSolidCube(20);
		glPopMatrix();

		glPushMatrix();
	    glTranslatef(0,20,0);
		glRotatef(rot_face,0,0,1);
		glTranslatef(0,-20,0);
		glTranslatef(missile_pos.x+22+d,missile_pos.y+22-d,missile_pos.z);
		glutSolidCube(20);
		glPopMatrix();

	glPopMatrix();


	//BACK
	glPushMatrix();
	glColor4f(1,1,1,1);

		glPushMatrix();
		glTranslatef(0,20,0);
		glRotatef(-rot_face,0,0,1);
		glTranslatef(0,-20,0);
	    glTranslatef(missile_pos.x-d,missile_pos.y+d,missile_pos.z+22-d);
    	glutSolidCube(20);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0,20,0);
		glRotatef(-rot_face,0,0,1);
		glTranslatef(0,-20,0);
		glTranslatef(missile_pos.x+22-d,missile_pos.y-d,missile_pos.z+22-d);
		glutSolidCube(20);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0,20,0);
		glRotatef(-rot_face,0,0,1);
		glTranslatef(0,-20,0);
		glTranslatef(missile_pos.x+d,missile_pos.y+22-d,missile_pos.z+22-d);
		glutSolidCube(20);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0,20,0);
		glRotatef(-rot_face,0,0,1);
		glTranslatef(0,-20,0);
		glTranslatef(missile_pos.x+22+d,missile_pos.y+22+d,missile_pos.z+22-d);
		glutSolidCube(20);
		glPopMatrix();
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_BLEND);
  glPopMatrix();

}



}; 




#endif
