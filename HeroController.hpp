//
//  HeroController.hpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//

#pragma once

#include "iGameComponent.hpp"

class HeroView; // Forward Declaration
class HeroAnimation;

class HeroController : public IGameController
{
public:
    
    HeroController();
    ~HeroController();
    
    virtual bool init() override;
    
    void setView(HeroView* view);

    void keyDown (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event);
    void keyUp (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event);
    

private:
    cocos2d::Action* createRunRightAction();
    cocos2d::Action* createRunLeftAction();
    cocos2d::Action* createJumpAction();
    void stopJumpAction();
    void stopRunRightAction();
    void stopRunLeftAction();
    
    HeroAnimation* m_idleAnimation;
    HeroAnimation* m_stepRightAnimation;
    HeroAnimation* m_jumpAnimation;
    
    HeroView* m_view;
};
