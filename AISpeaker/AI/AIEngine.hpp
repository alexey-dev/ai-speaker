//
//  AIEngine.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIEngine_hpp
#define AIEngine_hpp

#include <string>
#include "IOAbstractFactory.hpp"
#include "AIPerson/AIPersonBuilder.hpp"
#include "AIPerson/LanguageInterpretator/LanguageInterpretator.hpp"
#include "AIPerson/LanguageInterpretator/LanguagePhrasesBuilder.hpp"

//----------------------------------------------------
class AIEngine
{
public:
    AIEngine( IOAbstractFactory* ioFactory );
    ~AIEngine();
    
    void CreatePerson( IAIPersonBuilder* builder );
    void CreateLanguageInterpretator( ILanguagePhrasesBuilder* builder );
    void StartDialog();
    void InputInitiation();
    
    void InputDataReceived( const std::string& inputData );
    void OutputDataReceived( const std::string& outputData );
    void ExitRequired();
    
private:
    
    void DetectPhraseFromContext( const std::string& context, ILanguagePhrasesInterpretators* &PhraseInterpret );
    
    IAIPerson*          mAIPerson;
    
    IInputStream*           mInput;
    IOutputStream*          mOutput;
    LanguageInterpretator*  mLanguageInterpretator;
};
//----------------------------------------------------

#endif /* AIEngine_hpp */
