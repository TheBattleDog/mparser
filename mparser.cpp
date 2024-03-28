#include <iostream>
#include <string>
#include <algorithm>
#include "clipboardxx.hpp"

int main(int argc, char* argv[])
{
    std::string str = "(";
    clipboardxx::clipboard clipb;
    
    if (argc == 2)
    {
        argv[1][0] = toupper(argv[1][0]);
        str += argv[1];
        std::replace(str.begin(), str.end(), '-', ' ');
        str += ")";
    }
    else
    {
        std::string userInput;
        
        std::cout << "Enter the text: ";
        std::getline(std::cin, userInput);
        userInput[0] = toupper(userInput[0]);
        
        str += (userInput);
        std::replace(str.begin(), str.end(), '-', ' ');
        str += ")";
    }

    std::cout << str << " - [Copied to Clipboard]";
    clipb << str;
    return 0;
}