#include <iostream>
using namespace std;
class list
{
public:
    int val;
    list *next;
    list() { next = nullptr; }
};

class list head[6];
void dfs(int);
int run[6];

int main(void)
{
    // list head[6];
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
        run[i] = 0;
        head[i].val = i;
        cout << "top " << i << "=>";
        ptr = &(head[i]);
        for (int j = 0; j < 14; j++)
        {
            if (data[j][0] == i)
            {
                newnode = new list;
                newnode->val = data[j][1];
                while (ptr->next != nullptr)
                    ptr = ptr->next;
                ptr->next = newnode;
                cout << "[" << newnode->val << "]";
            }
        }
        cout << endl;
    }
    cout << "DFS:" << endl;
    dfs(1);
    cout << endl;
    return 0;
}

void dfs(int current)
{
    list *ptr;
    run[current] = 1;
    cout << "[" << current << "]";
    ptr = head[current].next;
    while (ptr != nullptr)
    {
        if (run[ptr->val] == 0)
            dfs(ptr->val);
        ptr = ptr->next;
    }
}