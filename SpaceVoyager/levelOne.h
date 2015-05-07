

#ifndef _levelOne
#define _levelOne


#pragma once


#include "Ship.h"
#include "MasterHeader.h"
#include "Render.h"
#include "IEntityManager.h"


class levelOne : public ISceneNode
{
       public:
       	levelOne();
        ~levelOne();

         virtual void initScene();
         virtual void display_fn_game();
	     virtual void idle_fn_game();
	     virtual void keyboard_fn_game(unsigned char& key,int& x, int& y);
         virtual void special_fn_game(int& key , int& x, int& y);
	     virtual void timer_fn_game(int t);


		 Ship* _ship;
	

         
};

#endif
