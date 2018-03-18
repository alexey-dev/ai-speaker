//
//  UsefulMethods.hpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef UsefulMethods_hpp
#define UsefulMethods_hpp

#include <string>

namespace simple_utils
{
//----------------------------------------------------
    template< typename T >
    void SafeDelete( T*& pVal )
    {
        delete pVal;
        pVal = nullptr;
    }
//----------------------------------------------------
    template< typename T >
    void SafeDeleteArray( T*& pVal )
    {
        delete[] pVal;
        pVal = nullptr;
    }
//----------------------------------------------------
    template< typename PossibleInstanceType, typename CurrentInstanceType >
    bool IsInstanceOf(CurrentInstanceType& instance)
    {
        return (dynamic_cast<PossibleInstanceType *>(&instance) != nullptr);
    }
//----------------------------------------------------
    std::string StrToLower(std::string s);
//----------------------------------------------------
}
#endif /* UsefulMethods_hpp */
