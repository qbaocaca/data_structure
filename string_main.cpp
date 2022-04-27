#include <iostream>
#include "string.h"
#include "string_class.cpp"
using namespace std;

int main()
{
    std::string str;
    getline(std::cin, str);
    STRING a(str);
    a.output();
    // STRING b(a);
    // b.output();
    // STRING c;
    // c = b;
    // cout << endl;
    // c.output();

    // STRING a;
    // a.input();
    // a.output();
    // STRING d;
    // cout << endl;
    // d.input();
    // d.output();
    // d = a;
    // cout << endl;
    // d.output();

    // STRING a;
    // cin >> a;
    // cout << a;

    // cout << endl;
    // cin >> a;
    // cout << a;

    // cout << endl;
    // STRING b;
    // cin >> b;
    // cout << b;
    // std::string b;
    // getline(cin, b);
    // cout << b;
    // cout << endl;
    // if (a == b)
    //     cout << "equal";
    // else
    //     cout << "not equal";

    // STRING b;
    // for (int i = 0; i < 10000; i++)
    // {
    //     b = a;
    // }

    // for (int i = 0; i < a.getLen(); i++)
    // {
    //     if (a.getContent(i) != b.getContent(i))
    //     {
    //         cout << "WRONG!";
    //         break;
    //     }
    // }
    // cout << "OK!";

    cout << endl;
    cout << a.getLen();
    // a.removeBlankHead();
    cout << endl;
    // a.removeBlankTail();
    a.RemoveExtraSpaces();
    a.output();
    cout << endl;
    cout << a.getLen();

    return 0;
}