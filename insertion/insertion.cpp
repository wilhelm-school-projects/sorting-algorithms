#include "../help_functions.h"
#include <vector>
#include <string>

using namespace std;

void sort(vector<string> & item)
{
    for (int i{}; i < item.size(); ++i)
    {
        for (int j{}; j < item.size(); ++j)
        {
            
        }
    }
}   

int main()
{
    vector<string> words{};
    insert_unique(words);
    print(words);
    
    sort(words);
    // print_nice(words);
    return 0;
}