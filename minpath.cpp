#include <iostream>
#include <iomanip>
#define SIZE 8
#define INFITE 99999
using namespace std;

int path[SIZE][SIZE];
int minpath[SIZE][SIZE];
void shortestpath(int vertex1, int vertex_total);

int main()
{
    // path matrix generate
    int data[12][3] = {{1, 2, 4}, {1, 4, 6}, {2, 3, 1}, {2, 5, 7}, {3, 5, 6}, {3, 6, 4}, {4, 3, 2}, {4, 6, 5}, {5, 3, 6}, {5, 7, 6}, {6, 5, 1}, {6, 7, 8}};
    // initial matrix
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
    // put value into matrix
    for (int i = 0; i < 12; i++)
        path[data[i][0]][data[i][1]] = data[i][2];
    // show path matrix
    cout << "Path Matrix:" << endl
         << "Vertex";
    for (int i = 1; i < SIZE; i++)
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
    // min path matrix
    cout << endl;
    for (int i = 1; i < SIZE; i++)
        shortestpath(i, 7);

    cout << "Min Path Matrix:" << endl
         << "Vertex";
    for (int i = 1; i < SIZE; i++)
        cout << setw(4) << "vex" << i;

    cout << endl;

    for (int i = 1; i < SIZE; i++)
    {
        cout << "vex" << i;
        for (int j = 1; j < SIZE; j++)
        {
            if (minpath[i][j] == INFITE)
            {
                cout << setw(5) << 'X';
            }
            else
            {
                cout << setw(5) << minpath[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}

void shortestpath(int vertex1, int vertex_total)
{
    int distance[SIZE];
    int shortest_vertex = 1;
    int shortest_distance;
    int goal[SIZE];
    for (int i = 1; i <= 7; i++)
    {
        goal[i] = 0;
        distance[i] = path[vertex1][i];
    }
    goal[vertex1] = 1;
    distance[vertex1] = 0;
    for (int i = 1; i <= vertex_total - 1; i++)
    {
        shortest_distance = INFITE;
        for (int j = 1; j <= vertex_total; j++)
        {
            if (goal[j] == 0 && shortest_distance > distance[j])
            {
                shortest_distance = distance[j];
                shortest_vertex = j;
            }
        }
        goal[shortest_vertex] = 1;
        for (int j = 1; j <= vertex_total; j++)
        {
            if (goal[j] == 0 && distance[shortest_vertex] + path[shortest_vertex][j] < distance[j])
            {
                distance[j] = distance[shortest_vertex] + path[shortest_vertex][j];
            }
        }
    }
    for (int j = 1; j < SIZE; j++)
    {
        minpath[vertex1][j] = distance[j];
    }
}