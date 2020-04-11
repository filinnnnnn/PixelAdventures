//
//  Chiken.hpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//

#pragma once
#include "cocos2d.h"
#include "iGameComponent.hpp"

class Chicken : public cocos2d::Sprite
{
public:
    bool init() ;
    CREATE_FUNC(Chicken);
    
private:
    cocos2d::Sprite* m_chicken;
};

