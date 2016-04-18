#include "gameobject.h"

#include <common/renderer.h>
#include <common/sprite.h>

gameobject::gameobject(){
   
}

gameobject::~gameobject(){
    deleteSprite();
}

void gameobject::addSprite(Sprite* spr)
{
    deleteSprite();
    _sprite = new Sprite();
    *_sprite = *spr;
}