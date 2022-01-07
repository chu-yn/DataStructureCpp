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

class hash_linklist
{
public:
    Node index_table[imax];
    void Add_data(int val)
    {
        Node *newnode = new Node(val);
        int hash = val % 7;
        Node *current = &index_table[hash];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newnode;
    }

    void print_data()
    {
        Node *head;
        for (int i = 0; i < imax; i++)
        {
            cout << "hash[" << i << "]:";
            if (index_table[i].next != nullptr)
            {
                head = index_table[i].next;
                do
                {
                    cout << "[" << head->val << "]";
                    head = head->next;
                } while (head != nullptr);
            }
            cout << endl;
        }
    }
};

int main()
{
    hash_linklist list;
    int arry[] = {93, 76, 21, 33, 56, 43, 29, 171, 10, 15, 11, 89, 99, 100, 77};
    for (int item : arry)
    {
        list.Add_data(item);
    }
    list.print_data();

    return 0;
}