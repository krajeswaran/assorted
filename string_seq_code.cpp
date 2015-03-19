// I was specifically asked to code in C++ using inplace strings -- this is otherwise trivial.

#include <iostream>
#include "string.h"
#include "malloc.h"

using namespace std;

// returns a count of repeated chars in input from pos
size_t tokenize(char input[], size_t pos)
{
    auto count = 1;
    for(auto i = pos + 1; i < strlen(input) && input[i] == input[i-1]; count++, i++);
        
    return count;
}

char itoa(size_t number)
{
    return 48 + number;
}

void inplace_sequence_formatter(char input[])
{   
    size_t count = 1;
    size_t i = 0;
    size_t j = 1;
    while(i < strlen(input))
    {
        count = tokenize(input, i);
        if(count > 1)
        {
            input[j-1] = input[i];

            size_t count_digits, local_count;
            for(count_digits = 0, local_count = count; local_count > 0; local_count /= 10, count_digits++);

            for(int k = count_digits - 1, local_count = count; k >= 0; local_count /= 10, k--)
            {
                input[j + k] = itoa(local_count % 10);    
            }
            j += count_digits;
        }
        else 
        {
            input[j-1] = input[i];
        }
        j++;
        i += count;
    }
    input[j-1] = '\0';
}


int main(void)
{
    char input[] = {'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','t','b','b','b','c','c','d','d','e','e','e','e','m','m','m','k','\0'};  
    inplace_sequence_formatter(input);
    cout<<input<<endl;
    cout<<endl<<"a18tb3c2d2e4m3k";

    return 0;
}

