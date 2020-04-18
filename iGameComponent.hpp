//
//  iGameComponent.cpp
//  PixelAdventure
//
//  Created by user on 30.03.2020.
//

#pragma once

#include <string>
#include <functional>
#include <map>
#include <vector>

#include "cocos2d.h"
#include "GameTypes.h"


enum GameProp {
    GP_Name,

};

class Rx {};

template <typename GameData>
class IGameData {
public:
    virtual ~IGameData() {}
    Rx* listen(const std::function<void(GameData*, GameProp)>& callback)
    {
        Rx* rx = new Rx;
        m_listeners[rx] = callback;
        return rx;
    }
    
    bool stopListen(Rx* rx)
    {
        auto it = m_listeners.find(rx);
        if (it != m_listeners.end) {
            m_listeners.erase(it);
            delete rx;
            rx = nullptr;
            return true;
        }
        return false;
    }
    
protected:
    void publish (GameData* obj, GameProp prop)
    {
        for (auto listener : m_listeners) {
            listener.second(obj, prop);
        }
    }
    
private:
    std::map <Rx*, std::function<void(GameData*, GameProp)>> m_listeners;
};



class IGameController {
public:
    virtual bool init() { ASSERT(0); }
    virtual ~IGameController() {}
};


template <typename GameData, typename GameController>
class IGameView : public cocos2d::Node
{
public:
    IGameView (GameData* data, GameController* controller) :
        m_data(data), m_controller(controller) {}
    virtual ~IGameView () {}
    
    virtual bool init() { ASSERT(0); }
    
    GameData* data () const
    {
        return m_data;
    }
    
    GameController* controller () const
    {
        return m_controller;
    }
    
private:
    GameData* m_data;
    GameController* m_controller;
};
