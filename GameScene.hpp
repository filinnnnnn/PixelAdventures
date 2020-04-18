//
//  GameScene.hpp
//  PixelAdventure
//
//  Created by user on 01.04.2020.
//

#pragma once

#include "cocos2d.h"

#include "MenuScene.hpp"
#include "HeroView.hpp"
#include "Chicken.hpp"
#include "Background.hpp"

class HeroView;

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
    
private:
    HeroView* m_heroView;
};
