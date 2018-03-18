//
//  AIPersonBrain.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIPersonBrain_hpp
#define AIPersonBrain_hpp

#include <string>
#include "AIBehaivor/IAIBehaivorState.hpp"
#include "LanguageInterpretator/LanguageInterpretator.hpp"

class IAIPerson;
//----------------------------------------------------
class IAIPersonBrain
{
public:
    
    virtual ~IAIPersonBrain(){}
    
    virtual void ReceivedMessage( const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr );
    virtual void OnBehaivorAnswered( const std::string& answer );
    virtual void ExitRequired();
    virtual void ChangeState( IAIBehaivorState* state );
    virtual void OnSimulatorStarted(){};
    virtual void ReadyForInput();
    
protected:
    
    IAIPersonBrain( IAIPerson& aiPerson, IAIBehaivorState* behaivor ):
    mAIPersonOwner(aiPerson)
    , mBehaivorState(behaivor)
    {}
    
    IAIPerson&          mAIPersonOwner;
    IAIBehaivorState*   mBehaivorState;
};
//----------------------------------------------------
class AISimplePersonBrain : public IAIPersonBrain
{
public:
    AISimplePersonBrain( IAIPerson& aiPerson );
    virtual void OnSimulatorStarted() override;
};
//----------------------------------------------------

#endif /* AIPersonBrain_hpp */
