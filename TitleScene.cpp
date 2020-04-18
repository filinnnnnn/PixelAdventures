/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include <iostream>
#include "TitleScene.h"

#define ASSERT(a) assert(a);

USING_NS_CC;

Scene* TitleScene::createScene()
{
    return TitleScene::create();
}

bool TitleScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto size = Director::getInstance()->getWinSize();
    
    auto labelPixel = Label::createWithTTF("PIXEL", "pixel.ttf", 280);
    if (labelPixel == nullptr) {ASSERT(0)}
    else
    {
        labelPixel->setPosition(cocos2d::Vec2(size.width/2, 600));
        labelPixel->setColor(Color3B::YELLOW);
        labelPixel->enableShadow(Color4B::ORANGE, Size(-10, 5), 0);
        this->addChild(labelPixel);
    }
    
    auto labelAdventure = Label::createWithTTF("ADVENTURE", "pixel.ttf", 140);
    if (labelAdventure == nullptr) {ASSERT(0)}
    else
    {
        labelAdventure->setPosition(Vec2(size.width/2, 400));
        labelAdventure->setColor(Color3B::YELLOW);
        labelAdventure->enableShadow(Color4B::ORANGE, Size(-10, 5), 0);
        this->addChild(labelAdventure);
    }
    
    auto labelPressSpace = Label::createWithTTF("press SPACE to continue", "pixel.ttf", 60);
    if (labelPressSpace == nullptr) {ASSERT(0)}
    else
    {
        labelPressSpace->setPosition(Vec2(size.width/2, 100));
        labelPressSpace->setColor(Color3B::WHITE);
        labelPressSpace->enableShadow(Color4B::GRAY, Size(-5, 3), 0);
        this->addChild(labelPressSpace);
    }
    
    auto listener = cocos2d::EventListenerKeyboard::create();
    auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    listener->onKeyPressed = CC_CALLBACK_2(TitleScene::keyDown, this);
    listener->onKeyReleased = CC_CALLBACK_2(TitleScene::keyUp, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, labelPressSpace);
    
    
    return true;
}


void TitleScene::keyDown (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)
{
    switch (code)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
            
//        std::cout << "SPACE_DOWN ";
            break;
            
        default:
            break;
            
    }
}

void TitleScene::keyUp (cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)
{
    switch (code)
    {
        case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
        Director::getInstance()->pushScene(TransitionFade::create(1.5f, MenuScene::createScene()));
//        std::cout << "SPACE_UP ";
            break;
            
        default:
            break;
    }
}
