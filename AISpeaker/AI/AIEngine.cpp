//
//  AIEngine.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include <iostream>
#include "AIEngine.hpp"
#include "AIPerson/LanguageInterpretator/LanguageInterpretator.hpp"
#include "../Utils/UsefulMethods.hpp"

//----------------------------------------------------
AIEngine::AIEngine( IOAbstractFactory* ioFactory )
{
    mInput = ioFactory->GetInputStream( *this );
    mOutput = ioFactory->GetOutputStream();
}
//----------------------------------------------------
AIEngine::~AIEngine()
{
    simple_utils::SafeDelete(mInput);
    simple_utils::SafeDelete(mOutput);
    simple_utils::SafeDelete(mAIPerson);
}
//----------------------------------------------------
void
AIEngine::CreatePerson( IAIPersonBuilder* builder )
{
    builder->CreateAIPerson(*this);
    builder->CreateAIPersonBrain();
    builder->CreateAIPersonMemory();
    
    mAIPerson = builder->GetAIPerson();    
}
//----------------------------------------------------
void
AIEngine::CreateLanguageInterpretator( ILanguagePhrasesBuilder* builder )
{
    builder->CreateMainInterpret();
    builder->CreateHelloInterpret();
    builder->CreateAquaintanceInterpret();
    builder->CreateByeInterpret();
    builder->CreateUnknownInterpret();
    
    mLanguageInterpretator = builder->GetMainInterpret();
}
//----------------------------------------------------
void
AIEngine::StartDialog()
{
    mAIPerson->OnSimulatorStarted();
    InputInitiation();
}
//----------------------------------------------------
void
AIEngine::InputInitiation()
{
    mInput->InputNext();
}
//----------------------------------------------------
void
AIEngine::InputDataReceived( const std::string& inputData )
{
    ILanguagePhrasesInterpretators* PhraseInterpret = nullptr;
    DetectPhraseFromContext(inputData, PhraseInterpret);
    
    mAIPerson->ReceivedMessage(inputData, *PhraseInterpret);
}
//----------------------------------------------------
void
AIEngine::DetectPhraseFromContext( const std::string& context, ILanguagePhrasesInterpretators* &PhraseInterpret )
{
    mLanguageInterpretator->Interpret(context, PhraseInterpret);
}
//----------------------------------------------------
void
AIEngine::OutputDataReceived( const std::string& outputData )
{
    mOutput->Print( outputData );
}
//----------------------------------------------------
void
AIEngine::ExitRequired()
{
    
}
//----------------------------------------------------
