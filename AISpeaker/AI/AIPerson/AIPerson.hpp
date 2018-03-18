//
//  AIPerson.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIPerson_hpp
#define AIPerson_hpp

#include <string>
#include "AIPersonBrain.hpp"
#include "AIPersonMemory.hpp"
#include "LanguageInterpretator/LanguageInterpretator.hpp"
#include "../../Utils/UsefulMethods.hpp"

class IAIPersonPartsAbstarctFactory;
class AIEngine;

//----------------------------------------------------
class IAIPerson
{
public:
    
    virtual ~IAIPerson()
    {
        simple_utils::SafeDelete(mBrain);
        simple_utils::SafeDelete(mMemory);
    }
    
    void SetBrain( IAIPersonBrain* brain )
    {
        mBrain = brain;
    }
    
    void SetMemory( IAIPersonMemory* memory )
    {
        mMemory = memory;
    }
    
    virtual void OnSimulatorStarted();
    virtual void ReceivedMessage( const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr );
    virtual void OnBrainAnswered( const std::string& answer );
    virtual void ReadyForInput();
    virtual void ExitRequired();
    
protected:
    
    IAIPerson(AIEngine& engine):
    mEngine(engine)
    , mBrain(nullptr)
    , mMemory(nullptr)
    {
    }
    
    IAIPersonBrain*     mBrain;
    IAIPersonMemory*    mMemory;
    AIEngine&           mEngine;
};
//----------------------------------------------------
class AISimplePerson : public IAIPerson
{
public:
    AISimplePerson( AIEngine& engine );
    ~AISimplePerson();
};
//----------------------------------------------------

#endif /* AIPerson_hpp */
