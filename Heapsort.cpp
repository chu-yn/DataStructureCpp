#include <iostream>
using namespace std;
void swap(int &i, int &j);
void heapify(int *iarr, int n, int i);

int main()
{
    int arry[] = {0, 23, 65, 99};
    heapify(arry, 3, 1);
    for (int i = 1; i <= 3; i++)
    {
        cout << arry[i] << endl;
    }

    return 0;
}

void swap(int &i, int &j)
{
    int tmp;
    tmp = i;
    i = j;
    j = tmp;
}

void heapify(int *iarr, int n, int i)
{
    int dad = i;
    int son = dad * 2;
    while (son <= n) { 
        if (son + 1 <= n && iarr[son] < iarr[son + 1])
            son++;
        if (iarr[dad] > iarr[son])
            return;
        else {
            swap(iarr[dad], iarr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
