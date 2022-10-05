#include <vector>
#include <string>

#include "../help_functions.h"

using namespace std;

void sort(vector<string> & words)
{   
    int smallest{};
    for (int i{}; i < words.size(); ++i)
    {
        smallest = i;
        for (int j{i}; j < words.size(); ++j)
        {
            if ( words.at(j).size() < words.at(smallest).size())
            {
                smallest = j;
            }
        }
        swap(words.at(smallest), words.at(i));
    }
}   

int main()
{
    vector<string> words{};
    insert_unique(words);
    
    sort(words);
    print(words);


    return 0;
}