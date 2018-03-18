//
//  LanguagePhrasesBuilder.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef LanguagePhrasesBuilder_hpp
#define LanguagePhrasesBuilder_hpp

class ILanguageInterpretators;
class LanguageInterpretator;

//----------------------------------------------------
class ILanguagePhrasesBuilder
{
public:
    
    virtual ~ILanguagePhrasesBuilder(){}
    
    virtual void CreateHelloInterpret() = 0;
    virtual void CreateAquaintanceInterpret() = 0;
    virtual void CreateByeInterpret() = 0;
    virtual void CreateUnknownInterpret();
    virtual void CreateMainInterpret() = 0;
    
    LanguageInterpretator* GetMainInterpret()
    {
        return mCurrentLanguageInterpret;
    }
    
protected:
    
    ILanguagePhrasesBuilder();
    
    LanguageInterpretator* mCurrentLanguageInterpret;
};
//----------------------------------------------------
class SimplePhrasesBuilder : public ILanguagePhrasesBuilder
{
public:
    virtual void CreateHelloInterpret() override;
    virtual void CreateAquaintanceInterpret() override;
    virtual void CreateByeInterpret() override;
    virtual void CreateMainInterpret() override;
};
//----------------------------------------------------

#endif /* LanguagePhrasesBuilder_hpp */
