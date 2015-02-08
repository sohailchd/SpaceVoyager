
#ifndef _XInputHandler_
#define _XInputHandler_
#include <Windows.h>
#include <Xinput.h>

#define MAX_CONTROLLER 1


 struct CONTROLLER_INFO
{
	CONTROLLER_INFO(){
		_lastState = _controllerState;
	}
	~CONTROLLER_INFO(){}

	XINPUT_STATE      _controllerState;
	XINPUT_STATE      _lastState;
	BOOL              isConnected;
	XINPUT_VIBRATION  _controllerVibration;
	BOOL              _notLast;

};


class XInputHandler
{

private:
	static XInputHandler* instanceXinput;

protected:

	XInputHandler();
	
public:
	~XInputHandler();
	
     struct CONTROLLER_INFO controller[MAX_CONTROLLER];
     void updateX();
     bool isDigitalButtonPressedOnce(char key);
	 bool isDigitalButtonPressed(char key);
	 int getThumbVal(char index , char axis);
	 int getTrigerVal(char index);
	 bool getShoulderButton(char s);
	 
	 static XInputHandler* getInstance();

};

#endif