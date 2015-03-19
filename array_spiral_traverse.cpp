#include <iostream>

using namespace std;

static unsigned int count = 0;

void one_single_traverse(int array[5][4], int m, int n, int x, int y)
{
    //traverse right
    for(int i = y; i < n - 1; i++)
    {
        cout<< array[x][i];
        cout<< " ";
    }

    //traverse down
    for(int i = x; i < m - 1; i++)
    {
        cout<< array[i][y + (n - 1) - count];
        cout<< " ";
    }

    //traverse left
    for(int i = n - 1; i > y; i--)
    {
        cout<< array[x + (m - 1) - count][i];
        cout<< " ";
    }

    //traverse up
    for(int i = m - 1; i > x; i--)
    {
        cout<< array[i][y];
        cout<< " ";
    }
}

void traverse(int array[5][4], int m, int n, int x, int y)
{
    int no_of_loops = (m+n)/n;
    // break out of recursion
    while(count < no_of_loops)
    {
        // now traverse
        one_single_traverse(array, m, n, x, y);
        m--; n--;
        x++; y++;

        count++;
    }
}

int main(void)
{
    int a[5][4] = { {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16},
                    {17, 18, 19, 20}
                                };
    cout<<"Actual: "<<endl;
    traverse(a, 5, 4, 0, 0);
    cout<<endl<<"Expected: ";
    cout<<endl<<"1 2 3 4 8 12 16 20 19 18 17 13 9 5 6 7 11 15 14 10"<<endl;
    return 0;
}
