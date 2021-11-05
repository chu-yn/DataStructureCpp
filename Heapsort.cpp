#include <iostream>
using namespace std;
void swap(int &i, int &j);
void heapify(int *iarr, int n, int i);
bool checkheaptree(int *iarr, int n);

int main()
{
    int arry[] = {0, 23, 65, 8, 29, 99, 9};
    bool isheaptree = false;

    cout << "Origin:" << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arry[i] << endl;
    }
    while (!isheaptree)
    {
        for (int i = 3; i >= 1; i--)
        {
            heapify(arry, 6, i);
        }
        isheaptree = checkheaptree(arry, 6);
    }

    cout << "heaptree:" << endl;
    for (int i = 1; i <= 6; i++)
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

bool checkheaptree(int *iarr, int n)
{
    int i = 1;
    int left = 2 * i;
    int right = left + 1;
    while (i <= n)
    {
        if (left <= n && iarr[i] < iarr[left])
            return false;
        if (right <= n && iarr[i] < iarr[right])
            return false;
        i++;
        left = 2 * i;
        right = left + 1;
    }
    return true;
}
