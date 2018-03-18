//
//  AIAquaintanceBehaivoralState.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/17/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "AIAquaintanceBehaivoralState.hpp"
#include "AIStandartBehaivorState.hpp"
#include "AIPersonBrain.hpp"
#include "../LanguageInterpretator/PhraseInterpretator.hpp"
#include "../../../Utils/UsefulMethods.hpp"

AIAquaintanceBehaivoralState::AIAquaintanceBehaivoralState():
IAIBehaivorState( BehaivorsType::Aquaintance )
{
    
}
//----------------------------------------------------
void
AIAquaintanceBehaivoralState::AnswerMessage( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr )
{
    if ( simple_utils::IsInstanceOf<HelloPhraseInterpretator>(phraseIntpr) )
    {
        brainOwner.OnBehaivorAnswered("Yes hello! And what is your name?");
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
AIAquaintanceBehaivoralState::GotUnknownPhrase( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr )
{
    brainOwner.OnBehaivorAnswered(message + " nice to meet you! I am artificai lintelligence!");
    brainOwner.ChangeState(new AIStandartBehaivorState);
    ReadyForInput(brainOwner);
}
//----------------------------------------------------
void
AIAquaintanceBehaivoralState::OnSimulatorStarted( IAIPersonBrain& brainOwner )
{
    brainOwner.OnBehaivorAnswered("What is your name!");
}
//----------------------------------------------------
void
AIAquaintanceBehaivoralState::OnActivated( IAIPersonBrain& brainOwner )
{
    brainOwner.OnBehaivorAnswered("What is your name!");
}
//----------------------------------------------------
