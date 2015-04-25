

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


class Scavs
{
};


class levelTwo : public ISceneNode
{
       public: 
		   levelTwo();
		
        ~levelTwo();

		 enum levelTwoStates
		 {
			 _reachUnity,
			 _docking,
			 _seqUpload,
			 _wormholeDocking
		 };


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
		 
		  Quad *planet_quad ; 
		  Quad *unity_collider_a ; 
	      Quad *unity_collider_b ; 
		  Quad *unity_collider_c ;
		  Quad *unity_collider_d ;
		  Quad *unity_dock_collider;
		  Quad *unity_dock2_collider;
		  Quad *unity_dock3_collider;
		  Quad *unity_collider_e;
		  Quad *wormHole_collider;
          Quad *wormHole_collider_b;
		  Quad *wormhole_collider_sensor;
		  // Part two - 
		  Quad  *scavs_vicinity_trigger;
		  Quad  *atmosphere_vicinity_alert;

		  bool ifInit ;
		  levelTwoStates mission_currentState;
		  vector<Quad*> _unityCollision_list; 
		/*  Quad* docking_pad_a ,docking_pad_b  , docking_pad_c ;*/
	      
		  void drawOnScreen();
		  void handleVicinityTriggers();
		  GLfloat levelStartTime;
		  bool startAttack;

		  vector<Quad*> _missileTargets;
		  void refereshMissileTargets();

		  // rotating scavs
		  ExterminatoreNet  *exterMin;        /* Drifters */
		  //end

};

#endif
