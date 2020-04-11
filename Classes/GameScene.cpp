//
//  GameScene.cpp
//  PixelAdventure
//
//  Created by user on 01.04.2020.
//

#include "GameScene.hpp"

#define ASSERT(a) assert(a);

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto background = Background::create()->
        withPath("Green.png")->
        withSize(20, 20);
    
    this->addChild(background, 0);
    this->addChild(HeroView::create(), 1);
    this->addChild(Chicken::create(), 1);
        
    return true;
}
