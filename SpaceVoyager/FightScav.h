



#ifndef _fightScav
#define _fightScav


#pragma once


#include "ISceneNode.h"
#include "Cockpit.h"
#include "IEntityManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"
#include "Ship.h"
#include "Exterminatore.h"


class TunnelObject
{
public:

	TunnelObject(Point& p){ position = p; }
	~TunnelObject()
	{
        
	}


	Point position;
	//Quad* collisionCube;
	GLfloat speed;

	void draw_scavs(Point& missile_pos , GLfloat d)
	{
	   glPushMatrix();
       glScaled(1000,1000,1000);
//	
//#pragma region FRONT-FACE
//	glPushMatrix();
//		glPushMatrix();
//	    glTranslatef(missile_pos.x-d,missile_pos.y+d,missile_pos.z);
//    	glutSolidCube(20);
//		glPopMatrix();
//
//
//		glPushMatrix();
//		glTranslatef(missile_pos.x+22-d,missile_pos.y-d,missile_pos.z);
//		glutSolidCube(20);
//		glPopMatrix();
//
//
//		glPushMatrix();
//		glTranslatef(missile_pos.x+d,missile_pos.y+22-d,missile_pos.z);
//		glutSolidCube(20);
//		glPopMatrix();
//
//		glPushMatrix();
//		glTranslatef(missile_pos.x+22+d,missile_pos.y+22-d,missile_pos.z);
//		glutSolidCube(20);
//		glPopMatrix();
//	glPopMatrix();
//#pragma endregion
//
//#pragma region BackFace
//	glPushMatrix();
//		glPushMatrix();
//	    glTranslatef(missile_pos.x-d,missile_pos.y+d,missile_pos.z+22-d);
//    	glutSolidCube(20);
//		glPopMatrix();
//
//
//		glPushMatrix();
//		glTranslatef(missile_pos.x+22-d,missile_pos.y-d,missile_pos.z+22-d);
//		glutSolidCube(20);
//		glPopMatrix();
//
//
//		glPushMatrix();
//		glTranslatef(missile_pos.x+d,missile_pos.y+22-d,missile_pos.z+22-d);
//		glutSolidCube(20);
//		glPopMatrix();
//
//		glPushMatrix();
//		glTranslatef(missile_pos.x+22+d,missile_pos.y+22+d,missile_pos.z+22-d);
//		glutSolidCube(20);
//		glPopMatrix();
//	glPopMatrix();
//#pragma endregion
//
//       glPopMatrix();

	   glPopMatrix();
	}

	void draw()
	{

	

	

	}


	void update()
	{
	
		
	}

	
};

class fightScav : public ISceneNode
{
       public: 
		   fightScav();
        ~fightScav();

         virtual void initScene();
         virtual void display_fn_game();
	     virtual void idle_fn_game();
	     virtual void keyboard_fn_game(unsigned char& key,int& x, int& y);
         virtual void special_fn_game(int& key , int& x, int& y);
	     virtual void timer_fn_game(int t);
		 
		 //CollisionManager* collisionManager;


	private:
          Ship*      _ship;
		  bool ifInit;
		  vector<TunnelObject*> TunnelObject_list;
};

#endif
