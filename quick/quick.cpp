#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

// Used for testing
#include <chrono>
#include <thread>

#include "../help_functions.h"

using namespace std;
using Iterator_Type  = vector<string>::iterator;

void swap_in_pivot(Iterator_Type & to, Iterator_Type & pivot)
{
    // maybe not necessary to let "to" aka first point to last element. Maybe just plain stupid.
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
    // std::cout << "First: " << *first << std::endl;
    // std::cout << "middle: " << *middle << std::endl;
    // std::cout << "Last: " << *last << std::endl;

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
    //std::cout << "tmp pivot: " << *tmp_pivot << std::endl;
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

    std::cout << "-------------PIVOT IN SWAPPAT----------------" << std::endl;
    std::copy(left, pivot + 1, ostream_iterator<string>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "test-it-start: " << *test_it_start << std::endl;
    std::cout << "test-it-last: " << *test_it_last << std::endl;

    // cout << "First: " << *left << std::endl;
    // cout << "Last: " << *right << std::endl;
    // cout << "Pivot: " << *pivot << std::endl;

    while (true)
    {
        std::cout << "-------------MEDANS----------------" << std::endl;
        std::copy(test_it_start, test_it_last + 1, ostream_iterator<string>(std::cout, " "));
        std::cout << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

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
        
        while (right->size() > pivot->size())
        {
            std::cout << "här" << std::endl;
            ++right;
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
    std::cout << "-------------INNAN-----------------" << std::endl;
    std::copy(first, last + 1, ostream_iterator<string>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;


    Iterator_Type pivot{};   
    do_sorting(first, last, pivot, size); 

    std::cout << "-------------Sorterat--------------" << std::endl;
    std::copy(first, last + 1, ostream_iterator<string>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;

    // "sort" this part of the array


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