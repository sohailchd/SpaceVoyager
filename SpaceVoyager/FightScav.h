



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
		 
		 CollisionManager* collisionManager;
		 SManager* soundManager_ltwo;

	private:
          Ship*      _ship;
		  ExterminatoreNet* exterMin;
		  Quad* planet_quad ; 
		  bool ifInit;

};

#endif
