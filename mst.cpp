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
        cout << "Top [" << ptr->from << "]\tEnd [" << ptr->to
             << "]\tPath [" << ptr->val << "]" << endl;
        ptr = ptr->next;
    }
    cout << "MST:" << endl;
    mintree(head);
    delete newnode;
    return 0;
}

node *findmincost(node *head)
{
    int minval = 100;
    node *ptr, *retptr;
    ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->val < minval && ptr->find == 0)
        {
            minval = ptr->val;
            retptr = ptr;
        }
        ptr = ptr->next;
    }
    retptr->find = 1;
    return retptr;
}

void mintree(node *head)
{
    node *ptr, *mceptr;
    int result = 0;
    ptr = head;
    for (int i = 0; i <= VERTS; i++)
        v[i] = 0;

    while (ptr != nullptr)
    {
        mceptr = findmincost(head);
        v[mceptr->from]++;
        v[mceptr->to]++;
        if (v[mceptr->from] > 1 && v[mceptr->to] > 1)
        {
            v[mceptr->from]--;
            v[mceptr->to]--;
            result = 1;
        }
        else
        {
            result = 0;
        }
        if (result == 0)
            cout << "Top [" << mceptr->from << "]\tEnd ["
                 << mceptr->to << "]\tPath [" << mceptr->val << "]" << endl;

        ptr = ptr->next;
    }
}