//
//  HeroController.cpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//
#include "HeroController.hpp"
#include "HeroView.hpp"
#include "Box.hpp"

#include "HeroAnimation.hpp"

#include <iostream>

HeroController::HeroController():
    m_idleAnimation(nullptr),
    m_stepRightAnimation(nullptr),
    m_jumpAnimation(nullptr)
{
    m_view = nullptr;
}

HeroController::~HeroController() {
    delete m_idleAnimation;
    delete m_stepRightAnimation;
    delete m_jumpAnimation;
    
    m_idleAnimation = nullptr;
    m_stepRightAnimation = nullptr;
    m_jumpAnimation = nullptr;
}

bool HeroController::init()
{
    auto listener = cocos2d::EventListenerKeyboard::create();
    auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
       
    listener->onKeyPressed = CC_CALLBACK_2(HeroController::keyDown, this);
    listener->onKeyReleased = CC_CALLBACK_2(HeroController::keyUp, this);
       
    dispatcher->addEventListenerWithSceneGraphPriority(listener, m_view->hero()->body());
    
    m_idleAnimation = HeroAnimation::start(m_view, SD_Idle);
    
    return true;
    
    //listener->onKeyPressed
    
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
            HeroAnimation::stop(m_idleAnimation);
            m_idleAnimation = nullptr;
            createRunLeftAction();
            m_stepRightAnimation = HeroAnimation::start(m_view, SD_StepRight);
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_D:
            HeroAnimation::stop(m_idleAnimation);
            m_idleAnimation = nullptr;
            createRunRightAction();
            m_stepRightAnimation = HeroAnimation::start(m_view, SD_StepRight);
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_W:
            HeroAnimation::stop(m_idleAnimation);
            m_idleAnimation = nullptr;
            createJumpAction();
            m_jumpAnimation = HeroAnimation::start(m_view, SD_Jump);
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_S:
            break;
        default:
             // Do nothing
            break;
    }
    
}

void HeroController::keyUp (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)
{
    cocos2d::Vec2 loc = event->getCurrentTarget()->getPosition();
    
    
    switch(code)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_A:
            stopRunLeftAction();
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_D:
            
            HeroAnimation::stop(m_stepRightAnimation);
            m_stepRightAnimation = nullptr;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_W:
//            stopJumpAction();
            // HeroAnimation::stop(m_jumpAnimation);
            m_jumpAnimation = nullptr;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_S:
            break;
        default:
            // Do nothing
            break;
    }
}


// ====== Actions

cocos2d::Action* HeroController::createRunRightAction()
{
    auto pos = m_view->hero()->body()->getPosition();
    auto run = cocos2d::MoveTo::create(5.0f, cocos2d::Vec2(1000, 0));
    auto runAction = m_view->hero()->body()->runAction(run);
    return runAction;
}

cocos2d::Action* HeroController::createRunLeftAction()
{
    auto run = cocos2d::MoveTo::create(5.0f, cocos2d::Vec2(-1000, 0));
    auto runAction = m_view->hero()->body()->runAction(run);
    return runAction;
}
cocos2d::Action* HeroController::createJumpAction()
{
    auto pos = m_view->hero()->body()->getPosition();
    auto jump = cocos2d::JumpTo::create(1.8f, cocos2d::Vec2(pos.x, pos.y + 150.0f), 150.0f, 1);
    auto jumpAction = m_view->hero()->body()->runAction(jump);
    return jumpAction;
}

void HeroController::stopJumpAction()
{
    m_view->hero()->body()->stopAction(createJumpAction());
}

void HeroController::stopRunRightAction()
{
    m_view->hero()->body()->stopAction(createRunRightAction());
}

void HeroController::stopRunLeftAction()
{
    m_view->hero()->body()->stopAction(createRunLeftAction());
}
