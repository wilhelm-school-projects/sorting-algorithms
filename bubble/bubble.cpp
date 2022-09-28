#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../help_functions.h"

using namespace std;

void sort(vector<string> & item)
{
    for (int i{}; i < item.size(); ++i)
    {
        for (int j{}; j < item.size() - i; ++j)
        {
            if (item.at(i) < item.at(j))
            {
                swap(item.at(i), item.at(j));
            }
        }
    }
}

int main()
{
    // input words to vector of words
    vector<string> words{};
    insert_unique(words);


    return 0;
}