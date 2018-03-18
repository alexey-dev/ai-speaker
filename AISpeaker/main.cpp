//
//  main.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include <iostream>
#include "AI/AIEngine.hpp"
#include "AI/AIPerson/AIPersonBuilder.hpp"
#include "AI/AIPerson/LanguageInterpretator/LanguagePhrasesBuilder.hpp"
#include "IOInteraction/IOConsoleFactory.hpp"
#include <memory>

using namespace std;

int main(int argc, const char * argv[])
{
    unique_ptr<IOConsoleFactory> PtrConsoleFactory( new IOConsoleFactory );
    unique_ptr<AISimplePersonBuilder> PtrPersonBuilder( new AISimplePersonBuilder );
    unique_ptr<ILanguagePhrasesBuilder> PtrLangInterpretBuilder( new SimplePhrasesBuilder );
    
    AIEngine engine( PtrConsoleFactory.get() );
    engine.CreatePerson( PtrPersonBuilder.get() );
    engine.CreateLanguageInterpretator( PtrLangInterpretBuilder.get() );
    engine.StartDialog();
    
    return 0;
}
