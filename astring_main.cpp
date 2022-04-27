#include <iostream>
#include "Astring.h"
#include "Astring_class.cpp"

using namespace std;

int main()
{
    // Astring a;
    // STRING x;
    // while (1)
    // {
    //     cin >> x;
    //     if (x == "null")
    //         break;
    //     a.insert(x);
    // }
    // a.output();

    // Astring b(a);
    // cout << endl;
    // b.output();

    // Astring c;
    // c = b;
    // cout << endl;
    // c.output();

    // for (int i = 0; i < 10000; i++)
    // {
    //     c = a;
    // }

    // cout << endl;
    // int flag = 0;
    // for (int i = 0; i < a.getLen(); i++)
    // {
    //     if (c.getContent(i) != a.getContent(i))
    //     {
    //         cout << "WRONG!";
    //         flag = 1;
    //         break;
    //     }
    // }
    // if (flag == 0)
    //     cout << "OK!";

    Astring a;
    cin >> a;
    cout << a;

    // Astring a(3);
    // int i = 0;
    // STRING x;
    // while (i < 3)
    // {
    //     cin >> x;
    //     a.setContent(i, x);
    //     i++;
    // }
    // a.setna(i);
    // a.output();

    return 0;
}