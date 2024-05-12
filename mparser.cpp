#include <iostream>
#include <string>
#include <algorithm>
#include "clipboardxx.hpp"

bool onlySymbols(std::string str)
{
    for (const char& i : str)
    {
        if (isalnum(i))
        {
            return false;
        }
    }
    return true;
}

std::string process_string(std::string mName)
{
    std::string::iterator it = mName.begin();
    bool capitalize = true;
    while (it != mName.end())
    {
        if (!isalnum(*it))
        {
            mName.erase(it);
            continue;
        }
        else 
        {
            break;
        }
        it++;
    }
    while (it != mName.end())
    {
        if (isalpha(*it) && capitalize)
        {
            *it = toupper(*it);
            capitalize = false;
        }
        else if (onlySymbols(std::string(it, mName.end())) && !isalnum(*it))
        {
            mName = std::string(mName.begin(), it);
            break;
        }
        else if (*it == '-' || *it == '_')
        {
            *it = ' ';
            capitalize = true;
        }
        it++;
    }
    return mName;
}

int main(int argc, char* argv[])
{
    std::string str = "(";
    clipboardxx::clipboard clipb;
    
    if (argc == 2)
    {
        str += process_string(argv[1]);
        str += ")";
    }
    else
    {
        std::string userInput;
        
        std::cout << "Enter the text: ";
        std::getline(std::cin, userInput);

        str += process_string(userInput);
        str += ")";
    }

    std::cout << str << " - [Copied to Clipboard]";
    clipb << str;
    return 0;
}