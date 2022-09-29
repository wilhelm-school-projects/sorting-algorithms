#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

// inserts words into vector but only once
void insert_unique(std::vector<std::string> & item)
{
    std::string buffer{};

    // Reads until end of file
    while (std::cin >> buffer)
    {
        if (std::find(begin(item), end(item), buffer) == item.end()) 
        {
            item.push_back(buffer);
        }
    }
}

void print(std::vector<std::string> & item)
{
    for (auto const& e : item)
    {
        std::cout << e << std::endl;
    }
}

#endif /* HELP_FUNCTIONS */