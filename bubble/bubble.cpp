#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#include "../help_functions.h"

using namespace std;

void sort(vector<string> & item)
{
    auto curr{item.begin()};
    auto next {item.begin() + 1};
    auto sorted{item.end()};

    for (; sorted != item.begin() + 1;)
    {
        bool swapped{false};
        while(true)
        {
            if (next == sorted)
            {
                sorted--;
                curr = item.begin();
                next = item.begin() + 1;
                break;
            }
            else if (curr->size() > next->size())
            {
                string tmp {*next};
                *next = *curr;
                *curr = tmp;
                swapped = true;
            }
            curr++;
            next++;
        }
        if ( !(swapped) )
        {
            break;
        } 
    }
}

int main()
{
    // input words to vector of words
    vector<string> words{};
    insert_unique(words);
    print(words);

    sort(words);

    print_nice(words);
    return 0;
}