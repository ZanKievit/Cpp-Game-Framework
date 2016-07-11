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
    
    if(_player->IsGroundedOn(_ground) || _player->IsGroundedOn(_ground2) || _player->IsGroundedOn(_ground3) ||
       _player->IsGroundedOn(_ground4) || _player->IsGroundedOn(_ground5) || _player->IsGroundedOn(_ground6) ||
       _player->IsGroundedOn(_ground7) || _player->IsGroundedOn(_ground8)){
        _player->isOnGround();
    }else{
        _player->isOffGround();
    }
    
    if(_player->IsCollidingLeftSide(_ground) || _player->IsCollidingLeftSide(_ground2) || _player->IsCollidingLeftSide(_ground3) ||
    _player->IsCollidingLeftSide(_ground4) || _player->IsCollidingLeftSide(_ground5) || _player->IsCollidingLeftSide(_ground6) ||
    _player->IsCollidingLeftSide(_ground7) || _player->IsCollidingLeftSide(_ground8)){
        _player->isColLeft();
    }else{
        _player->isNotColLeft();
    }
    
    if(_player->IsCollidingRightSide(_ground) || _player->IsCollidingRightSide(_ground2) || _player->IsCollidingRightSide(_ground3) ||
       _player->IsCollidingRightSide(_ground4) || _player->IsCollidingRightSide(_ground5) || _player->IsCollidingRightSide(_ground6) ||
       _player->IsCollidingRightSide(_ground7) || _player->IsCollidingRightSide(_ground8)){
        _player->isColRight();
    }else{
        _player->isNotColRight();
    }
     
    
    if(_player->IsGroundedOn(_spike1) || _player->IsGroundedOn(_spike2)){
        reset();
    }
    
    if(_player->IsGroundedOn(end) || _player->IsCollidingLeftSide(end) || _player->IsCollidingRightSide(end)){
        this->stopRunning();
    }
}

void Level1::start(){
    playerSprite = new Sprite();
    groundSprite = new Sprite();
    spikeSprite = new Sprite();
    endSprite = new Sprite();
    _player = new Player();
    _ground = new Gameobject();
    _ground2 = new Gameobject();
    _ground3 = new Gameobject();
    _ground4 = new Gameobject();
    _ground5 = new Gameobject();
    _ground6 = new Gameobject();
    _ground7 = new Gameobject();
    _ground8 = new Gameobject();
    _spike1 = new Gameobject();
    _spike2 = new Gameobject();
    end = new Gameobject();
    
    playerSprite->setSprite(128, 128, "assets/player.bmp");
    groundSprite->setSprite(128, 128, "assets/ground.bmp");
    spikeSprite->setSprite(128, 64, "assets/spike.bmp");
    endSprite->setSprite(128, 128, "assets/end.bmp");
    
    _player->addSprite(playerSprite);
    _ground->addSprite(groundSprite);
    _ground2->addSprite(groundSprite);
    _ground3->addSprite(groundSprite);
    _ground4->addSprite(groundSprite);
    _ground5->addSprite(groundSprite);
    _ground6->addSprite(groundSprite);
    _ground7->addSprite(groundSprite);
    _ground8->addSprite(groundSprite);
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
    this->addChild(_ground8);
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
    _ground8->posx = 484;
    _ground8->posy = 522;
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