//
//  AIHelloBehaivorState.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/16/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIHelloBehaivorState_hpp
#define AIHelloBehaivorState_hpp

#include <string>
#include "IAIBehaivorState.hpp"

class IAIPersonBrain;

//----------------------------------------------------
class AIHelloBehaivorState: public IAIBehaivorState
{
public:
    AIHelloBehaivorState();
    virtual void AnswerMessage( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr ) override;
    virtual void OnSimulatorStarted( IAIPersonBrain& brainOwner ) override;
    
protected:
    virtual void GotUnknownPhrase( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr ) override;
    
private:
};
//----------------------------------------------------

#endif /* AIHelloBehaivorState_hpp */
