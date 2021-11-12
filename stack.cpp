#include <iostream>
using namespace std;
#define Max 100

class stack
{
private:
    char Item[Max];
    int Top;

public:
    stack()
    {
        Top = -1;
    };
    void push_f();
    void pop_f();
};

void stack::push_f()
{
    if (Top >= Max - 1)
        cerr << "Stack is full";
    else
    {
        Top++;
        cout << "Please input item:\n";
        cin >> Item[Top];
    }
}

void stack::pop_f()
{
    if (Top > -1)
    {
        cout << "Item " << Item[Top] << " deleted\n";
        Top--;
    }
    else
    {
        cerr << "Stack is Empty.\n";
    }
}

int main()
{
    int i;
    stack s1;
    for (int i = 0; i < 4; i++){
        
    }
        s1.push_f();
    for (int i = 0; i < 5; i++)
        s1.pop_f();
}
