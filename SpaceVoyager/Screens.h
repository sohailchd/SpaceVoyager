

#ifndef  _screens_
#define  _screens_

#pragma once

#include "MasterHeader.h"
#include "Render.h"


enum ScreensState
{
	  _inactive,
	  _active,
	  _saved,
	  _exited
};


class Screens
{
 
protected:
	
		  ScreensState _currentState;
		  ScreensState  _lastState;

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

		  void setScreenState(ScreensState st);
		  ScreensState getScreenState();
		  ScreensState getLastScreenState();
		   
		  int _namedId;


		 
};


#endif
