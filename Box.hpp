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
    Box* withPhysics(double width,
                     double height,
                     bool dynamic = false,
                     int tag = 0,
                     bool gravity = false,
                     int bitmask = 0,
                     int mass = 0);
    
    Box* setBitmasks(int categoryBitmask, int collisionBitmask);

    bool init() ;
    CREATE_FUNC(Box);
    
    void setDynamic(bool dynamic);
    
private:
    
    //void updateSprite();
    cocos2d::Sprite* m_box;
    std::string m_path;
};
