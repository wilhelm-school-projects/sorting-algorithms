#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <iomanip>

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

/**
 * TODO: print_nice
 * Print words like pillars meaning letters in the same word are in the same column but different rows. Harder than i thought it would be.
 * Idea: make 1 string for every row which consists of characters that actually are part of different words, E.g.;
 * 
 * string1: e k d d   
 * string2: o l a e p o
 * string3: j u d o w k o
 * 
 * And so forth. Thus e.g., "eoj" was a word in item 
*/

// void print_nice(std::vector<std::string> & item)
// {
//     std::cout << "-------------------------------" << std::endl;
//     for (std::string const& e : item)
//     {
//         for (char const& c : e)
//         {
//             std::cout << std::left << std::setw(2) << c;
//         }
//        std::cout << " ";

//     }
//     std::cout << "-------------------------------\n" << std::endl;
// }

/* TODO: function print_nice 
        - Should print the words like pillars on the same row 
*/

#endif /* HELP_FUNCTIONS */