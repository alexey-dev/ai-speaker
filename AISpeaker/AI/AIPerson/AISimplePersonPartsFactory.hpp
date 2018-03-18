//
//  AISimplePersonFactory.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AISimplePersonFactory_hpp
#define AISimplePersonFactory_hpp

#include "AIPersonPartsAbstarctFactory.hpp"

class IAIPerson;

//----------------------------------------------------
class AISimplePersonPartsFactory : public IAIPersonPartsAbstarctFactory
{
public:
    virtual IAIPersonBrain* CreateAIBrain( IAIPerson& aiPerson ) override;
    virtual IAIPersonMemory* CreateAIMemory( IAIPerson& aiPerson ) override;
};
//----------------------------------------------------

#endif /* AISimplePersonFactory_hpp */
