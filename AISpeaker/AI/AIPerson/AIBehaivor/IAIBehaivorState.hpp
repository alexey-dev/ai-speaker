//
//  IAIBehaivorState.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef IAIBehaivorState_hpp
#define IAIBehaivorState_hpp

#include <string>
#include "../LanguageInterpretator/LanguageInterpretator.hpp"

class IAIPersonBrain;

//----------------------------------------------------
enum class BehaivorsType : uint8_t
{
    Hello = 0,
    Aquaintance,
    Bye,
};
//----------------------------------------------------
class IAIBehaivorState
{
public:
    
    static IAIBehaivorState* CreateBehaivorState(BehaivorsType type);
    virtual ~IAIBehaivorState();
    
    virtual void OnSimulatorStarted( IAIPersonBrain& brainOwner ){};
    virtual void AnswerMessage( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr ) = 0;
    virtual void ChangeState( IAIPersonBrain& brainOwner, IAIBehaivorState* state );
    virtual void OnActivated( IAIPersonBrain& brainOwner ){};
    virtual void ReadyForInput( IAIPersonBrain& brainOwner );    
    
protected:
    
    IAIBehaivorState( BehaivorsType type );
    
    virtual void GotUnknownPhrase( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr ) = 0;
    
    BehaivorsType   mType;
};
//----------------------------------------------------

#endif /* IAIBehaivorState_hpp */
