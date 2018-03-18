//
//  AIStandartBehaivorState.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/18/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "AIStandartBehaivorState.hpp"
#include "AIPersonBrain.hpp"
#include "../LanguageInterpretator/PhraseInterpretator.hpp"
#include "../../../Utils/UsefulMethods.hpp"

AIStandartBehaivorState::AIStandartBehaivorState():
IAIBehaivorState( BehaivorsType::Aquaintance )
{
    
}
//----------------------------------------------------
void
AIStandartBehaivorState::AnswerMessage( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr )
{
    if ( simple_utils::IsInstanceOf<HelloPhraseInterpretator>(phraseIntpr) )
    {
        brainOwner.OnBehaivorAnswered("Yes hello!");
        ReadyForInput(brainOwner);
    }
    else if ( simple_utils::IsInstanceOf<ByePhraseInterpretator>(phraseIntpr) )
    {
        brainOwner.OnBehaivorAnswered("Bye master!");
    }
    else if ( simple_utils::IsInstanceOf<UnknownPhraseInterpretator>(phraseIntpr) )
    {
        GotUnknownPhrase(brainOwner, message, phraseIntpr);
    }
}
//----------------------------------------------------
void
AIStandartBehaivorState::GotUnknownPhrase( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr )
{
    brainOwner.OnBehaivorAnswered("Sorry dont understand you!");
}
//----------------------------------------------------
void
AIStandartBehaivorState::OnSimulatorStarted( IAIPersonBrain& brainOwner )
{
}
//----------------------------------------------------
void
AIStandartBehaivorState::OnActivated( IAIPersonBrain& brainOwner )
{
}
//----------------------------------------------------
