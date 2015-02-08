

#ifndef _inFightScav_SQ
#define _inFightScav_SQ


#pragma once


#include "ISceneNode.h"
#include "Cockpit.h"


class inFightScav : public ISceneNode
{
       public: 
		   inFightScav(){
			   _ship = new Ship(Point(0,0,2000000));
			   _cockpit = new Cockpit(*_ship);
		   };
        ~inFightScav();

         virtual void initScene();
         virtual void display_fn_game();
	     virtual void idle_fn_game();
	     virtual void keyboard_fn_game(unsigned char& key,int& x, int& y);
         virtual void special_fn_game(int& key , int& x, int& y);
	     virtual void timer_fn_game(int t);


		 
          Ship*      _ship;
		  Cockpit*   _cockpit;
         
};

#endif
