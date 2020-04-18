//
//  GameScene.cpp
//  PixelAdventure
//
//  Created by user on 01.04.2020.
//

#include "GameScene.hpp"
#include "GameTypes.h"
#include "Ground.hpp"

#define ASSERT(a) assert(a);

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if ( !Scene::initWithPhysics() )
    {
        ASSERT(0);
        return false;
    }
//
    auto background = Background::create()->
        withPath("Green.png")->
        withSize(20, 20);
//
    auto ground = Ground::create()->
        withPath("Ground-38.png")->
        withSize(150, 8);
    
    this->addChild(background, 0);
    this->addChild(ground, 1);
    this->addChild(HeroView::create(), 2);
    this->addChild(Chicken::create(), 3);
    
    auto contactListener =
    EventListenerPhysicsContact::create(); contactListener->onContactBegin = [](PhysicsContact& contact){
    CCLOG("contact begin");
    auto shapeA = contact.getShapeA();
        auto bodyA = shapeA->getBody();
    auto shapeB = contact.getShapeB();
        auto bodyB = shapeB->getBody();
        return true;
    };
        
    return true;
}
