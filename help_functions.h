#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

// inserts words into vector but only once
void insert_unique(std::vector<std::string> & item)
{
    std::string buffer{};
    std::set<std::string> input{};
    
    // Reads until end of file
    while (std::cin >> buffer)
    {
        input.insert(buffer);
    }
    std::copy(std::begin(input), std::end(input), std::back_insert_iterator<std::vector<std::string>>(item));
}

void print(std::vector<std::string> & item)
{
    std::cout << "\nVector size: " << item.size() << std::endl;
    std::cout << "-------------------------------" << std::endl;
    for (auto const& e : item)
    {
        std::cout << e << std::endl;
    }
    std::cout << "-------------------------------\n" << std::endl;
}

#endif /* HELP_FUNCTIONS */