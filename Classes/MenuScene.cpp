//
//  MenuScene.cpp
//  PixelAdventure
//
//  Created by user on 30.03.2020.
//

#include "MenuScene.hpp"

#define ASSERT(a) assert(a);

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

bool MenuScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    cocos2d::Size size = cocos2d::Director::getInstance()->getWinSize();
        
    auto normalPlay = Sprite::create("Play.png");
    auto selectedPlay = Sprite::create("Play.png");
    selectedPlay->setColor(Color3B::GRAY);
    auto playItem = MenuItemSprite::create(normalPlay, selectedPlay, [](Ref* sender)
    {
        Director::getInstance()->pushScene(TransitionFade::create(1.5f, GameScene::createScene()));
        CCLOG("tapped playItem");
    });
    playItem->setPosition(size.width / 2, 400);
    playItem->setScale(2.0f);

    
    auto normalSettings = Sprite::create("Settings.png");
    auto selectedSettings = Sprite::create("Settings.png");
    selectedSettings->setColor(Color3B::GRAY);
    auto settingsItem = MenuItemSprite::create(normalSettings, selectedSettings, [](Ref* sender)
    {
        CCLOG("tapped settingsItem");
    });
    settingsItem->setPosition(size.width / 2, 300);
    
    auto normalClose = Sprite::create("Close.png");
    auto selectedClose = Sprite::create("Close.png");
    selectedClose->setColor(Color3B::GRAY);
    auto closeItem = MenuItemSprite::create(normalClose, selectedClose, [](Ref* sender)
    {
        Director::getInstance()->end();
        CCLOG("tapped closeItem");
    });
    closeItem->setPosition(size.width / 2, 200);

    auto menu = Menu::create(playItem, settingsItem, closeItem,  nullptr);
    menu->setPosition(Vec2());
    menu->setScale(1.5f);
    this->addChild(menu, 1);
    
    auto background = Background::create()->
           withPath("Blue.png")->
           withSize(20, 20);
    this->addChild(background, 0);
    
    auto listener = cocos2d::EventListenerKeyboard::create();
    auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    listener->onKeyPressed = CC_CALLBACK_2(MenuScene::keyDown, this);
    listener->onKeyReleased = CC_CALLBACK_2(MenuScene::keyUp, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, playItem);

    return true;
}


void MenuScene::keyDown (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)
{
    switch (code)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_ENTER:
        
        Director::getInstance()->pushScene(TransitionFade::create(1.5f, GameScene::createScene()));
        std::cout << "ENTER_DOWN ";
            break;
            
        default:
            break;
            
    }
}

void MenuScene::keyUp (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)
{
    switch (code)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_ENTER:
        
        std::cout << "ENTER_UP ";
            break;
            
        default:
            break;
    }
}
