//
//  AIPersonBuilder.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "AIPersonBuilder.hpp"
#include "AISimplePersonPartsFactory.hpp"

//----------------------------------------------------
AISimplePersonBuilder::AISimplePersonBuilder()
{
    mPersonPartsFactory = new AISimplePersonPartsFactory;
}
//----------------------------------------------------
void
AISimplePersonBuilder::CreateAIPerson(AIEngine& engine)
{
    if ( mCurrentPerson == nullptr )
    {
        mCurrentPerson = new AISimplePerson(engine);
    }
}
//----------------------------------------------------
void
AISimplePersonBuilder::CreateAIPersonBrain()
{
    if ( mCurrentPerson != nullptr )
    {
        IAIPersonBrain* brain = mPersonPartsFactory->CreateAIBrain( *mCurrentPerson );
        mCurrentPerson->SetBrain( brain );
    }
}
//----------------------------------------------------
void
AISimplePersonBuilder::CreateAIPersonMemory()
{
    if ( mCurrentPerson != nullptr )
    {
        IAIPersonMemory* memory = mPersonPartsFactory->CreateAIMemory( *mCurrentPerson );
        mCurrentPerson->SetMemory( memory );
    }
}
//----------------------------------------------------
