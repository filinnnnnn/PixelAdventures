//
//  Ground.cpp
//  PixelAdventure
//
//  Created by user on 15.04.2020.
//

#include "Ground.hpp"
#include "Box.hpp"

Ground::Ground(): m_width(0), m_height(0) {}

Ground::~Ground() {
    for (auto rowIt : m_grid) {
        for (auto boxIt : rowIt) {
            delete boxIt;
            boxIt = nullptr;
        }
        rowIt.clear();
    }
    m_grid.clear();
}

Ground* Ground::withPath(const std::string& path)
{
    if (m_path == path) {
        return;
    }
    m_path = path;
    if (body() == nullptr) {
        // Error
    }
    return this;
}

Ground* Ground::withSize(int width, int height)
{
    m_width = width;
    m_height = height;
    if (body() == nullptr) {
        // Error
    }
    return this;
}

bool Ground::init()
{
    return true;
}

Ground* Ground::body() {
    
    if (m_grid.size() == 0 && m_path.length() > 0 && m_width > 0 && m_height > 0) {
        
        const static double boxWidth = 16;
        const static double boxHeight = 16;
    
        // cocos2d::Size size = cocos2d::Director::getInstance()->getWinSize();
        
        for (int i = 0; i < m_height; ++i)
        {
            m_grid.push_back(std::vector<Box *>(m_height));
            
            for (int j = 0; j < m_width; ++j)
            {
                auto box = Box::create()->withPath(m_path)->withPhysics(16 , 16, false, 10, false, 1000)->setBitmasks(i, j);
                m_grid[i].push_back(box);
                
                double x = boxWidth * j - boxWidth / 2;
                double y = boxHeight * i - boxHeight / 2;
                
                box->body()->setPosition(cocos2d::Vec2(x, y));
                
                this->addChild(box);
            }
        }
        return this;
    }
    return nullptr;
}
