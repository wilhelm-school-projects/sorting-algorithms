#include <vector>
#include <string>
#include <iterator>
#include <iostream>

#include "../help_functions.h"

using namespace std;
using Iterator_Type  = vector<string>::iterator;

/// @brief  calculates which value in the array should be the pivot. Then lets pivot point to this value
///         and that value is the last element in the array now, which means that last will point to the
///         element at position (pivot - 1).
/// @param first 
/// @param last 
/// @param pivot 
/// @param size 
void calc_pivot(Iterator_Type & first, Iterator_Type & last, Iterator_Type & pivot, size_t size)
{
    Iterator_Type middle { first + (size/2) };
    Iterator_Type tmp_pivot {};
    size_t first_s {first->size()};
    size_t last_s {last->size()};
    size_t middle_s {middle->size()};

    if (middle_s <= first_s && first_s <= last_s)
    {
        tmp_pivot = first;
    }
    else if (first_s <= middle_s && middle_s <= last_s )
    {
        tmp_pivot = middle;
    }
    else if (last_s <= middle_s && last_s <= first_s)
    {
        tmp_pivot = last;
    }
    tmp_pivot = middle;

    Iterator_Type::value_type last_value{*last};
    *last = *tmp_pivot;
    pivot = last;
    last = last - 1;
    *tmp_pivot = last_value;
    //cout << "tmp pivot: " << *tmp_pivot << endl;
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
    
    Iterator_Type pivot{};
    calc_pivot(first, last, pivot, size);    
    // cout << "-----------Pivot calculation" << endl;
    // cout << "First: " << *first << endl;
    // cout << "Last: " << *last << endl;
    // cout << "Pivot: " << *pivot << endl;

    // "sort" this part of the array

    int left_count{}, right_count{ distance(first, pivot) + 1 };

    while (true)
    {
        if (first->size() >= pivot->size() && last->size() < pivot->size())
        {
            // swap
        }
        
        while (first->size() <= pivot->size())
        {
            ++first;
            ++left_count;

            if (left_count > right_count)
            {
                // swap in pivot?
            }
        }
        
        while (last->size() > pivot->size())
        {
            ++last;
            --right_count;

            if (left_count > right_count)
            {
                // swap in pivot?
            }
        }
    }

    // call quick with left and right side of pivot    
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