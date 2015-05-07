#include "Exterminatore.h"


Exterminatore::Exterminatore(){}
Exterminatore::Exterminatore(Point p)
{
	initPos   = p;
	position  = p;
	isHit     = false;
	isAlive   = true;
	collisionBox = new Quad(p,8000,8000,8000);
}

Exterminatore::~Exterminatore(){}

void Exterminatore::drawExterminatore()
{

	if(!isHit)
	{
		glPushMatrix();
		glDisable(GLU_CULLING);
		glDisable(GL_CULL_FACE);
		glDisable(GL_LIGHTING);
		glRotatef(GameStateManager::timeSinceStart*0.005,0.2,1,0);
		glColor3f(sin(GameStateManager::timeSinceLast*0.01),sin(GameStateManager::timeSinceLast*0.01),sin(GameStateManager::timeSinceLast*0.01));
		glTranslated(position.x,position.y,position.z);


		glutSolidCube(3000.0);
		
		IEntityManager::getInstance()->draw_plane(9000,2000,1);
		/**
		glTranslatef(-4000.0f,0.0f,0.0f);
		glRotatef(90.0f,0.0f,0.0f,1.0f);
		IEntityManager::getInstance()->draw_plane(4000,2000,20);
		glTranslatef(8000.0f,0.0f,0.0f);
		IEntityManager::getInstance()->draw_plane(4000,2000,20);
		**/
		glEnable(GLU_CULLING);
		glEnable(GL_CULL_FACE);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		
	}
	else
	{
		IEntityManager::getInstance()->draw_scavs(position,GameStateManager::timeSinceStart*0.01);
	}
}
    GLfloat seg_satEx = 72.0f;
	GLfloat inc = 2 * 3.14256 / seg_satEx;
	double thetaEx = 0.0;
	Point center(0.0,0.0,0.0);
void Exterminatore::updateExterminatore()
{
	
	        Point cent = initPos + Vector(cosf(thetaEx),sinf(thetaEx),center.z) * 140000.0f;   // radia 
			setPosition(cent);
		    thetaEx += inc*0.1;
			setPosition(cent);
	
}

void Exterminatore::setPosition(Point p)
{
	position = p;
	collisionBox->setPosition(position);
}

Point Exterminatore::getPosition()
{
	return position;
}

void Exterminatore::setIsAlive(bool t)
{
	isAlive = t;
}

bool Exterminatore::getIsAlive()
{
	return isAlive;
}





/****************************************************************************************/
#pragma region exterminatorePackager

ExterminatoreNet::ExterminatoreNet(){}
ExterminatoreNet::~ExterminatoreNet(){}

void ExterminatoreNet::createExterminatore(Point at)
	{
		_listExterMinator.push_back(new Exterminatore(at));
	}

	void ExterminatoreNet::drawExterminatore()
	{
		for(unsigned int i=0;i < _listExterMinator.size();i++ )
		{

			if(_listExterMinator[i]->collisionBox->getIsColliding())
			{
				_listExterMinator[i]->isHit = true;
			}

			if(_listExterMinator[i]->getIsAlive())
			{
			  _listExterMinator[i]->drawExterminatore();
			}
			else
			{
				SAFE_DELETE(_listExterMinator[i]);
				_listExterMinator.erase(_listExterMinator.begin()+i);
			}
		}
	}

	void ExterminatoreNet::updateExterminatore()
	{
		for(unsigned int i=0;i < _listExterMinator.size();i++ )
		{
			if(_listExterMinator[i]->getIsAlive())
			{
			    _listExterMinator[i]->updateExterminatore();
			}else
			{
				SAFE_DELETE(_listExterMinator[i]);
				_listExterMinator.erase(_listExterMinator.begin()+i);
			}
		}
	}

#pragma endregion