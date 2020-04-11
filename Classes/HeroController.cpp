//
//  HeroController.cpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//
#include "HeroController.hpp"
#include "HeroView.hpp"

#include <iostream>

HeroController::HeroController() {
    m_view = nullptr;
}

bool HeroController::init()
{
    auto listener = cocos2d::EventListenerKeyboard::create();
    auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
       
    listener->onKeyPressed = CC_CALLBACK_2(HeroController::keyDown, this);
    listener->onKeyReleased = CC_CALLBACK_2(HeroController::keyUp, this);
       
    dispatcher->addEventListenerWithSceneGraphPriority(listener, m_view);
    
}

void HeroController::setView(HeroView* view) {
    if (m_view == nullptr) {
        m_view = view;
        init();
    } else { ASSERT(0); }
}

void HeroController::keyDown (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)
{
    cocos2d::Vec2 loc = event->getCurrentTarget()->getPosition();
    
    switch(code)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_A:
            m_view->createRunLeftAction();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_D:
            m_view->createRunRightAction();
            m_view->createRunAnimation();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_W:
            m_view->createJumpAction();
            m_view->createJumpAnimation();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_S:
            break;
        default:
            m_view->createIdleAnimation();
    }
    
}

void HeroController::keyUp (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)
{
    cocos2d::Vec2 loc = event->getCurrentTarget()->getPosition();
    
    
    switch(code)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_A:
            m_view->stopRunLeftAction();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_D:
            m_view->stopRunRightAction();
            m_view->stopRunAnimation();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_W:
            m_view->stopJumpAction();
            m_view->stopJumpAnimation();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_S:
            break;
        default:
            m_view->createIdleAnimation();
    }
}



