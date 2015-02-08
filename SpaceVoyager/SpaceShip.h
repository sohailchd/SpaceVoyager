
#ifndef _spaceShip_H_
#define _spaceShip_H_


#include "Geometry.h"


class SpaceShip
{
     public:
     	Point   position;
        Vector  forward , up , right;
        double speed;
     	
     	SpaceShip(Point initialPos = Point(0,0,0)){};
     	/*virtual Point getPosition(){ return position;}*/

        //Collision data
        double w,h,d;

};

#endif