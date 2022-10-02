#include <vector>
#include <string>

#include "../help_functions.h"

using namespace std;

void sort(vector<string> & words)
{

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