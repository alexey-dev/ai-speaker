//
//  IOConsoleFactory.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef IOConsoleFactory_hpp
#define IOConsoleFactory_hpp

#include "IOAbstractFactory.hpp"
#include <iostream>

class AIEngine;

//----------------------------------------------------
class ConsoleInput : public IInputStream
{
public:
    
    ConsoleInput( AIEngine& engine ):
     IInputStream( engine )
    , mMaxSymbolsPerLine(100)
    {}
    
    virtual void GetInputData( std::string& inputData ) override;
    virtual void InputNext() override;
    
private:
    
    const uint16_t  mMaxSymbolsPerLine;
};
//----------------------------------------------------
class ConsoleOutput : public IOutputStream
{
public:
    virtual void Print( const std::string& outData ) const override;
};
//----------------------------------------------------
class IOConsoleFactory : public IOAbstractFactory
{
public:
    virtual IInputStream*   GetInputStream( AIEngine& engine ) override;
    virtual IOutputStream*  GetOutputStream() override;
};
//----------------------------------------------------

#endif /* IOConsoleFactory_hpp */
