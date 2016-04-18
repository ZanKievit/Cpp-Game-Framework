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
    
private:
    void Init();
    
};

#endif /* Gameobject_h */
