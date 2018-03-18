//
//  AIPersonBuilder.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIPersonBuilder_hpp
#define AIPersonBuilder_hpp

#include "AIPerson.hpp"
#include "AIPersonBrain.hpp"
#include "AIPersonMemory.hpp"
#include "../../Utils/UsefulMethods.hpp"

class AIEngine;
//----------------------------------------------------
class IAIPersonBuilder
{
public:
    virtual ~IAIPersonBuilder()
    {
        simple_utils::SafeDelete(mPersonPartsFactory);
    }
    
    virtual void CreateAIPerson(AIEngine& engine) = 0;
    virtual void CreateAIPersonBrain() = 0;
    virtual void CreateAIPersonMemory() = 0;
    
    IAIPerson* GetAIPerson()
    {
        return mCurrentPerson;
    }
    
protected:
    IAIPersonBuilder():
    mCurrentPerson(nullptr)
    , mPersonPartsFactory(nullptr)
    {}
    
    IAIPerson*                      mCurrentPerson;
    IAIPersonPartsAbstarctFactory*  mPersonPartsFactory;
};
//----------------------------------------------------
class AISimplePersonBuilder : public IAIPersonBuilder
{
public:
    AISimplePersonBuilder();
    virtual void CreateAIPerson(AIEngine& engine) override;
    virtual void CreateAIPersonBrain() override;
    virtual void CreateAIPersonMemory() override;
};
//----------------------------------------------------

#endif /* AIPersonBuilder_hpp */
