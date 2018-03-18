//
//  AIPerson.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include <assert.h>
#include "AIPerson.hpp"
#include "AIPersonPartsAbstarctFactory.hpp"
#include "../AIEngine.hpp"

//----------------------------------------------------
AISimplePerson::AISimplePerson(AIEngine& engine):
 IAIPerson(engine)
{
    
}
//----------------------------------------------------
AISimplePerson::~AISimplePerson()
{
     
}
//----------------------------------------------------
void
IAIPerson::OnSimulatorStarted()
{
    mBrain->OnSimulatorStarted();
}
//----------------------------------------------------
void
IAIPerson::ReceivedMessage( const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr )
{
    assert( mBrain != nullptr && mMemory != nullptr && "Bad parts of aiperson!" );
    
    mBrain->ReceivedMessage( message, phraseIntpr );
}
//----------------------------------------------------
void
IAIPerson::OnBrainAnswered( const std::string& answer )
{
    mEngine.OutputDataReceived(answer);
}
//----------------------------------------------------
void
IAIPerson::ExitRequired()
{
    
}
//----------------------------------------------------
void
IAIPerson::ReadyForInput()
{
    mEngine.InputInitiation();
}
//----------------------------------------------------
