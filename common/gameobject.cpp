#include <iostream>
#include "gameobject.h"

int Gameobject::_nextGuid = 0;

Gameobject::Gameobject(){
    
    _guid = _nextGuid;
    _nextGuid++;
    
    _parent = NULL;
    
    posx = 0;
    posy = 0;
    rotation = 0;
    scalex = 1;
    scaley = 1;
    
    _sprite = NULL;
}

Gameobject::~Gameobject(){
    deleteSprite();
}

void Gameobject::addChild(Gameobject* child)
{
    if(child->_parent != NULL) {
        child->_parent->removeChild(child);
    }
    child->_parent = this;
    this->_children.push_back(child);
}

void Gameobject::removeChild(Gameobject* child)
{
    std::vector< Gameobject* >::iterator it = _children.begin();
    while (it != _children.end()) {
        if ((*it)->_guid == child->_guid) {
            it = _children.erase(it);
        } else {
            ++it;
        }
    }
}

Gameobject* Gameobject::getChild(unsigned int i)
{
    if (i < _children.size()) {
        return _children[i];
    }
    return NULL;
}

void Gameobject::addSprite(Sprite* spr)
{
    deleteSprite();
    _sprite = new Sprite();
    *_sprite = *spr;
}

bool Gameobject:: IsCollidingWith(Gameobject* object){
    float TopLeft = posx - (_sprite->getWidth()/2*scalex) + (_sprite->getHeight()/2*scaley);
    float Bottomright = posy + (_sprite->getWidth()/2*scalex) - (_sprite->getHeight()/2*scaley);
    
    float TopLeft2 =  object->posx - (object->_sprite->getWidth()/2*object->scalex) + (object->_sprite->getHeight()/2*object->scaley);
    float Bottomright2 = object->posy + (object->_sprite->getWidth()/2*object->scalex) - (object->_sprite->getHeight()/2*object->scaley);
    
    
    if((TopLeft >= TopLeft2 && TopLeft <= (TopLeft2 + object->_sprite->getWidth())) ||
       ((TopLeft + _sprite->getWidth()) >= TopLeft2 &&
        (TopLeft + _sprite->getWidth()) <= (TopLeft2 + object->_sprite->getWidth()))){
           if((Bottomright >= Bottomright2 && Bottomright <= (Bottomright2 + object->_sprite->getHeight())) ||
              ((Bottomright + _sprite->getHeight()) >= Bottomright2 &&
               (Bottomright + _sprite->getHeight()) <= (Bottomright2 + object->_sprite->getHeight()))){
                  return true;
            }
       }
    return false;
}