//
//  AIAquaintanceBehaivoralState.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/17/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIAquaintanceBehaivoralState_hpp
#define AIAquaintanceBehaivoralState_hpp

#include <string>
#include "IAIBehaivorState.hpp"

class IAIPersonBrain;

//----------------------------------------------------
class AIAquaintanceBehaivoralState: public IAIBehaivorState
{
public:
    AIAquaintanceBehaivoralState();
    virtual void AnswerMessage( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr ) override;
    virtual void OnSimulatorStarted( IAIPersonBrain& brainOwner ) override;
    virtual void OnActivated( IAIPersonBrain& brainOwner ) override;
    
protected:
    virtual void GotUnknownPhrase( IAIPersonBrain& brainOwner, const std::string& message, ILanguagePhrasesInterpretators& phraseIntpr ) override;
    
private:
};
//----------------------------------------------------

#endif /* AIAquaintanceBehaivoralState_hpp */
