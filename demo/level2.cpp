#include "level2.h"

Level2::Level2(){
    playerSprite->setSprite(128, 128, "assets/island.bmp");
    groundSprite->setSprite(128, 128, "assets/ground.bmp");
    _player->addSprite(playerSprite);
    _ground->addSprite(groundSprite);
    _ground2->addSprite(groundSprite);
    _ground3->addSprite(groundSprite);
    _ground4->addSprite(groundSprite);
    _ground5->addSprite(groundSprite);
    _ground6->addSprite(groundSprite);
    _ground7->addSprite(groundSprite);
    this->addChild(_player);
    this->addChild(_ground);
    this->addChild(_ground2);
    this->addChild(_ground3);
    this->addChild(_ground4);
    this->addChild(_ground5);
    this->addChild(_ground6);
    this->addChild(_ground7);
    
    _player->posx = 100;
    _player->posy = 522;
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
    _ground7->posx = 868;
    _ground7->posy = 650;
}

Level2::~Level2(){
    delete playerSprite;
    delete _player;
}

void Level2::Update()
{
    _player->setWindow(_window);
    _player->move();
    if(_player->IsGroundedOn(_ground) || _player->IsGroundedOn(_ground2) || _player->IsGroundedOn(_ground3) ||
       _player->IsGroundedOn(_ground4) || _player->IsGroundedOn(_ground5) || _player->IsGroundedOn(_ground6)||
       _player->IsGroundedOn(_ground7)){
        _player->isOnGround();
    }else{
        _player->isOffGround();
    }
}