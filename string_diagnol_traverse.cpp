#include <iostream>
#include "string.h"
#include "malloc.h"

using namespace std;

char* convert(char *s, int rows)
{
    unsigned int slen = strlen(s);
    char* output = (char *)malloc(slen + 1);
    int columns = slen/rows;
    int dx = 0, dy = 0, c = 0, curr = 0, rev = 0;
    
    for(int i = 0; i < rows; i++)
    {
        dy = i + 2;
        rev = 0;
        for(int j = 0, curr = dx; j < columns; j++)
        {
           if(dy > columns)
           {
                dy = columns;
                rev++;
           }
           if(dy == columns)
           {
               dy = columns;
           }

           output[c++] = s[curr]; 
           curr += dy;
           dy = (rev > 0) ? (dy - rev) : (dy + 1);
        }
        dx += i + 1;
    }

    output[c++] = '\0';
    return output;
}
    

int main(void)
{
    char s[] = "thequickbrownfoxjumpsover";

    cout<<convert(s, 5);
    cout<<endl<<"teirohubfmqknuocwjseoxpvr";
    
    return 0;
}
