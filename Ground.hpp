//
//  Ground.hpp
//  PixelAdventure
//
//  Created by user on 15.04.2020.
//

#pragma once
#include "cocos2d.h"
#include "iGameComponent.hpp"

class Box;

typedef std::vector<std::vector<Box *>> BoxGrid;

class Ground : public cocos2d::Sprite
{
public:
    Ground();
    ~Ground();
    
    Ground* withPath(const std::string& path);
    Ground* withSize(int width, int height);
    
    bool init() ;
    Ground* body();
    CREATE_FUNC(Ground);
    
private:
    BoxGrid m_grid;
    std::string m_path;
    int m_width;
    int m_height;
};
