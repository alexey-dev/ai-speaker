//
//  LanguagePhrasesBuilder.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "LanguagePhrasesBuilder.hpp"
#include "LanguageInterpretator.hpp"
#include "PhraseInterpretator.hpp"

//----------------------------------------------------
void
ILanguagePhrasesBuilder::CreateUnknownInterpret()
{
    if ( mCurrentLanguageInterpret != nullptr )
    {
        mCurrentLanguageInterpret->SetUnknownPhrase( new UnknownPhraseInterpretator );
    }
}
//----------------------------------------------------
ILanguagePhrasesBuilder::ILanguagePhrasesBuilder():
 mCurrentLanguageInterpret(nullptr)
{
    
}
//----------------------------------------------------
void
SimplePhrasesBuilder::CreateHelloInterpret()
{
    if ( mCurrentLanguageInterpret != nullptr )
    {
        mCurrentLanguageInterpret->AddPhraseInterpretators( new HelloPhraseInterpretator );
    }
}
//----------------------------------------------------
void
SimplePhrasesBuilder::CreateAquaintanceInterpret()
{
    if ( mCurrentLanguageInterpret != nullptr )
    {
        mCurrentLanguageInterpret->AddPhraseInterpretators( new AquaintancePhraseInterpretator );
    }
}
//----------------------------------------------------
void
SimplePhrasesBuilder::CreateByeInterpret()
{
    if ( mCurrentLanguageInterpret != nullptr )
    {
        mCurrentLanguageInterpret->AddPhraseInterpretators( new ByePhraseInterpretator );
    }
}
//----------------------------------------------------
void
SimplePhrasesBuilder::CreateMainInterpret()
{
    mCurrentLanguageInterpret = new LanguageInterpretator;
}
//----------------------------------------------------
