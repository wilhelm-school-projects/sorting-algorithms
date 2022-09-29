#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../help_functions.h"

using namespace std;

void sort(vector<string> & item)
{
    auto curr{item.begin()};
    auto next {item.begin() + 1};
    auto sorted{item.end()};

    for (; sorted != item.begin() ;)
    {
        while(true)
        {
            if (curr->size() > next->size())
            {
                string tmp {*next};
                *next = *curr;
                *curr = tmp;

                curr++;
                next++;
                if (next == sorted)
                {
                    sorted--;
                    break;
                }
            }
        }
    }
}

int main()
{
    // input words to vector of words
    vector<string> words{};
    insert_unique(words);
    print(words);
    cout << "------------------" << endl;
    sort(words);
    print(words);

    return 0;
}