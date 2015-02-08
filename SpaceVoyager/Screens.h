

#ifndef  _screens_
#define  _screens_

#pragma once

#include "MasterHeader.h"
#include "Render.h"


class Screens
{
      
      public:
		  Screens();
		  virtual ~Screens();

          virtual void display_screen();
          virtual void keyboard_screen(unsigned char& key , int& x , int& y);
          virtual void keyboard_screen_sp(int& key,int& x,int& y);
          virtual void timer_screen(int t);
          virtual void idle_screen();
          virtual void reshape(int& n , int& n2);
          virtual void loadObjects();	
		 // virtual void soundPlayer();
};


#endif
