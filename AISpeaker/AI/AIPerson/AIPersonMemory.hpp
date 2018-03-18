//
//  AIPersonMemory.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AIPersonMemory_hpp
#define AIPersonMemory_hpp

class IAIPerson;
//----------------------------------------------------
class IAIPersonMemory
{
public:
    
    virtual ~IAIPersonMemory(){}
    
protected:
    
    IAIPersonMemory( IAIPerson& aiPerson ):
    mAIPersonOwner(aiPerson)
    {}
    IAIPerson&      mAIPersonOwner;
};
//----------------------------------------------------
class AISimplePersonMemory : public IAIPersonMemory
{
public:
    AISimplePersonMemory( IAIPerson& aiPerson ):
    IAIPersonMemory(aiPerson)
    {}
};
//----------------------------------------------------


#endif /* AIPersonMemory_hpp */
