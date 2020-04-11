//
//  Background.cpp
//  PixelAdventure
//
//  Created by user on 06.04.2020.
//

#include "Background.hpp"
#include "Box.hpp"

Background::Background(): m_width(0), m_height(0) {}

Background::~Background() {
    for (auto rowIt : m_grid) {
        for (auto boxIt : rowIt) {
            delete boxIt;
            boxIt = nullptr;
        }
        rowIt.clear();
    }
    m_grid.clear();
}

Background* Background::withPath(const std::string& path)
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

Background* Background::withSize(int width, int height)
{
    m_width = width;
    m_height = height;
    if (body() == nullptr) {
        // Error
    }
    return this;
}

bool Background::init()
{
    return true;
}

Background* Background::body() {
    
    if (m_grid.size() == 0 && m_path.length() > 0 && m_width > 0 && m_height > 0) {
        
        const static double boxWidth = 64;
        const static double boxHeight = 64;
    
        // cocos2d::Size size = cocos2d::Director::getInstance()->getWinSize();
        
        for (int i = 0; i < m_height; ++i)
        {
            m_grid.push_back(std::vector<Box *>(m_height));
            
            for (int j = 0; j < m_width; ++j)
            {
                auto box = Box::create()->withPath(m_path);
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
