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

std::string spaces(int num)
{
    std::string spaces{""};
    for (int i {}; i < num; ++i)
    {
        spaces = spaces + " ";
    }
    return spaces;
}

std::vector<std::string> construct_space_induced_words (std::vector<std::string> const& words)
{
    std::vector<std::string> result {};
    int biggest{static_cast<int>(words.front().size())};

    std::string word_with_spaces{};
    for (size_t i{}; i < words.size(); ++i)
    {
        word_with_spaces = spaces(biggest - words.at(i).size()) + words.at(i);
        result.push_back(word_with_spaces); 
    }
    return result;
}

/// @brief Creates a column presentation of the sorted words and thus assumes item is sorted by word size.
///        Turns out it's not such a nice way to print with texts with more than maybe about 200 unique words.
/// @param item 
/// @return column presentation of sorted words in vector<string>
std::vector<std::string> create_rows(std::vector<std::string> & item)
{
    std::reverse(begin(item), end(item));
    std::vector<std::string> result{};
    std::vector<std::string> tmp{construct_space_induced_words(item)};
    
    for (size_t i{}; i < tmp.at(0).size(); ++i)
    {
        std::string row{};
        for (size_t j{}; j < tmp.size(); ++j)
        {
            row = row + tmp.at(j).at(i) + "  ";
        }
        result.push_back(row);
    }
    std::reverse(begin(item), end(item));
    return result;
}

void print_nice(std::vector<std::string> & item)
{
    std::vector<std::string> rows {create_rows(item)};
    
    std::cout << "-------------------------------" << std::endl;
    for (size_t i{}; i < rows.size(); ++i)
    {
        std::cout << rows.at(i) << std::endl;
    }
    std::cout << "-------------------------------\n" << std::endl;
}
#endif /* HELP_FUNCTIONS */