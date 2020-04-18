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

class Box;

class HeroView : public IGameView <HeroData, HeroController>
{
public:
    HeroView ();
    
    Box* hero() const;
    
    virtual bool init() override;
    CREATE_FUNC(HeroView);

private:
    Box* m_hero;
};
