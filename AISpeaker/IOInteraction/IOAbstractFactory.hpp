//
//  IOAbstractFactory.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef IOAbstractFactory_hpp
#define IOAbstractFactory_hpp

#include <string>
#include <iostream>

class AIEngine;
//----------------------------------------------------
class IInputStream
{
public:
    
    virtual ~IInputStream(){}
    virtual void InputNext() = 0;
    virtual void GetInputData( std::string& inputData ) = 0;
    
protected:
    
    IInputStream( AIEngine& engine ):
    mEngine(engine)
    {}
    
    AIEngine&   mEngine;
};
//----------------------------------------------------
class IOutputStream
{
public:
    virtual ~IOutputStream(){}
    virtual void Print( const std::string& outData ) const = 0;
};
//----------------------------------------------------
class IOAbstractFactory
{
public:
    virtual ~IOAbstractFactory(){}
    
    virtual IInputStream*   GetInputStream( AIEngine& engine ) = 0;
    virtual IOutputStream*  GetOutputStream() = 0;
};
//----------------------------------------------------


#endif /* IOAbstractFactory_hpp */
