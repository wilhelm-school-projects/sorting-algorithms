#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

#include "../help_functions.h"

using namespace std;
using Iterator_Type  = vector<string>::iterator;

void swap_in_pivot(Iterator_Type & to, Iterator_Type & pivot)
{
    Iterator_Type::value_type tmp_val{*to};
    Iterator_Type tmp_it{pivot};
    *to = *pivot;
    pivot = to;
    to = tmp_it;
    *to = tmp_val;
}

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

    // Calculate the median and let tmp_pivot point to this element
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

    // Let pivot point to the last element which now is the pivot element
    // and last point to the element left of pivot
    Iterator_Type::value_type last_value{*last};
    *last = *tmp_pivot;
    pivot = last;
    last = last - 1;
    *tmp_pivot = last_value;
}

/// @brief Puts elements < pivot to left of pivot and elements >= pivot to the right of pivot.
/// @param first 
/// @param last 
/// @param pivot 
void do_sorting(Iterator_Type left, Iterator_Type right, Iterator_Type & pivot, int size)
{
    calc_pivot(left, right, pivot, size);
    Iterator_Type test_it_start{left};
    Iterator_Type test_it_last {pivot};

    int left_count{1}, right_count{ static_cast<int>(distance(left, pivot)) };

    while (true)
    {
        if (left->size() >= pivot->size() && right->size() < pivot->size())
        {
            std::swap(*left, *right);
        }
        
        while (left->size() < pivot->size())
        {
            ++left;
            ++left_count;

            if (left_count > right_count)
            {
                swap_in_pivot(left, pivot);
                return;
            }
        }
        
        while (right->size() >= pivot->size())
        {
            --right;
            --right_count;

            if (left_count > right_count)
            {
                swap_in_pivot(left, pivot);
                return;
            }
        }
    }
}


void quick_sort(Iterator_Type first, Iterator_Type last)
{
    size_t size { static_cast<size_t>(std::distance(first, last)) + 1};

    if (size == 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (first->size() > last->size())
        {
            std::swap(*first, *last);
        }
        return;
    }

    Iterator_Type pivot{};   
    do_sorting(first, last, pivot, size); 

    // Left side
    if (first != pivot)
    {
        quick_sort(first, pivot - 1);
    }

    // Right side
    if (last != pivot)
    {
        quick_sort(pivot + 1, last);
    }
}

/// @brief Sorts the words in ascending order comparing the size of the string, using the quick sort method
/// @param words 
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
    print(words);


    return 0;
}