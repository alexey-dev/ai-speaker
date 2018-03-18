//
//  PhraseInterpretator.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "PhraseInterpretator.hpp"
#include <initializer_list>

//----------------------------------------------------
HelloPhraseInterpretator::HelloPhraseInterpretator():
ILanguagePhrasesInterpretators( std::initializer_list<std::string> ({"Hello","Hi"}) )
{
    
}
//----------------------------------------------------
bool
HelloPhraseInterpretator::Interpret( const std::string& context )
{
    return ILanguagePhrasesInterpretators::Interpret(context);
}
//----------------------------------------------------
AquaintancePhraseInterpretator::AquaintancePhraseInterpretator():
ILanguagePhrasesInterpretators( std::initializer_list<std::string> ({"What is your name","Who are you"}) )
{
    
}
//----------------------------------------------------
bool
AquaintancePhraseInterpretator::Interpret( const std::string& context )
{
    return ILanguagePhrasesInterpretators::Interpret(context);
}
//----------------------------------------------------
ByePhraseInterpretator::ByePhraseInterpretator():
ILanguagePhrasesInterpretators( std::initializer_list<std::string> ({"Bye","Goodbye"}) )
{
    
}
//----------------------------------------------------
bool
ByePhraseInterpretator::Interpret( const std::string& context )
{
    return ILanguagePhrasesInterpretators::Interpret(context);
}
//----------------------------------------------------
UnknownPhraseInterpretator::UnknownPhraseInterpretator():
ILanguagePhrasesInterpretators( std::initializer_list<std::string> ({}) )
{
    
}
//----------------------------------------------------
bool
UnknownPhraseInterpretator::Interpret( const std::string& context )
{
    return ILanguagePhrasesInterpretators::Interpret(context);
}
//----------------------------------------------------
