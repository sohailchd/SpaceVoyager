
#include "Screens.h"

Screens::Screens()
{
	 
}



Screens::~Screens()
{
}



 void Screens::display_screen()
{

}


void Screens::idle_screen()
{

}

void Screens::keyboard_screen(unsigned char& key , int& x , int& y)
{
     
}

void Screens::keyboard_screen_sp(int& key , int& x , int& y)
{
     
}



void Screens::reshape(int& w , int& h)
{
}

void Screens::loadObjects()
{

}

void Screens::timer_screen(int t)
{

}

void Screens::setScreenState(ScreensState st)
{
	_lastState    = _currentState;
	_currentState = st;

}

ScreensState Screens::getScreenState ()
{return _currentState;}

ScreensState Screens::getLastScreenState()
{ return _lastState; }


