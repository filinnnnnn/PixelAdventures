//
//  HeroController.hpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//

#pragma once

#include "iGameComponent.hpp"

class HeroView; // Forward Declaration

class HeroController : public IGameController
{
public:
    
    HeroController();
    virtual bool init() override;
    
    void setView(HeroView* view);

    void keyDown (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event);
    void keyUp (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event);

private:
    HeroView* m_view;
};
