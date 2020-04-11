//
//  HeroView.hpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//
#pragma once

#include "iGameComponent.hpp"
#include "HeroData.hpp"
#include "HeroController.hpp"

class HeroView : public IGameView <HeroData, HeroController>
{
public:
    HeroView ();
    cocos2d::Action* createHero();
    
    cocos2d::Action* createJumpAnimation();
    cocos2d::Action* createIdleAnimation();
    cocos2d::Action* createRunAnimation();
    
    cocos2d::Action* createRunRightAction();
    cocos2d::Action* createRunLeftAction();
    cocos2d::Action* createJumpAction();
    
    void stopRunRightAction();
    void stopRunLeftAction();
    void stopRunAnimation();
    void stopJumpAction();
    void stopJumpAnimation();

    virtual bool init() override;
    CREATE_FUNC(HeroView);

private:
    cocos2d::Sprite* m_hero;
};
