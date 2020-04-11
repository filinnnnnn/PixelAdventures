//
//  HeroData.hpp
//  PixelAdventure
//
//  Created by user on 02.04.2020.
//

#pragma once

#include "iGameComponent.hpp"

class HeroData : public IGameData<HeroData>
{
public:
    HeroData (const std::string& name);
    
    const std::string& name () const;
    void setName (const std::string& name);
    
private:
    std::string m_name;
};
    
