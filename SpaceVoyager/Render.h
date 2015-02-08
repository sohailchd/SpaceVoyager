
#ifndef _render_
#define _render_

#pragma once

#include "MasterHeader.h"
#include <cstring>



class Render{

protected:
	    Render(){};
private:
	static Render* renderInstance;
     
public:  
	~Render(){};

     
    void drawCircle(Point center,const double radius);
    void drawPolygon(Point vertices_array[],int v_count);
    void drawRect(Point top_corner,double w,double h);
    void drawSegment3d(Point p1 , Point p2);
	void drawCube(GLdouble s);
    void drawHudText(Point pos , char* text , double* color );
	void drawHudText10(Point pos , char* text , double* color);
	void drawHudText12(Point pos , char* text , double* color);
    void drawHudText18(Point pos , char* text , double* color);

	static Render* getRenderInstance();
    

};


//Render* Render::render_ins = NULL;
//GLUT_BITMAP_TIMES_ROMAN_24
//GLUT_BITMAP_HELVETICA_12
#endif
