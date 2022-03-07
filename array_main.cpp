#include <iostream>
#include "array_class.cpp"
#include "array.h"

using namespace std;

void input(Array &, int &);

int main()
{
    // Array a;
    // int x;
    // while (true)
    // {
    //     cin >> x;
    //     if (x == 0)
    //         break;
    //     a.insert(x);
    // }
    // a.print();

    // int m;
    // cin >> m;
    // Array *a = new Array[m];
    // int x;
    // for (int i = 0; i < m; i++)
    // {
    //     input(a[i], x);
    // }
    // cout << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     a[i].print();
    //     cout << endl;
    // }

    // cout << endl;
    // Array b(a);
    // b.print();
    // Array c;
    // c = a;
    // c.print();

    // Array a;
    // cin >> a;
    // a.print();
    // cout << a;

    // Array a, b;
    // cin >> a >> b;
    // cout << a << endl
    //      << b << endl;
    // Array c;
    // c = a + b;
    // cout << c << endl;
    // cout << c.view_na();

    //     Array a;
    //     cin >> a;
    //     cout << a << endl;
    //     a.quicksort(0, a.view_na() - 1);
    //     cout << a;

    // Array a(5);
    // cin >> a;
    // cout << a << endl;

    return 0;
}

void input(Array &a, int &x)
{
    while (true)
    {
        cin >> x;
        if (x == 0)
            break;
        a.insert(x);
    }
}