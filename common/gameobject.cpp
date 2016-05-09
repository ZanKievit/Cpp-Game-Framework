#include "gameobject.h"

Gameobject::Gameobject(){
    posx = 0;
    posy = 0;
    rotation = 0;
    scalex = 1;
    scaley = 1;
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