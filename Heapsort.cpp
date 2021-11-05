#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 10, b = 5;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    swap(a, b);
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    return 0;
}