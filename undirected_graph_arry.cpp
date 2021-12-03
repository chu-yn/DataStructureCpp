#include <iostream>
using namespace std;

int main(void)
{
    int arr[6][6];
    int data[14][2] = {{1, 2},
                       {2, 1},
                       {1, 5},
                       {5, 1},
                       {2, 3},
                       {3, 2},
                       {2, 4},
                       {4, 2},
                       {3, 4},
                       {4, 3},
                       {3, 5},
                       {5, 3},
                       {4, 5},
                       {5, 4}};

    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < 14; i++)
        arr[data[i][0]][data[i][1]] = 1;

    cout << "輸出無向圖" << endl;
    for (int i = 1; i < 6; i++)
    {
        cout << "  " << i;
    }
    cout << endl;
    for (int i = 1; i < 6; i++)
    {
        cout << i << "";
        for (int j = 1; j < 6; j++)
        {
            cout << "[" << arr[i][j] << "]";
        }
        cout << endl;
    }

    return 0;
}