//
//  Box.cpp
//  PixelAdventure
//
//  Created by user on 07.04.2020.
//

#include "Box.hpp"
#include "GameTypes.h"

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

Box* Box::withPhysics(double width, double height, bool dynamic, int tag, bool gravity, int bitmask, int mass) {
    if (m_box) {
        auto physicsBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(width, height),
                                cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(dynamic);
        physicsBody->setGravityEnable(gravity);
        physicsBody->setTag(tag);
        physicsBody->setContactTestBitmask(bitmask);
        physicsBody->addMass(mass);
        
        m_box->addComponent(physicsBody);
        return this;
    }
    ASSERT(0);
    return nullptr;
}

Box* Box::setBitmasks(int categoryBitmask, int collisionBitmask)
{
    m_box->getPhysicsBody()->setCategoryBitmask(categoryBitmask);
    m_box->getPhysicsBody()->setCollisionBitmask(collisionBitmask);
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
