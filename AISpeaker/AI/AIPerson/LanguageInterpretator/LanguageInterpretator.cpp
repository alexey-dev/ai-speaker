//
//  LanguageInterpretator.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "../../../Utils/UsefulMethods.hpp"
#include "LanguageInterpretator.hpp"
#include <algorithm>
#include <cctype>

//----------------------------------------------------
ILanguagePhrasesInterpretators::ILanguagePhrasesInterpretators( const std::initializer_list<std::string>& keywords ):
 mKeyWords(keywords)
{
    
}
//----------------------------------------------------
LanguageInterpretator::LanguageInterpretator():
 mUnknownPhrase(nullptr)
{
    
}
//----------------------------------------------------
LanguageInterpretator::~LanguageInterpretator()
{
    for ( ILanguagePhrasesInterpretators * interpr : mPhrases )
    {
        simple_utils::SafeDelete(interpr);
    }
    
    mPhrases.clear();
}
//----------------------------------------------------
void
LanguageInterpretator::SetUnknownPhrase( ILanguagePhrasesInterpretators* phraseInterpret )
{
    mUnknownPhrase = phraseInterpret;
}
//----------------------------------------------------
void
LanguageInterpretator::AddPhraseInterpretators( ILanguagePhrasesInterpretators* phraseInterpret )
{
    mPhrases.push_back(phraseInterpret);
}
//----------------------------------------------------
bool
LanguageInterpretator::Interpret( const std::string& context, ILanguagePhrasesInterpretators* &retPhrase )
{
    retPhrase = mUnknownPhrase;
    
    for ( ILanguagePhrasesInterpretators * interpr : mPhrases )
    {
        if ( interpr->Interpret(context) )
        {
            retPhrase = interpr;
            return true;
        }
    }
    
    return false;
}
//----------------------------------------------------
bool
ILanguagePhrasesInterpretators::Interpret( const std::string& context )
{
    std::string TempContext = simple_utils::StrToLower(context);
    
    for ( std::string PatternEl : mKeyWords )
    {
        std::string TempPatternEl = simple_utils::StrToLower(PatternEl);
        
        if ( TempContext.find( TempPatternEl ) != std::string::npos )
        {
            return true;
        }
    }
    
    return false;
}
//----------------------------------------------------
