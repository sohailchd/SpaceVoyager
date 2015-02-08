
#include "GameStateManager.h"
#include "MasterHeader.h"

GameStateManager::GameStates GameStateManager::_activeState = _splash;;
GameStateManager::GameStates GameStateManager::_lastState = GameStateManager::_activeState;
GameStateManager::SequenceStates GameStateManager::_currentSequence = GameStateManager::_inPrologue_SQ;
GameStateManager::SequenceStates GameStateManager::_lastSequence = GameStateManager::_lastSequence;
std::vector<ISceneNode*> GameStateManager::_sequenceList ;

float GameStateManager::timeSinceStart  = 0;
float GameStateManager::timeSinceLast   = 0;
float GameStateManager::deltaTime       = 0;



GameStateManager::GameStateManager()
{

}

GameStateManager::~GameStateManager()
{

}

void graphicsDuringGamePlay()
{
  glViewport(0, 0, 800, 600);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat)800*0.8 / (GLfloat)600, 1.0, 100000.0);
  glMatrixMode(GL_MODELVIEW);
  

   //LIGHTING
  GLfloat black[] = { 0.0, 0.0, 0.0, 1.0};
  GLfloat dark[] = { 0.2, 0.15, 0.2, 1.0};
  GLfloat white[] = { 1.0, 1.0, 1.0, 1.0};
  GLfloat direction[] = { 0.2, 0.0, 10.5,0.0};

  glMaterialfv(GL_FRONT, GL_SPECULAR, white);
  glMaterialf(GL_FRONT, GL_SHININESS, 30);
  glLightfv(GL_LIGHT0, GL_AMBIENT , white);
  glLightfv(GL_LIGHT0, GL_DIFFUSE , white);
 // glLightfv(GL_LIGHT0, GL_SPECULAR , white);
  glLightfv(GL_LIGHT0, GL_POSITION , direction);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}



void GameStateManager::setState(GameStateManager::GameStates gs)
{
     GameStateManager::_lastState = _activeState;
     GameStateManager::_activeState = gs;
	
}

void GameStateManager::managerEngine()
{

	switch (GameStateManager::_activeState)
	{
	case GameStates::_splash:
		break;
	case GameStates::_menu:  
		break;
	case GameStates::_inGame:
		graphicsDuringGamePlay();
		break;

	default:
		break;
	}

}


void GameStateManager::addToSequenceList(ISceneNode* node)
{
	GameStateManager::_sequenceList.push_back(node);
}

void GameStateManager::setSequence(GameStateManager::SequenceStates st)
{
	GameStateManager::_lastSequence = GameStateManager::_currentSequence;
	GameStateManager::_currentSequence = st;
}


