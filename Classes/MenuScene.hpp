//
//  MenuScene.hpp
//  PixelAdventure
//
//  Created by user on 30.03.2020.
//

#pragma once

#include <iostream>
#include "cocos2d.h"
#include "GameScene.hpp"

class MenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);
    
    void keyDown (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event);
    void keyUp (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event);
};


