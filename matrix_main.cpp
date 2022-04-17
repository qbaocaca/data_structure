#include <iostream>
#include "matrix.h"
#include "matrix_class.cpp"
#include <ctime>

using namespace std;

int main()
{
    // Matrix a;
    // a.output();
    // Matrix b(3, 2);
    // b.output();
    // cout << b;
    // cout << endl;

    // Matrix a(3, 3);
    // a.input();
    // a.output();

    Matrix a(3, 2);
    cin >> a;
    cout << a;

    // Matrix b(a);
    // cout << endl;
    // cout << b;

    // Matrix c;
    // c = a;
    // cout << endl;
    // cout << c;

    // cout << endl;
    // b = a;
    // cout << b;

    // int num_people = 4;

    // int acquaintances[][num_people] = {{0, 1, 1, 1},
    //                                    {1, 0, 1, 0},
    //                                    {0, 0, 0, 0},
    //                                    {1, 0, 1, 0}};

    // Matrix a(num_people, num_people);
    // for (int i = 0; i < num_people; i++)
    // {
    //     for (int j = 0; j < num_people; j++)
    //     {
    //         a.insert(i, j, acquaintances[i][j]);
    //     }
    // }

    // cout << a;
    // cout << a.knows(0, 0);

    // srand(time(NULL));
    // Matrix a;
    // a.create_celeb_test(10);
    // cout << a;

    // int celebrity = a.findCelebrity();

    // if (celebrity == -1)
    // {
    //     cout << "No Celebrity" << endl;
    // }
    // else
    //     cout << "Celebrity ID = " << celebrity << endl;

    // Matrix a;
    // a.create_identity(5);
    // cout << a;

    // Matrix b(a);
    // cout << b;
    // Matrix c, d;
    // c = a + b;
    // cout << c;
    // cout << a;

    Matrix b(2, 3);
    cin >> b;
    cout << b;

    Matrix c;
    c = a * b;
    cout << c;

    return 0;
}