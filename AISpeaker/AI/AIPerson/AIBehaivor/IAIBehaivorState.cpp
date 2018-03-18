//
//  IAIBehaivorState.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "IAIBehaivorState.hpp"
#include "AIHelloBehaivorState.hpp"
#include "../AIPersonBrain.hpp"

//----------------------------------------------------
IAIBehaivorState::~IAIBehaivorState()
{
}
//----------------------------------------------------
IAIBehaivorState*
IAIBehaivorState::CreateBehaivorState(BehaivorsType type)
{
    IAIBehaivorState* RetBehaivor = nullptr;
    switch (type) {
        case BehaivorsType::Hello :
            RetBehaivor = new AIHelloBehaivorState;
            break;
            
        default:
            break;
    }
    return RetBehaivor;
}
//----------------------------------------------------
IAIBehaivorState::IAIBehaivorState( BehaivorsType type ):
 mType(type)
{
    
}
//----------------------------------------------------
void
IAIBehaivorState::ReadyForInput( IAIPersonBrain& brainOwner )
{
    brainOwner.ReadyForInput();
}
//----------------------------------------------------
void
IAIBehaivorState::ChangeState( IAIPersonBrain& brainOwner, IAIBehaivorState* state )
{
    brainOwner.ChangeState( state );
}
//----------------------------------------------------
