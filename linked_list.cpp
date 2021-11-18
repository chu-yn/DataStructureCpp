#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node() { next = NULL; }
};

class queue1
{
public:
    node head;
    void enque()
    {
        node *Node = new node();
        cout << "input data: ";
        cin >> Node->data;
        if (head.next == NULL)
        {
            head.next = Node;
            return;
        }

        node *p = head.next;
        while (p->next != NULL)
            p = p->next;

        p->next = Node;
    }
    
    void deque()
    {
        if (head.next == NULL)
        {
            cout << "Queue empty" << endl;
            return;
        }
        node *prev, *current;
        prev = &head;
        current = head.next;
        prev->next = current->next;
        cout << current->data << endl;
        delete current;
    }
};

class stack1
{
public:
    node head;
    void push()
    {
        node *Node = new node();
        cout << "input data: ";
        cin >> Node->data;
        if (head.next == NULL)
        {
            head.next = Node;
            return;
        }
        node *p = head.next;
        while (p->next != NULL)
            p = p->next;

        p->next = Node;
    }

    void pop()
    {
        node *prev, *current;
        prev = &head;
        current = head.next;
        if (head.next == NULL)
        {
            cout << "Stack empty" << endl;
            return;
        }
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        cout << current->data << endl;
        delete current;
        prev->next = NULL;
    }
};

int main()
{
    queue1 Queue1;
    for (int i = 0; i < 4; i++)
        Queue1.enque();
    for (int i = 0; i < 5; i++)
        Queue1.deque();
    return 0;
}