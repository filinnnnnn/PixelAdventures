//
//  Box.hpp
//  PixelAdventure
//
//  Created by user on 07.04.2020.
//

#pragma once 

#include "cocos2d.h"
#include "iGameComponent.hpp"

class Box: public cocos2d::Sprite
{
public:
    
    Box();
    cocos2d::Sprite* body();
    
    Box* withPath(const std::string& path);
    bool init() ;
    CREATE_FUNC(Box);
    
private:
    
    //void updateSprite();
    cocos2d::Sprite* m_box;
    std::string m_path;
};
