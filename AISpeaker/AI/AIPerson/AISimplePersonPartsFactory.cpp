//
//  AISimplePersonFactory.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "AISimplePersonPartsFactory.hpp"

//----------------------------------------------------
IAIPersonBrain*
AISimplePersonPartsFactory::CreateAIBrain( IAIPerson& aiPerson )
{
    return new AISimplePersonBrain(aiPerson);
}
//----------------------------------------------------
IAIPersonMemory*
AISimplePersonPartsFactory::CreateAIMemory( IAIPerson& aiPerson )
{
    return new AISimplePersonMemory(aiPerson);
}
//----------------------------------------------------
