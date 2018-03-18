//
//  UsefulMethods.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "UsefulMethods.hpp"
#include <algorithm>
#include <ctype.h>

namespace simple_utils
{
//----------------------------------------------------
    std::string StrToLower(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); } );
        return s;
    }
//----------------------------------------------------
}
