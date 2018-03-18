//
//  PhraseInterpretator.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef PhraseInterpretator_hpp
#define PhraseInterpretator_hpp

#include <string>
#include "LanguageInterpretator.hpp"

//----------------------------------------------------
class HelloPhraseInterpretator : public ILanguagePhrasesInterpretators
{
public:
    HelloPhraseInterpretator();
    virtual bool Interpret( const std::string& context ) override;
};
//----------------------------------------------------
class AquaintancePhraseInterpretator : public ILanguagePhrasesInterpretators
{
public:
    AquaintancePhraseInterpretator();
    virtual bool Interpret( const std::string& context ) override;
};
//----------------------------------------------------
class ByePhraseInterpretator : public ILanguagePhrasesInterpretators
{
public:
    ByePhraseInterpretator();
    virtual bool Interpret( const std::string& context ) override;
};
//----------------------------------------------------
class UnknownPhraseInterpretator : public ILanguagePhrasesInterpretators
{
public:
    UnknownPhraseInterpretator();
    virtual bool Interpret( const std::string& context ) override;
};
//----------------------------------------------------

#endif /* PhraseInterpretator_hpp */
