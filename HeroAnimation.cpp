//
//  HeroAnimation.cpp
//  PixelAdventure
//
//  Created by user on 14.04.2020.
//

#include "HeroAnimation.hpp"
#include "HeroView.hpp"
#include "Box.hpp"
#include <iostream>

static std::map<HeroAnimation* , cocos2d::Action*> animations;


HeroAnimation* HeroAnimation::start(HeroView* view, AnimationType type) {
    HeroAnimation* animation = new HeroAnimation(view, type);
    animations[animation] = animation->runAnimation(type);
    return animation;
}

bool HeroAnimation::stop(HeroAnimation* animation) {
    
    if (!animation) return;
    
    auto animIt = animations.find(animation);
    if (animIt != animations.end()) {
        animIt->first->stopAnimation(animIt->second);
        delete animIt->first;
        animations.erase(animIt);
        return true;
    }
    ASSERT(0);
    return false;
}

HeroAnimation::HeroAnimation(HeroView* view, AnimationType type): m_view(view), m_type(type) {
    
}

HeroAnimation::~HeroAnimation() {}

cocos2d::Action* HeroAnimation::runAnimation(AnimationType type) {
    
    switch (type) {
        case SD_Idle:
            return this->createIdleAnimation();
        case SD_Jump:
            return this->createJumpAnimation();
        case SD_StepLeft:
            return this->createRunAnimation();
        case SD_StepRight:
            return this->createRunAnimation();
    }
    ASSERT(0);
    return nullptr;
}

bool HeroAnimation::stopAnimation(cocos2d::Action* animation) {
    m_view->hero()->body()->stopAction(animation);
}



// ====== Animations

cocos2d::Action* HeroAnimation::createIdleAnimation()
{
    auto idleAnimation = cocos2d::Animation::create();
    for (int i = 1; i <= 10; i++)
    {
        std::string name = cocos2d::StringUtils::format("Idle-%0d.png", i);
        idleAnimation->addSpriteFrameWithFile(name.c_str());
    }
    idleAnimation->setDelayPerUnit(0.1f);
    idleAnimation->setRestoreOriginalFrame(true);
    auto idleAction = cocos2d::RepeatForever::create(cocos2d::Animate::create(idleAnimation));
    auto idleHero = m_view->hero()->body()->runAction(idleAction);
    
    return idleHero;
}

cocos2d::Action* HeroAnimation::createJumpAnimation()
{
    auto jumpAnimation = cocos2d::Animation::create();
    for (int i=1; i <= 2; i++)
    {
        std::string name = cocos2d::StringUtils::format("Jump-%1d.png", i);
        jumpAnimation->addSpriteFrameWithFile(name.c_str());
    }
    jumpAnimation->setDelayPerUnit(0.5f);
    jumpAnimation->setRestoreOriginalFrame(true);
    auto jumpAction = cocos2d::Animate::create(jumpAnimation);
    auto jumpHero = m_view->hero()->body()->runAction(jumpAction);
    return jumpHero;
}

cocos2d::Action* HeroAnimation::createRunAnimation()
{
    auto runAnimation = cocos2d::Animation::create();
    for (int i=1; i <= 11; i++)
    {
        std::string name = cocos2d::StringUtils::format("Run-%0d.png", i);
        runAnimation->addSpriteFrameWithFile(name.c_str());
    }
    runAnimation->setDelayPerUnit(0.05f);
    runAnimation->setRestoreOriginalFrame(true);
    auto runAction = cocos2d::Animate::create(runAnimation);
    auto runHero = m_view->hero()->body()->runAction(runAction);
    return runHero;
}
