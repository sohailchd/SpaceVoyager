
/********************************************
Project : The_Voyager
Author  : sohail_choudhary
Licence : GNU


Usage: Every entity will created at the opengl context origin.
1. Sat_A
2. Sat_B
3. Sat_C
4. Dock_A
5. Dock_B
6. Energizer

********************************************/

#ifndef _IEntityManager_
#define _IEntityManager_



#include "MasterHeader.h"
#include "Render.h"
#include "TextureLoader.h"





class IEntityManager
{


private:
    static IEntityManager* entityManagerInstance;


public:
	virtual ~IEntityManager(){ }

	void init_IEntityManager();

	void create_Sat_A();
	void create_Sat_B();
	void create_Sat_C();

	
	void draw_plane(GLdouble w , GLdouble h , int tex);
	void create_planet();
	void draw_sphere(int r , int tex);

	void create_genesis(Point* at);
	void draw_scavs(Point& p , GLfloat d);

	void draw_colony_debris( GLfloat d );
	void call_draw_colony_debris();

	void draw_colony_boot();
	void draw_FusionShip();
	void draw_nalanda();
	void draw_cube(GLdouble w, GLdouble h, GLdouble l, int tex_index);
    void draw_dockStation();
	void draw_sphere_parallel(int r, char* fileNameConstant);
	void draw_tunnelBoundary();
	
	GLuint gen_list;

	// Singleton instance creator
	static IEntityManager *getInstance();
	GLuint texture_ids[MAX_NO_TEXTURE];
    GLUquadric* quad_iem;
	GLfloat rotor_val;
protected:
	IEntityManager()
	{
		init_IEntityManager();
	}


};



class MainCamera
{
private:
	static MainCamera* instance;
	MainCamera();

public:
	static MainCamera* getInsatance();
	~MainCamera();
	void setCamera2d();
	void setCamera3d();

};



#endif     
