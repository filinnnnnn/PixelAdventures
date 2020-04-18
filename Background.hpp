//
//  Background.hpp
//  PixelAdventure
//
//  Created by user on 06.04.2020.
//

#pragma once
#include "cocos2d.h"
#include "iGameComponent.hpp"

class Box;

typedef std::vector<std::vector<Box *>> BoxGrid;

class Background : public cocos2d::Sprite 
{
public:
    Background();
    ~Background();
    
    Background* withPath(const std::string& path);
    Background* withSize(int width, int height);
    
    bool init() ;
    Background* body();
    CREATE_FUNC(Background);
    
private:
    BoxGrid m_grid;
    std::string m_path;
    int m_width;
    int m_height;
};

