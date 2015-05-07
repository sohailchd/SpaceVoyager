

#ifndef _levelTwo
#define _levelTwo


#pragma once



#include "MasterHeader.h"
#include "Exterminatore.h"
#include "CollisionManager.h"
#include "SoundManager.h"
#include <vector>
#include "IEntityManager.h"


using namespace std;

class levelTwo : public ISceneNode
{
 public: 
		 levelTwo();
		~levelTwo();

		 enum levelTwoStates
		 {
			 _intro,
			 _fightCuborgs,
			 _docking_genesis,
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
		 void drawUnityExtensions();

		 void drawNormal();

private:
          Ship* _ship;
		 
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
		
		  Quad  *scavs_vicinity_trigger;
		  Quad  *atmosphere_vicinity_alert;

		  
		  void drawOnScreen();
		  void handleVicinityTriggers();
		 


		
		  /***********       variables   **********************/
		  unsigned int cuborgsCount;
		  GLfloat fogDensity2       ;
		  GLfloat fogDensity        ;
          GLfloat fogColor[4]       ;
          GLfloat unity_debrispara  ;
		  bool isWormhole           ;
		  GLfloat counterWormhole   ;
		  GLfloat levelStartTime;
		  bool startAttack;
		  vector<Quad*> _missileTargets;
		  void refereshMissileTargets();
          ExterminatoreNet  *exterMin;        /* Drifters */
		  bool ifInit ;
		  levelTwoStates mission_currentState;
		  vector<Quad*> _unityCollision_list; 
		  bool enterAtmosphere;
		
};

#endif
