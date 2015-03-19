#include <iostream>
#include "string.h"

using namespace std;

class LinkedList
{
    public:
        char ch;
        LinkedList* next;
};

bool find_palindrome(LinkedList *start)
{
    int length = 0;
    LinkedList *ptr, *midptr;

    ptr = start;
    while(ptr)
    {
        ptr = ptr->next;
        length++;
    }
    length--;
    
    int mid = (length / 2) + (length % 2) - 1;
    ptr = start;

    // reverse one linked list 
    LinkedList* new_root = NULL;
    int i = 0;
    while(ptr && i < mid)
    { 
        LinkedList* temp = ptr->next;
        ptr->next = new_root;
        new_root = ptr;
        ptr = temp;

        i++;
    }
    midptr = ptr->next;
    ptr = new_root;

    i = 0; 
    while(ptr && midptr && i < mid)
    {
        if(midptr->ch != ptr->ch)
        {
            return false;
        }

        midptr = midptr->next;
        ptr = ptr->next;
        i++;
    }

    // everything checks out
    return true;
}

int main(void)
{
    char s[] = "malayalam";

    LinkedList *start, *list;
    start = new LinkedList;
    list = start;

    // init list with string
    for(int i = 0; i < strlen(s); i++)
    {
        list->ch = s[i];
        list->next = new LinkedList;
        list = list->next;
    }
    list->ch = '\0';
    list->next = NULL;

    cout<<endl<<"palindrome : "<<find_palindrome(start)<<endl;
    
    return 0;
}
