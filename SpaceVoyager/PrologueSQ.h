

#ifndef _prologueSQ
#define _prologueSQ


#pragma once


#include "ISceneNode.h"



class prologueSQ : public ISceneNode
{
       public:
       	prologueSQ();
        ~prologueSQ();

         virtual void initScene();
         virtual void display_fn_game();
	     virtual void idle_fn_game();
	     virtual void keyboard_fn_game(unsigned char& key,int& x, int& y);
         virtual void special_fn_game(int& key , int& x, int& y);
	     virtual void timer_fn_game(int t);




         
};

#endif
