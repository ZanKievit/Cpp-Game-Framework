#ifndef gameobject_h
#define gameobject_h

#include <stdio.h>
#include <stdlib.h>

#include <common/renderer.h>
#include <common/sprite.h>

class gameobject
{
public:
    gameobject();
    virtual ~gameobject();
    
    void addSprite(Sprite* spr);
    void addSprite(const std::string& filename);
    
private:
    
    Sprite* _sprite;
    
    void deleteSprite() {
        if (_sprite != NULL) {
            delete _sprite;
            _sprite = NULL;
        }
    };
};

#endif /* Gameobject_h */
