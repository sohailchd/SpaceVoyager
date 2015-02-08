

#ifndef _Cockpit_
#define _Cockpit_

#pragma once

#include "Render.h"
#include <cmath>

class Cockpit
{





public:

    Cockpit();
    ~Cockpit(){};


    void create();
    void draw();

	enum cockpit_state
	{
        _inActive,
		_onThrusters,
		_docking,
		_rollAnimation,
		_forceStop,
		_stuttering
	};
	
	

};



#endif
