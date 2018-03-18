//
//  LanguageInterpretator.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef LanguageInterpretator_hpp
#define LanguageInterpretator_hpp

#include <string>
#include <vector>
#include <initializer_list>

//----------------------------------------------------
class ILanguagePhrasesInterpretators
{
public:
    
    virtual ~ILanguagePhrasesInterpretators(){}
    virtual bool Interpret( const std::string& context );
    
protected:
    
    ILanguagePhrasesInterpretators( const std::initializer_list<std::string>& keywords );
    std::vector<std::string>        mKeyWords;
};
//----------------------------------------------------
class LanguageInterpretator
{
public:
    LanguageInterpretator();
    ~LanguageInterpretator();
    void AddPhraseInterpretators( ILanguagePhrasesInterpretators* phraseInterpret );
    void SetUnknownPhrase( ILanguagePhrasesInterpretators* phraseInterpret );
    bool Interpret( const std::string& context, ILanguagePhrasesInterpretators* &retPhrase );
private:
    std::vector<ILanguagePhrasesInterpretators*>    mPhrases;
    ILanguagePhrasesInterpretators*                 mUnknownPhrase;
    
};
//----------------------------------------------------
#endif /* LanguageInterpretator_hpp */
