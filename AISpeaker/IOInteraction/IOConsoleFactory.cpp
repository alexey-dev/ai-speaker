//
//  IOConsoleFactory.cpp
//  AISpeaker
//
//  Created by Alex Usachov on 3/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include "IOConsoleFactory.hpp"
#include "../AI/AIEngine.hpp"

using namespace std;

//----------------------------------------------------
void
ConsoleInput::GetInputData( std::string& inputData )
{
    
}
//----------------------------------------------------
void
ConsoleInput::InputNext()
{
    std::string TempInputLine;
    char InputData[mMaxSymbolsPerLine];
    
    cin.getline(InputData, mMaxSymbolsPerLine);
    TempInputLine = InputData;
    mEngine.InputDataReceived( TempInputLine );
}
//----------------------------------------------------
void
ConsoleOutput::Print( const std::string& outData ) const
{
    cout << outData << endl;
}
//----------------------------------------------------
IInputStream*
IOConsoleFactory::GetInputStream( AIEngine& engine )
{
    return new ConsoleInput(engine);
}
//----------------------------------------------------
IOutputStream*
IOConsoleFactory::GetOutputStream()
{
    return new ConsoleOutput;
}
//----------------------------------------------------
