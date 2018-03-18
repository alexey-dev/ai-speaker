//
//  AIPersonAbstarctFactory.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIPersonAbstarctFactory_hpp
#define AIPersonAbstarctFactory_hpp

#include "AIPersonBrain.hpp"
#include "AIPersonMemory.hpp"

class IAIPerson;

//----------------------------------------------------
class IAIPersonPartsAbstarctFactory
{
public:
    virtual ~IAIPersonPartsAbstarctFactory(){};
    virtual IAIPersonBrain* CreateAIBrain( IAIPerson& aiPerson ) = 0;
    virtual IAIPersonMemory* CreateAIMemory( IAIPerson& aiPerson ) = 0;
};
//----------------------------------------------------

#endif /* AIPersonAbstarctFactory_hpp */
