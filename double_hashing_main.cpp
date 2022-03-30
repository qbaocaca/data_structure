#include <iostream>
#include "double_hash.h"
#include "double_hash.cpp"

using namespace std;

int main()
{
    doubleHash a(13);
    // a.print();
    // cout << a.getPrimeNum();

    int x;
    while (true)
    {
        cin >> x;
        if (x == 0)
            break;
        a.insert(x);
    }
    a.print();

    cout << endl;

    // while (true)
    // {
    //     cin >> x;
    //     if (x == 0)
    //         break;
    //     // cout << a.search(x);
    //     // cout << endl;
    //     a.erase(x);
    //     a.print();
    //     cout << endl;
    // }

    a.erase(115).erase(87);
    a.print();

    return 0;
}
