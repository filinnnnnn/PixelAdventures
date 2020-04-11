//
//  HeroView.cpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//
#include "HeroView.hpp"

auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

HeroView::HeroView () : IGameView(new HeroData("Greettings, Hero!"), new HeroController)
{
    controller()->setView(this);
}

cocos2d::Action* HeroView::createIdleAnimation()
{
    auto idleAnimation = cocos2d::Animation::create();
    for (int i = 1; i <= 10; i++)
    {
        std::string name = cocos2d::StringUtils::format("Idle-%0d.png", i);
        idleAnimation->addSpriteFrameWithFile(name.c_str());
    }
    idleAnimation->setDelayPerUnit(0.1f);
    idleAnimation->setRestoreOriginalFrame(true);
    auto idleAction = cocos2d::Animate::create(idleAnimation);
    auto idleHero = m_hero->runAction(idleAction);
    return idleHero;
}

cocos2d::Action* HeroView::createJumpAnimation()
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
    auto jumpHero = m_hero->runAction(jumpAction);
    return jumpHero;
}

cocos2d::Action* HeroView::createRunAnimation()
{
    auto runAnimation = cocos2d::Animation::create();
    for (int i=1; i <= 11; i++)
    {
        std::string name = cocos2d::StringUtils::format("Run-%0d.png", i);
        runAnimation->addSpriteFrameWithFile(name.c_str());
    }
    runAnimation->setDelayPerUnit(0.1f);
    runAnimation->setRestoreOriginalFrame(true);
    auto runAction = cocos2d::Animate::create(runAnimation);
    auto runHero = m_hero->runAction(runAction);
    return runHero;
}

cocos2d::Action* HeroView::createRunRightAction()
{
    auto run = cocos2d::MoveBy::create(0.5f, cocos2d::Vec2(10, 0));
    auto runAction = m_hero->runAction(run);
    return runAction;
}

cocos2d::Action* HeroView::createRunLeftAction()
{
    auto run = cocos2d::MoveBy::create(0.5f, cocos2d::Vec2(-10, 0));
    auto runAction = m_hero->runAction(run);
    return runAction;
}
cocos2d::Action* HeroView::createJumpAction()
{
    auto jump = cocos2d::JumpBy::create(1.0f, cocos2d::Vec2(0, 0), 150.0f, 1);
    auto jumpAction = m_hero->runAction(jump);
    return jumpAction;
}

void HeroView::stopRunRightAction()
{
    m_hero->stopAction(createRunRightAction());
}

void HeroView::stopRunLeftAction()
{
    m_hero->stopAction(createRunLeftAction());
}
void HeroView::stopRunAnimation()
{
    m_hero->stopAction(createRunAnimation());
}

void HeroView::stopJumpAction()
{
    m_hero->stopAction(createJumpAction());
}

void HeroView::stopJumpAnimation()
{
    m_hero->stopAction(createJumpAnimation());
}

bool HeroView::init()
{
    m_hero = cocos2d::Sprite::create("Idle-0.png");
    m_hero->setPosition(cocos2d::Vec2(100, 200));
    this->addChild(m_hero);
    
    return true;
};



