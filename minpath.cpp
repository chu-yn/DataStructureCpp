#include <iostream>
using namespace std;

int main()
{
    int path[8][8];
    int data[12][2] = {{1, 2}, {1, 4}, {2, 3}, {2, 5}, {3, 5}, {3, 6}, {4, 3}, {4, 6}, {5, 3}, {5, 7}, {6, 5}, {6, 7}};

    for (int i = 1; i < 8; i++)
        for (int j = 1; j < 8; j++)
            path[i][j] = 0;

    for (int i = 0; i < 12; i++)
        path[data[i][0]][data[i][1]] = 1;

    cout << "Path" << endl;
    cout << " ";
    for (int i = 1; i < 8; i++)
        cout << "  " << i;
    cout << endl;
    for (int i = 1; i < 8; i++)
    {
        cout << i << " ";
        for (int j = 1; j < 8; j++)
        {
            cout << "[" << path[i][j] << "]";
        }
        cout << endl;
    }
    return 0;
}