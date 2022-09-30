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

void add_spaces (std::vector<std::string> & words)
{
    int biggest{words.front().size()};

    for (int i{}; i < words.size(); ++i)
    {
        
    }
}

/// @brief Creates a column presentation of the sorted words and thus assumes item is sorted by word size.
/// @param item 
/// @return column presentation of sorted words in vector<string>
std::vector<std::string> create_rows(std::vector<std::string> const& item)
{
    std::vector<std::string> tmp{item};
    std::reverse(begin(tmp), end(tmp));

    add_spaces(tmp);

    std::vector<std::string> result{};
    int current_size{};
    int index{};
    while(true)
    {
        current_size = item.at(index).size();
        result.push_back(std::string{""});
        int curr_word{};

        while (true)
        {
            if (item.at(curr_word).size() != current_size)
            {
                break;
            }

            result.at(index) = result.at(index) + item.at(curr_word).at(index);

            curr_word++;
        }
        std::cout << result.at(index) << std::endl;
        ++index;
    }

    // for (int i{}; i < item.back().size(); ++i)
    // {
    //     // Första ordets storlek
    //     current_size = item.at(i).size();
    //     result.push_back(std::string{""});
    //     int curr_word{i};

    //     while (true)
    //     {
    //         if (item.at(curr_word).size() != current_size)
    //         {
    //             break;
    //         }

    //         result.at(i) = result.at(i) + item.at(curr_word).at(i);

    //         curr_word++;
    //     }
    //     std::cout << result.at(i) << std::endl;
        
    //     // for (int j{}; static_cast<int>(item.at(j).size()) != current_size; ++j)
    //     // {
    //     //     result.at(i) += item.at(j).at(i);
    //     // }
    // }

    std::reverse(begin(item), end(item));
    return result;
}

void print_nice(std::vector<std::string> & item)
{
    std::vector<std::string> rows {create_rows(item)};
    
   // std::cout << "-------------------------------" << std::endl;
    // for (std::string const& e : rows)
    // {
    //     std::cout << e << std::endl;
    // }
    //std::cout << "-------------------------------\n" << std::endl;
}

/* TODO: function print_nice 
        - Should print the words like pillars on the same row 
*/

#endif /* HELP_FUNCTIONS */