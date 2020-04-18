//
//  HeroView.cpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//
#include "HeroView.hpp"
#include "Box.hpp"

auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

HeroView::HeroView () : IGameView(new HeroData("Greettings, Hero!"), new HeroController), m_hero(nullptr)
{
}

Box* HeroView::hero() const {
    return m_hero;
}

bool HeroView::init()
{
    m_hero = Box::create()->withPath("Idle-0.png")->withPhysics(32, 32, true, 1, true, 5, 100)->setBitmasks(0x01, 0x02);
    m_hero->body()->setPosition(cocos2d::Vec2(100, 200));
    m_hero->body()->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
    this->addChild(m_hero);
    controller()->setView(this);
    return true;
};



