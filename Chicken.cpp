//
//  Chiken.cpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//

#include "Chicken.hpp"
#include "Box.hpp"

cocos2d::Sprite* Chicken::spawnChicken(float x, float y)
{
    m_chicken = Box::create()->withPath("chicken-0.png")->withPhysics(32, 32, true, 2, true, 1, 1)->setBitmasks(0x03, 0x04);
    m_chicken->body()->setPosition(cocos2d::Vec2(x, y));
    return m_chicken;
};

bool Chicken::init()
{
    this->addChild(spawnChicken(500.0, 200.0));
    
    auto idleAnimation = cocos2d::Animation::create();
    for (int i=1; i<=10; i++)
    {
        std::string name = cocos2d::StringUtils::format("chicken-%0d.png", i);
        idleAnimation->addSpriteFrameWithFile(name.c_str());
    }
    idleAnimation->setDelayPerUnit(0.1f);
    idleAnimation->setRestoreOriginalFrame(true);

    auto idleAction = cocos2d::Animate::create(idleAnimation);
    m_chicken->body()->runAction(cocos2d::RepeatForever::create(idleAction));
    
    
    auto runAnimation = cocos2d::Animation::create();
    for (int i=1; i<=13; i++)
    {
        std::string name = cocos2d::StringUtils::format("chickenrun-%0d.png", i);
        runAnimation->addSpriteFrameWithFile(name.c_str());
    }
    runAnimation->setDelayPerUnit(0.1f);
    runAnimation->setRestoreOriginalFrame(true);
    
    auto runAction = cocos2d::Animate::create(runAnimation);
    m_chicken->body()->runAction(cocos2d::RepeatForever::create(runAction));
    
    cocos2d::Vec2 point = m_chicken->body()->getPosition();
    float x = point.x;
    float y = point.y;
    
    auto run = cocos2d::MoveBy::create(1.5f ,cocos2d::Vec2(-100, 0));
    auto jump = cocos2d::JumpBy::create(1.0f, cocos2d::Vec2(-50, 0), 50.0f, 1);

    auto action = cocos2d::Sequence::create(run, jump, nullptr);
    m_chicken->body()->runAction(cocos2d::RepeatForever::create (action));
    

    
    return true;
};
