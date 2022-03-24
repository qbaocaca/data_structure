#include <iostream>
#include "min_heap.h"
#include "min_heap.cpp"

using namespace std;

int main()
{
    min_heap a(10);
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        a.insert(x);
    }
    a.print();

    // cout << endl;
    // a.decreaseKey(3, 11);
    // a.print();
    // cout << endl;
    // a.decreaseKey(4, 1).decreaseKey(6, 2);
    // a.print();

    a.delete_(3);
    cout << endl;
    a.print();
    a.delete_(1);
    cout << endl;
    a.print();
    a.delete_(2);
    cout << endl;
    a.print();

    // cout << endl;
    // cout << a.extract_min();
    // a.delete_(3).delete_(1).delete_(2);
    // cout << endl;
    // a.print();
    return 0;
}
