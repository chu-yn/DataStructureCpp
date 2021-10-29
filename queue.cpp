#include <iostream>
using namespace std;
#define Max 10

class queue
{
private:
    char Item[Max];
    int start, end;

public:
    queue()
    {
        start = -1;
        end = -1;
    }
    void enqueue_f();
    void dequeue_f();
};

void queue::enqueue_f(void)
{
    if (end >= Max - 1)
        cout << "Full" << endl;
    else
    {
        end++;
        cout << "Insert a number:" << endl;
        cin >> Item[end];
    }
}

void queue::dequeue_f(void)
{
    if (start >= end)
        cout << "Empty" << endl;
    else
    {
        start++;
        cout << "Item " << Item[start] << " deleted" << endl;
    }
}

int main()
{
    queue s1;
    for (int i = 0; i < 4; i++)
    {
        s1.enqueue_f();
    }

    for (int i = 0; i < 5; i++)
    {
        s1.dequeue_f();
    }
}