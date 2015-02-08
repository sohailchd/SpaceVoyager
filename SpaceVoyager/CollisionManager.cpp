#include "CollisionManager.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{
	delete[] &_collisionList; 
	delete[] &_targetList;
}

void CollisionManager::addToList(Quad* quad)
{
	_collisionList.push_back(quad);
}

void CollisionManager::addAsTarget(Quad* quad)
{
	_targetList.push_back(quad);
}

void CollisionManager::deleteFromList(Quad* quad)
{
	for(int i = 0;i<_collisionList.size();i++)
	{
		if(!_collisionList[i]->getVisibility())
		{
			_collisionList.erase(_collisionList.begin()+i);  
		}
	}
}


void CollisionManager::deleteAsTarget(Quad* quad)
{
	for(int i = 0;i<_targetList.size();i++)
	{
		if(!_targetList[i]->getVisibility())
		{
			_targetList.erase(_targetList.begin()+i);  
		}
	}
}




void CollisionManager::runCollisionEngine()
{
	for(int i = 0;i<_targetList.size();i++)
	{
	   for(int j = 0;i< _collisionList.size();i++)
	   {
		   if(_targetList[i]->Intersects(_collisionList[j]))
		   {
			   _targetList[i]->setCollision(true);
			   _collisionList[j]->setCollision(true);
		   }
	   }
	}
}