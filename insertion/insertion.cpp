#include <vector>
#include <string>
#include <fstream>

#include "../help_functions.h"

using namespace std;

void sort(vector<string> & item)
{
    for (size_t i{1}; i < item.size(); ++i)
    {  
        for (size_t j{i}; j > 0; --j)
        {
            if (item.at(j).size() < item.at(j - 1).size())
            {
                swap(item.at(j), item.at(j - 1));
            }
            else if (item.at(j).size() >= item.at(j - 1).size())
            {
                break;
            }
        }
    }
}   

int main()
{
    vector<string> words{};
    insert_unique(words);
    print(words);
    
    sort(words);
    print_nice(words);

    return 0;
}