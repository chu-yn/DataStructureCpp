#include <iostream>
using namespace std;
class list
{
public:
    int val;
    list *next;
    list() { next = NULL; }
};

int main(void)
{
    list head[6];
    list *ptr;
    list *newnode;
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
    cout << "list content" << endl;
    for (int i = 1; i < 6; i++)
    {
        head[i].val = i;
        cout << "top " << i << "=>";
        ptr = &(head[i]);
        for (int j = 0; j < 14; j++)
        {
            if (data[j][0] == i)
            {
                newnode = new list;
                newnode->val = data[j][1];
                while (ptr->next != NULL)
                    ptr = ptr->next;
                ptr->next = newnode;
                cout << "[" << newnode->val << "]";
            }
        }
    }
    return 0;
}