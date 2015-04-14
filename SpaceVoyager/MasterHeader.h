
#ifndef _MasterHeader_
#define _MasterHeader_

#pragma once

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <freeglut.h>
#include <gl\GL.h>
#include <SOIL.h>
#include "Geometry.h"
#include <vector>
#include <map>
#include <irrKlang.h>

//assimp
#include <Importer.hpp>      // C++ importer interface
#include <scene.h>           // Output data structure
#include <postprocess.h> 

#define FAR_SIGHT 10000000.0

#define ENTITY           0
#define ENTITY_COCKPIT   1
#define ENTITY_UNITY     2
#define ENTITY_BG        3
#define ENTITY_CYRUS     4
#define ENTITY_HABITAT   5

#define space_bg  "../images/space_bg.jpg"
#define cyrus     "../images/cryrus.jpg"
#define voyager   "../images/voyager.jpg"
#define crash     "../images/crash.jpg"



#define MAX_NO_TEXTURE 20




#endif