#include <vector>
#include <string>
#include <iterator>

#include "../help_functions.h"

using namespace std;
using Size_Type = long int;
using Iterator_Type  = vector<string>::iterator;

vector<string> merge_sort(Iterator_Type begin, Iterator_Type last)
{
    vector<string> result {};
    vector<string> left {};
    vector<string> right {};
    Size_Type size{ distance(begin, last) + 1 };

    /* partition array */
    if (size == 1)
    {
        result.push_back(*begin);
        return result;
    }
    else if(size == 2)
    { 
        // Left side
        left = merge_sort(begin, begin);
    
        // Right side    
        right = merge_sort(last, last);
    }
    else
    {
        Iterator_Type middle { last - size/2};
        // Left side
        left = merge_sort(begin, middle);
        
        // Right side    
        right = merge_sort(middle + 1, last);    
    }

    /* Sort returned partitions */
    auto left_it {left.begin()};
    auto right_it {right.begin()};
    
    auto right_end {right.end()};
    auto left_end {left.end()};
   
    while (true)
    {
        if (right_it == right_end)
        {
            for (; left_it != left_end; ++left_it)
            {
                result.push_back(*left_it);
            }
            break;
        }
        else if ( left_it == left_end )
        {
            for (; right_it != right_end; ++right_it)
            {
                result.push_back(*right_it);
            }
            break;
        }

        if ( left_it->size() < right_it->size())
        {
            result.push_back(*left_it);
            ++left_it;
        }
        else if ( right_it->size() < left_it->size())
        {
            result.push_back(*right_it);
            ++right_it;
        }
        else
        {
            result.push_back(*left_it);                     // left_it and right_it point to a words the same size, thus choose one to push_back into vector.
            ++left_it;
        }
    }
    return result;
}

void sort(vector<string> & words)
{
    words = merge_sort(words.begin(), words.end() - 1);
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