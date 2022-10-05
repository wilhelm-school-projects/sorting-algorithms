#include <vector>
#include <string>
#include <iterator>

#include "../help_functions.h"

using namespace std;
using Iterator_Type  = vector<string>::iterator;

Iterator_Type calc_pivot(Iterator_Type & first, Iterator_Type & last, size_t size)
{
    Iterator_Type middle { first + (size/2) };
    size_t first_s {first->size()};
    size_t last_s {last->size()};
    size_t middle_s {middle->size()};

    if (middle_s <= first_s && first_s <= last_s)
    {
        return first;
    }
    else if (first_s <= middle_s && middle_s <= last_s )
    {
        return middle;
    }
    else if (last_s <= middle_s && last_s <= first_s)
    {
        return last;
    }
    return middle;
}

void swap(Iterator_Type & lhs, Iterator_Type & rhs)
{
    if (lhs->size() < rhs->size() || lhs->size() > rhs->size())
    {
        swap(*lhs, *rhs);
    }
}

void quick_sort(Iterator_Type first, Iterator_Type last)
{
    size_t size { static_cast<size_t>(distance(first, last)) + 1};

    if (size == 1)
    {
        return;
    }
    else if (size == 2)
    {
        swap(first, last);
        return;
    }
    
    Iterator_Type pivot { calc_pivot(first, last, size) };
    swap(*pivot, *last);
    cout << *pivot << endl;

    // "sort" this part of the array

    
}

void sort(vector<string> & words)
{
    quick_sort(words.begin(), words.end() - 1);
}

int main()
{
    vector<string> words{};
    insert_unique(words);
    print(words);

    sort(words);
    //print(words);


    return 0;
}