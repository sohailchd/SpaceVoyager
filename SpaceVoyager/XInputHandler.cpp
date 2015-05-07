
#include "XInputHandler.h"
#include "MasterHeader.h"


XInputHandler::XInputHandler(){}

//XInputHandler::~XInputHandler(){}

XInputHandler* XInputHandler::instanceXinput = 0;
BOOL XInputHandler::isConnected = false;

XInputHandler* XInputHandler::getInstance()
{
	if( XInputHandler::instanceXinput==NULL)
	{
		instanceXinput = new XInputHandler();
	}

	return instanceXinput;
}

/* Called every frame to update the current state of the controller is updated */
void XInputHandler::updateX()
{
	
	for(DWORD i=0;i<MAX_CONTROLLER;i++)
	{

		//Get the current State of the controler & save them in XINPUT_STATE
		DWORD result =  XInputGetState(i,&controller[i]._controllerState);
		//Set the isConnected 
		controller[i].isConnected = (result == ERROR_SUCCESS);
		XInputHandler::isConnected = controller[i].isConnected?TRUE:FALSE;
		if(controller[i]._controllerState.dwPacketNumber != controller[i]._lastState.dwPacketNumber)
		{
			controller[i]._notLast = true;
			controller[i]._lastState = controller[i]._controllerState;
			//printf("Controller State updated. \n");
		}else { controller[i]._notLast = false; }
	}
	
}

/* Called when discrete press is required to be register */

/****************
     Mapping by Xbox 360
****************/
bool XInputHandler::isDigitalButtonPressedOnce(char key)
{
	bool ret = false;;
	for(DWORD i=0;i<MAX_CONTROLLER;i++)
	{
		if(controller[i]._notLast)
		{
		switch(key)
		{
		case 'X':
			if((controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_X)){ret= true;}
			break;
		case 'Y':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_Y){ret= true;}
			break;
		case 'A':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_A){ret= true;}
			 break;
		case 'B':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_B){ret= true;}
			break;
		case 'U':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP){ret= true;}
			break;
		case 'D':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN){ret= true;}
			break;

		case 'R':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT){ret= true;}
			break;
		case 'L':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT){ret= true;}
			break;

		default :
			ret = false;
			break;
		}
		}

 	}

	return ret;
}





bool XInputHandler::isDigitalButtonPressed(char key)
{
	bool ret = false;;
	for(DWORD i=0;i<MAX_CONTROLLER;i++)
	{
		
		switch(key)
		{
		case 'X':
			if((controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_X)){ret= true;}
			break;
		case 'Y':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_Y){ret= true;}
			break;
		case 'A':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_A){ret= true;}
			 break;
		case 'B':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_B){ret= true;}
			break;
		case 'U':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP){ret= true;}
			break;
		case 'D':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN){ret= true;}
			break;

		case 'R':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT){ret= true;}
			break;
		case 'L':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT){ret= true;}
			break;
       case 'S':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_START){ret= true;}
			break;
	   case 'C':
			if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_BACK ){ret= true;}
			break;

		default :
			ret = false;
			break;
		}
	

 	}

	return ret;
}


bool XInputHandler::getShoulderButton(char key)
{
	bool retVal = false;
	for(DWORD i = 0;i<MAX_CONTROLLER;i++)
	{
		if(key=='L'){if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER){ retVal = true; }}
		if(key=='R'){if(controller[i]._controllerState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER){ retVal = true; }}

	}
	return retVal;
}








/* Registering the sticks  
   Mapping : 
   R - Right
   L - Left
   X - X axis
   Y - Y axis
*/
int XInputHandler::getThumbVal(char index , char axis)
{

	int retVal=0;
	for(DWORD i=0;i<MAX_CONTROLLER;i++)
	{

		switch (index)
		{
		case 'R':
			{
               switch (axis)
					{
					case 'X':
						if((controller[i]._controllerState.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) && 
							(controller[i]._controllerState.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) )
				        {
					       retVal = 0;
				        }
						
						else
						{
						   retVal = controller[i]._controllerState.Gamepad.sThumbRX;
						}
						break;
					case 'Y':
						if((controller[i]._controllerState.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) && 
							(controller[i]._controllerState.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) )
				        {
					       retVal = 0;
				        }
						
						else
						{
					    	retVal = controller[i]._controllerState.Gamepad.sThumbRY;
						}
						break;
					} 

				}
			break;
		
		case 'L':
			{
					switch (axis)
					{
					case 'X':
						if((controller[i]._controllerState.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) && 
							(controller[i]._controllerState.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) )
				        {
					       retVal = 0;
				        }
						else
						{
					    	retVal = controller[i]._controllerState.Gamepad.sThumbLX;
						}
						break;
					case 'Y':
						if((controller[i]._controllerState.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) && 
							(controller[i]._controllerState.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) )
				        {
					       retVal = 0;
				        }
						
						else
						{
						    retVal = controller[i]._controllerState.Gamepad.sThumbLY;
						}
						break;
					} 
				} 
			break;
		
		default:
			break;
		
		}//SWITCH_index
	
	}//FOR-END

	return retVal;
}


int XInputHandler::getTrigerVal(char index)
{
	int retVal = 0;

	for(DWORD i = 0;i<MAX_CONTROLLER;i++)
	{
		  
		switch (index)
		{
		case 'R':
			{
				retVal = controller[i]._controllerState.Gamepad.bRightTrigger;
			}break;
		case 'L':
			{
				retVal = controller[i]._controllerState.Gamepad.bLeftTrigger;
			}break;
		default:
			break;
		}
	}

	return retVal;

}