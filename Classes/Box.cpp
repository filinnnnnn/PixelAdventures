//
//  Box.cpp
//  PixelAdventure
//
//  Created by user on 07.04.2020.
//

#include "Box.hpp"

Box::Box(): m_box(nullptr) {}

bool Box::init()
{
    return true;
}



Box* Box::withPath(const std::string& path)
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

cocos2d::Sprite* Box::body() {
    if (m_box == nullptr && m_path.length() > 0) {
        cocos2d::Size size = cocos2d::Director::getInstance()->getWinSize();
        m_box = cocos2d::Sprite::create(m_path);
        this->addChild(m_box);
    }
    return m_box;
}
