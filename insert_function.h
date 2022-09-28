#ifndef INSERT_FUNCTION
#define INSERT_FUNCTION

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

#endif /* INSERT_FUNCTION */