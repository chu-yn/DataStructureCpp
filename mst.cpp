#include <iostream>
#define VERTS 6
using namespace std;

class node
{
public:
    int from, to, find, val;
    class node *next;
};
void mintree(node *head);
node *findmincost(node *head);
int v[VERTS + 1];

int main(void)
{
    int data[10][3] = {{1, 2, 6},
                       {1, 6, 12},
                       {1, 5, 10},
                       {2, 3, 3},
                       {2, 4, 5},
                       {2, 6, 8},
                       {3, 4, 7},
                       {4, 6, 11},
                       {4, 5, 9},
                       {5, 6, 16}};
    node *head, *ptr, *newnode;
    head = nullptr;
    cout << "Graph link:" << endl;
    for (int i = 0; i < 10; i++)
    {
        newnode = new node;
        newnode->from = data[i][0];
        newnode->to = data[i][1];
        newnode->val = data[i][2];
        newnode->find = 0;
        newnode->next = nullptr;
        if (head == nullptr)
        {
            head = newnode;
            head->next = nullptr;
            ptr = head;
        }
        else
        {
            ptr->next = newnode;
            ptr = ptr->next;
        }
    }
    ptr = head;
    while (ptr != nullptr)
    {
        cout << "Top [" << ptr->from << "] \t End [" << ptr->to
             << "]\tPath [" << ptr->val << "]" << endl;
        ptr = ptr->next;
    }

    return 0;
}
