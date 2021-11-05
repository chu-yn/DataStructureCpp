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
    int j = i * 2; // left
    int k = j + 1; // right
    if (j <= n && iarr[i] < iarr[j])
        swap(iarr[i], iarr[j]);
    if (k <= n && iarr[i] < iarr[k])
        swap(iarr[i], iarr[k]);
}
