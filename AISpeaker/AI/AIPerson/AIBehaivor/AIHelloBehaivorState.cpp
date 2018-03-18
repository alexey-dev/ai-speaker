//
//  AIHelloBehaivorState.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "AIHelloBehaivorState.hpp"
#include "AIAquaintanceBehaivoralState.hpp"
#include "AIPersonBrain.hpp"
#include "../LanguageInterpretator/PhraseInterpretator.hpp"
#include "../../../Utils/UsefulMethods.hpp"

AIHelloBehaivorState::AIHelloBehaivorState():
IAIBehaivorState( BehaivorsType::Hello )
{
    
}
//----------------------------------------------------
void
AIHelloBehaivorState::AnswerMessage( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr )
{
    if ( simple_utils::IsInstanceOf<HelloPhraseInterpretator>(phraseIntpr) )
    {
        brainOwner.ChangeState(new AIAquaintanceBehaivoralState);
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
AIHelloBehaivorState::GotUnknownPhrase( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr )
{
    brainOwner.OnBehaivorAnswered("Sorry dont understand you! Just wanted to say hello!");
    ReadyForInput(brainOwner);
}
//----------------------------------------------------
void
AIHelloBehaivorState::OnSimulatorStarted( IAIPersonBrain& brainOwner )
{
    brainOwner.OnBehaivorAnswered("Hello master!");
}
//----------------------------------------------------
