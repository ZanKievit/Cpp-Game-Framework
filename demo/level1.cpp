#include "level1.h"

Level1::Level1(){
    start();
}

Level1::~Level1(){
    delete playerSprite;
    delete _player;
}

void Level1::Update()
{
    _player->setWindow(_window);
    _player->move();
    if(_player->IsCollidingWith(_ground) || _player->IsCollidingWith(_ground2) || _player->IsCollidingWith(_ground3) ||
       _player->IsCollidingWith(_ground4) || _player->IsCollidingWith(_ground5) || _player->IsCollidingWith(_ground6) ||
       _player->IsCollidingWith(_ground7)){
        _player->isOnGround();
    }else{
        _player->isOffGround();
    }
    
    if(_player->IsCollidingWith(_spike1) || _player->IsCollidingWith(_spike2)){
        reset();
    }
    
    if(_player->IsCollidingWith(end)){
        this->stopRunning();
    }
}

void Level1::start(){
    playerSprite->setSprite(128, 128, "assets/island.bmp");
    groundSprite->setSprite(128, 128, "assets/ground.bmp");
    spikeSprite->setSprite(128, 64, "assets/spikes_small.bmp");
    endSprite->setSprite(128, 128, "assets/end.bmp");
    _player->addSprite(playerSprite);
    _ground->addSprite(groundSprite);
    _ground2->addSprite(groundSprite);
    _ground3->addSprite(groundSprite);
    _ground4->addSprite(groundSprite);
    _ground5->addSprite(groundSprite);
    _ground6->addSprite(groundSprite);
    _ground7->addSprite(groundSprite);
    _spike1->addSprite(spikeSprite);
    _spike2->addSprite(spikeSprite);
    end->addSprite(endSprite);
    
    this->addChild(_player);
    this->addChild(_ground);
    this->addChild(_ground2);
    this->addChild(_ground3);
    this->addChild(_ground4);
    this->addChild(_ground5);
    this->addChild(_ground6);
    this->addChild(_ground7);
    this->addChild(_spike1);
    this->addChild(_spike2);
    this->addChild(end);
    
    _player->posx = 100;
    _player->posy = 500;
    _ground->posx = 100;
    _ground->posy = 650;
    _ground2->posx = 228;
    _ground2->posy = 650;
    _ground3->posx = 356;
    _ground3->posy = 650;
    _ground4->posx = 484;
    _ground4->posy = 650;
    _ground5->posx = 612;
    _ground5->posy = 650;
    _ground6->posx = 740;
    _ground6->posy = 650;
    _spike2->posx = 868;
    _spike2->posy = 682;
    _spike1->posx = 996;
    _spike1->posy = 682;
    _ground7->posx = 1124;
    _ground7->posy = 650;
    end->posx = 1252;
    end->posy = 522;
}

void Level1::reset(){
    _player->posx = 100;
    _player->posy = 500;
}