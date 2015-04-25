#include "CollisionManager.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{
	delete[] &_collisionList; 
	delete[] &_targetList;
	delete[] &_triggerList;
	delete[] &_triggerTargetList;
}

void CollisionManager::addToList(Quad* quad)
{
	_collisionList.push_back(quad);
}
void CollisionManager::addToTriggerList(Quad* quad)
{
	_triggerList.push_back(quad);
}


void CollisionManager::addAsTarget(Quad* quad)
{
	_targetList.push_back(quad);
}
void CollisionManager::addAsTriggerTarget(Quad* quad)
{
	_triggerTargetList.push_back(quad);
}



void CollisionManager::deleteFromList(Quad* quad)
{
	/*for(int i = 0;i<_collisionList.size();i++)
	{
		if(!_collisionList[i]->getVisibility())
		{
			_collisionList.erase(_collisionList.begin()+i);  
		}
	}
*/
	
	for(int i = 0;i<_collisionList.size();i++)
	{
		if(_collisionList[i]->getPosition() == quad->getPosition())
			{
			 _collisionList.erase(_collisionList.begin()+i); 
			 //cout<<"collisionManager.cpp: deleted QUAD at "<< quad->getPosition();
			}
		
	}



}

void CollisionManager::deleteAsTarget(Quad* quad)
{
	for(int i = 1;i<_targetList.size();i++)
	{
		if(!_targetList[i]->getVisibility())
		{
			_targetList.erase(_targetList.begin()+i);  
		}
	}
}

void CollisionManager::deleteAsTriggerTarget(Quad* quad)
{
	for(int i = 1;i<_triggerList.size();i++)
	{
		if(!_triggerList[i]->getVisibility())
		{
			_targetList.erase(_targetList.begin()+i);  
		}
	}
}


/*
       Checking if the TARGET has collision registered with the 
	   objects in the <_colliasionList>
*/
void CollisionManager::runCollisionEngine()
{

	for(unsigned short i = 0;i<_targetList.size();i++)
	{
	   for( unsigned short j = 0;j< _collisionList.size();j++)
	   {
		   if(_targetList[i]->Intersects(*_collisionList[j]))
		   {
			   _targetList[i]->setCollision(true);
			   _collisionList[j]->setCollision(true);
			   //_targetList[i]->setVisibility(false);
			   //_collisionList[j]->setVisibility(false);
			   //cout<<"CollisionManager.cpp: [Intersection Object] w h l "<<_collisionList[j]<<endl;

		   }
	   }
	}  // end for


}


/*
      Just triggering behaviour
*/
void CollisionManager::runTriggerEngine()
{

	for(unsigned short i = 0;i<_triggerTargetList.size();i++)
	{
	   for( unsigned short j = 0;j< _triggerList.size();j++)
	   {
		   if(_triggerTargetList[i]->Intersects(*_triggerList[j]))
		   {
			   _triggerTargetList[i]->setTrigger(true);
			   _triggerList[j]->setTrigger(true);
		   }
	   }
	}  // end for


}
