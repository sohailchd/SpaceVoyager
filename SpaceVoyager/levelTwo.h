

#ifndef _levelTwo
#define _levelTwo


#pragma once


#include "ISceneNode.h"
#include "Cockpit.h"
#include "MasterHeader.h"
#include "Exterminatore.h"
#include "CollisionManager.h"
#include "SoundManager.h"
#include <vector>

#ifndef _IEntityManager_
#include "IEntityManager.h"
#endif

using namespace std;

class levelTwo : public ISceneNode
{
       public: 
		   levelTwo();
		 /*  {
			   _ship = new Ship(Point(0,0,2000000));
			   exterMin = new ExterminatoreNet(); 
			   planet_quad = new Quad(Point(-660000,-10000,-100000),445000,445000,445000);
			   collisionManager = new CollisionManager();
			   soundManager_ltwo = new SManager();

		   };*/
        ~levelTwo();

         virtual void initScene();
         virtual void display_fn_game();
	     virtual void idle_fn_game();
	     virtual void keyboard_fn_game(unsigned char& key,int& x, int& y);
         virtual void special_fn_game(int& key , int& x, int& y);
	     virtual void timer_fn_game(int t);

		 CollisionManager* collisionManager;
	     void atmosphereEntryProtocol();
private:
          Ship  *_ship;
		  ExterminatoreNet  *exterMin;
		  Quad *planet_quad ; 
		  Quad *unity_collider_a ; 
	      Quad *unity_collider_b ; 
		  Quad *unity_collider_c ;
		  Quad *unity_collider_d ;
		  Quad *unity_dock_collider;
		  Quad *unity_dock2_collider;
		  Quad *unity_dock3_collider;
		  Quad *unity_collider_e;
      


		  bool ifInit ;
		  vector<Quad*> _unityCollision_list; 
		/*  Quad* docking_pad_a ,docking_pad_b  , docking_pad_c ;*/
	
};

#endif
