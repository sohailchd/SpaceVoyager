

#ifndef _Geometry_
#define _Geometry_


#include <cmath>
#include <iostream>
#include <freeglut.h>

using namespace std;

class Point;
class Vector;
class PointXY;



class Vector
{
public:
	double i,j,k;
	Vector(double i=0,double j=0 , double k=0):i(i),j(j),k(k){};
	Vector(Point p);
	Vector operator +(Vector v){ return Vector(i+v.i,j+v.j,k+v.k);}
	Vector& operator +=(Vector v){ i+=v.i;j+=v.j;k+=v.k; 
		return *this ;
	}
        Vector operator -(Vector v){ return Vector(i-v.i,j-v.j,k-v.k);}
	Vector& operator -=(Vector v){ i-=v.i; j-=v.j; k-=v.k; 
		return *this;
	}
	Vector operator -(){ return Vector(-i,-j,-k); }
	Vector operator *(double c){return Vector(i*c,j*c,k*c); }
	Vector operator /(double c){ return Vector(i/c,j/c,k/c); }
	
	
    Vector& operator *=(double c) 
    {    i=i*c;
         j=j*c;
         k=k*c;  
         return *this ;
    }
    Vector& operator /=(double c) {
        i=i/c;
        j=j/c;
        k=k/c;  
        return *this ;
    }
     
    Vector cross(Vector);
    double dot(Vector v) { return i * v.i + j*v.j + k*v.k ;};    
    friend Vector operator *(double c , Vector v) { return v*c; };
    double magnitude() { return sqrt(this->dot(*this)); }
    friend Vector unit(Vector v){ return v / v.magnitude(); };
    friend void normalize(Vector& v){  v /= v.magnitude(); }

};


inline Vector Vector::cross(Vector v)
{
	return Vector( j*v.k-k*v.j , k*v.i-i*v.k , i*v.j-j*v.i );
}



class Point
{
      public:
		GLdouble x , y , z ;
      	Point(double x=0 , double y=0, double z=0):x(x),y(y),z(z){};
        Point operator +(Vector v) { return Point(x+v.i,y+v.j,z+v.k);}
        Point operator -(Vector v){ return Point(x-v.i,y-v.j,z-v.k); }
        Point operator +=(Vector v) { return Point( x+=v.i , y+=v.j , z+=v.k ); }
		Point(const Point &obj){ x=obj.x;y=obj.y;z=obj.z; }
		bool operator==(const Point& p){ if(p.x==x&&p.y==y&&p.z==z){ return true; } return false; }
		friend ostream& operator<<(ostream &os , const Point& p){ os<<endl<< p.x <<" : "<<p.y<<" : "<<p.z; return os; }
};

class PointXY
{

public:
  double x , y ;
  PointXY(double x=0,double y=0):x(x),y(y){};
};


class Quad
{
private:
         Point position;
         double height , width , depth;
		 bool isVisible;
		 bool isColliding;
public:
	   
         Quad(Point& v,double w,double h,double d)
         {
              position = v;
              height   = h;
              width    = w;
              depth    = d;

			  isVisible = true;
			  isColliding = false;
         }
		
         bool Intersects(Quad& qd);
		 void setPosition(Point& point){ this->position =  point;}
         Point getPosition(){ return position; }
		 bool IntersectsSphere(Point position , double rad);
		 void setVisibility(bool param){ isVisible = param; }
		 void setCollision(bool param){ isColliding = param; }
		 bool getVisibility(){ return isVisible; }
		 bool getIsColliding() { return isColliding;}
		 Quad operator<<(const Quad* q){cout<<"w:"<<width<<" h"<<height<<" d: "<<depth<<endl;}
		 Quad(const Quad& obj){ width = obj.width; height=obj.height;depth=obj.depth;isVisible=true;isColliding=false; }
		 
		 
};

inline bool Quad::Intersects(Quad& qd)
{
	if(&qd!=NULL)
	{
               if(abs(position.x - qd.position.x) < abs(width + qd.width))
               {
                   if(abs(position.y - qd.position.y) < abs(height + qd.height))
				   {
                        if(abs(position.z - qd.position.z) < abs(depth+10 + qd.depth))
                        { 
                              return true;
                        }
                   }
               }
               else{
                return false;
              }
	}

	return 0;

}


inline bool Quad::IntersectsSphere(Point point , double rad)
 {
	 GLdouble distance=0.0;
	 bool ret = false;
//	 distance= pow((this->position.x - point.x),2) + pow((this->position.y - point.y),2) + pow((this->position.z - point.z),2);

	 if( (abs(position.x - point.x) < rad) && 
		 (abs(position.y - point.y) < rad) &&
		 (abs(position.z - point.z) < rad))
	 {
		 ret = true;
	 }

	 //printf("geometry.h  %d \n",distance);
	 
	 return ret;
 }



#endif







