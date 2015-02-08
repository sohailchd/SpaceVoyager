
#include "ISceneNode.h"




ISceneNode::ISceneNode(){}
ISceneNode::~ISceneNode(){}	


void ISceneNode::initScene(){}
void ISceneNode::display_fn_game(){}
void ISceneNode::idle_fn_game(){}
void ISceneNode::keyboard_fn_game(unsigned char& key,int& x, int& y){}
void ISceneNode::special_fn_game(int& key , int& x, int& y){}
void ISceneNode::timer_fn_game(int n){}



