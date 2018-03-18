//
//  AIStandartBehaivorState.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/18/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIStandartBehaivorState_hpp
#define AIStandartBehaivorState_hpp

#include <string>
#include "IAIBehaivorState.hpp"

class IAIPersonBrain;

//----------------------------------------------------
class AIStandartBehaivorState: public IAIBehaivorState
{
public:
    AIStandartBehaivorState();
    virtual void AnswerMessage( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr ) override;
    virtual void OnSimulatorStarted( IAIPersonBrain& brainOwner ) override;
    virtual void OnActivated( IAIPersonBrain& brainOwner ) override;
    
protected:
    virtual void GotUnknownPhrase( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr ) override;
    
private:
};
//----------------------------------------------------

#endif /* AIStandartBehaivorState_hpp */
