#include "GameObject.h"
#include <iostream>


int GameObject::GetPos_x() const { return _pos_x; }
int GameObject::GetPos_y() const { return _pos_y; }

void GameObject::SetPos_x(int pos_x){ _pos_x = pos_x; } 
void GameObject::SetPos_y(int pos_y){ _pos_y = pos_y; } 


void GameObject::SetState(GameObject::State state)
{
    this->state = state;
}
