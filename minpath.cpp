#include <iostream>
#include <iomanip>
#define SIZE 8
#define INFITE 99999
using namespace std;

int main()
{
    // matrix
    int path[SIZE][SIZE];
    int data[12][3] = {{1, 2, 4}, {1, 4, 6}, {2, 3, 1}, {2, 5, 7}, {3, 5, 6}, {3, 6, 4}, {4, 3, 2}, {4, 6, 5}, {5, 3, 6}, {5, 7, 6}, {6, 5, 1}, {6, 7, 8}};

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            if (i == j)
                path[i][j] = 0;
            else
                path[i][j] = INFITE;
        }
    }

    for (int i = 0; i < 12; i++)
        path[data[i][0]][data[i][1]] = data[i][2];

    cout << "Matrix:" << endl
         << "Vertex";
    for (int i = 1; i < 8; i++)
        cout << setw(4) << "vex" << i;

    cout << endl;

    for (int i = 1; i < SIZE; i++)
    {
        cout << "vex" << i;
        for (int j = 1; j < SIZE; j++)
        {
            if (path[i][j] == INFITE)
            {
                cout << setw(5) << 'X';
            }
            else
            {
                cout << setw(5) << path[i][j];
            }
        }
        cout << endl;
    }

    /* for (int i = 0; i < 12; i++)
        path[data[i][0]][data[i][1]] = data[i][2];

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
            cout << " " << path[i][j] << " ";
        }
        cout << endl;
    } */

    return 0;
}