//
//  AIPersonBrain.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "AIPersonBrain.hpp"
#include "AIBehaivor/AIHelloBehaivorState.hpp"
#include "AIBehaivor/IAIBehaivorState.hpp"
#include "AIPerson.hpp"
#include "../../Utils/UsefulMethods.hpp"

//----------------------------------------------------
AISimplePersonBrain::AISimplePersonBrain( IAIPerson& aiPerson ):
IAIPersonBrain(aiPerson, IAIBehaivorState::CreateBehaivorState(BehaivorsType::Hello))
{
    
}
//----------------------------------------------------
void
IAIPersonBrain::ReceivedMessage( const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr )
{
    mBehaivorState->AnswerMessage(*this, message, phraseIntpr);
}
//----------------------------------------------------
void
IAIPersonBrain::OnBehaivorAnswered( const std::string& answer )
{
    mAIPersonOwner.OnBrainAnswered(answer);
}
//----------------------------------------------------
void
IAIPersonBrain::ChangeState( IAIBehaivorState* state )
{
    simple_utils::SafeDelete(mBehaivorState);
    mBehaivorState = state;
    mBehaivorState->OnActivated(*this);
}
//----------------------------------------------------
void
IAIPersonBrain::ExitRequired()
{
    
}
//----------------------------------------------------
void
IAIPersonBrain::ReadyForInput()
{
    mAIPersonOwner.ReadyForInput();
}
//----------------------------------------------------
void
AISimplePersonBrain::OnSimulatorStarted()
{
    mBehaivorState->OnSimulatorStarted(*this);
}
//----------------------------------------------------
