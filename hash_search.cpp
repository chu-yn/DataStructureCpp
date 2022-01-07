#include <iostream>
using namespace std;
#define imax 7
#define max 15

class Node
{
public:
    int val;
    Node *next;

    Node(int value = 0)
    {
        val = value;
        next = nullptr;
    }
};