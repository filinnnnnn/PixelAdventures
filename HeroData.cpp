//
//  HeroData.cpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//

#include "HeroData.hpp"
#include "iGameComponent.hpp"

HeroData::HeroData (const std::string& name) : m_name(name) {}

const std::string& HeroData::name () const
{
    return m_name;
}

void HeroData::setName (const std::string& name)
{
    if (m_name == name) {
        return;
    }
    m_name = name;
    IGameData::publish(this, GameProp::GP_Name);
};
