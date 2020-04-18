//
//  GameType.h
//  PixelAdventure
//
//  Created by user on 14.04.2020.
//

#pragma once

#include <assert.h>
#define ASSERT(a) assert(a);

enum AnimationType {
    SD_StepLeft,
    SD_StepRight,
    SD_Jump,
    SD_Idle
};
