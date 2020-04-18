//
//  HeroAnimation.hpp
//  PixelAdventure
//
//  Created by user on 14.04.2020.
//

#pragma once

#include "cocos2d.h"
#include "GameTypes.h"

class HeroView;

class HeroAnimation
{
public:
    static HeroAnimation* start(HeroView* view, AnimationType type);
    static bool stop(HeroAnimation* animation);
    
    ~HeroAnimation();
    
    
private:
    HeroAnimation(HeroView* view, AnimationType type);
    cocos2d::Action* runAnimation(AnimationType type);
    bool stopAnimation(cocos2d::Action* animation);

    cocos2d::Action* createJumpAnimation();
    cocos2d::Action* createIdleAnimation();
    cocos2d::Action* createRunAnimation();
    
    HeroView* m_view;
    AnimationType m_type;
};
