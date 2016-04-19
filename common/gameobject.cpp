#include "gameobject.h"

Gameobject::Gameobject(){
   
}

Gameobject::~Gameobject(){
    deleteSprite();
}

void Gameobject::addSprite(Sprite* spr)
{
    deleteSprite();
    _sprite = new Sprite();
    *_sprite = *spr;
}