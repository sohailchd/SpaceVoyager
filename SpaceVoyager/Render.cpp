

#include "Render.h"
    const double k_seg = 32.0f;
    const double k_inc = 2.0f * 3.1425 / k_seg;
    double theta = 0.0f;

	Render* Render::renderInstance = NULL;

	Render* Render::getRenderInstance()
	{
		if(renderInstance== NULL)
		{
			renderInstance = new Render();
		}
		return renderInstance;
	}


	void Render::drawHudText(Point pos , char* text , double* color )
	{
		int len ;
      len = (int)strlen(text);
    	glColor3f(color[0],color[1],color[2]);
        double t_dis = 0.0;
        for( int i= 0;i<len;i++){
           t_dis += 0.04;
           glRasterPos3f(pos.x+t_dis,pos.y,pos.z);
           glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
         }
	}

	void Render::drawHudText10(Point pos , char* text , double* color )
	{
		int len ;
      len = (int)strlen(text);
    	glColor3f(color[0],color[1],color[2]);
        double t_dis = 0.0;
        for( int i= 0;i<len;i++){
           t_dis += 0.01;
           glRasterPos3f(pos.x+t_dis,pos.y,pos.z);
           glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,text[i]);
         }
	}

	void Render::drawHudText12(Point pos , char* text , double* color )
	{
		int len ;
      len = (int)strlen(text);
    	glColor3f(color[0],color[1],color[2]);
        double t_dis = 0.2;
        for( int i= 0;i<len;i++){
           t_dis += 0.02;
           glRasterPos3f(pos.x+t_dis,pos.y,pos.z);
           glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,text[i]);
         }
	}

	void Render::drawHudText18(Point pos , char* text , double* color )
	{
	  int len ;
      len = (int)strlen(text);
    	glColor3f(color[0],color[1],color[2]);
        double t_dis = 0.0;
        for( int i= 0;i<len;i++){
           t_dis += 0.03;
           glRasterPos3f(pos.x+t_dis,pos.y,pos.z);
           glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
         }
	}




    void Render::drawCircle(Point center,const double radius)
	{
   


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<32;++i)
        {
            Point v = center +  Vector(cosf(theta),sinf(theta),center.z) * radius;
            glVertex3f(v.x/10,v.y/10,center.z);
            theta += k_inc;
        }
    glEnd();
    
    //printf("Draw circle called..\n");     
    }
  
    void Render::drawPolygon(Point vertices_array[],int v_count)
	{

      glBegin(GL_LINE_LOOP);
           for(int i=0;i<v_count;i++){
                 glVertex3f(vertices_array[i].x,vertices_array[i].y, vertices_array[i].z);
           }
      glEnd();
    }


    void Render::drawRect(Point vertex,double w,double h)
	{
     

      glBegin(GL_LINE_LOOP);
          glVertex3f(vertex.x,vertex.y,vertex.z);
          glVertex3f(vertex.x,vertex.y-h,vertex.z);
          glVertex3f(vertex.x+w,vertex.y-h,vertex.z);
          glVertex3f(vertex.x+w,vertex.y,vertex.z);
      glEnd();


     
    }



    void Render::drawSegment3d(Point p1 , Point p2)
    {
      glPushMatrix();
      glBegin(GL_LINES);
          glVertex3f(p1.x,p1.y,p1.z);
          glVertex3f(p2.x,p2.y,p2.z);
      glEnd();    
      glPopMatrix();
      //printf("%f\n", p2.y);       
    }
