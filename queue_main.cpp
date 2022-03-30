#include <iostream>
// #include "queue.h"
// #include "queue_class.cpp"
#include "circular_queue.h"
#include "circular_queue.cpp"

using namespace std;

bool check_prime(int);

int main()
{

    // Queue a(1000);
    // int x;
    // while (true)
    // {
    //     cin >> x;
    //     if (x == 0)
    //         break;
    //     a.enqueue(x);
    // }

    // int n;
    // cin >> n;
    // int i = 0;
    // // int x;
    // while (i < n)
    // {
    //     // cin >> x;
    //     a.enqueue(i);
    //     i++;
    // }
    // a.display();
    // cout << endl;

    // a.enqueue(1).enqueue(100).enqueue(1000);
    // while (!a.isEmpty())
    // {
    //     // cout << "capacity=" << a.getCapacity() << endl;
    //     a.dequeue();
    //     a.display();
    //     cout << endl;
    // }

    // int k;
    // cin >> k;
    // i = 0;
    // while (i < k)
    // {
    //     int temp = a.dequeue_();
    //     a.enqueue(temp);
    //     cout << "Run_" << i + 1 << ": ";
    //     a.display();
    //     cout << endl;
    //     i++;
    // }
    // cout << endl;
    // a.display();

    // int n;
    // cin >> n;

    // for (int i = 2; i <= n, i < 10; i++)
    // {
    //     if (i <= n && check_prime(i))
    //         a.enqueue(i);
    // }

    // while (!a.isEmpty())
    // {
    //     for (int i = 1; i <= 9; i++)
    //     {
    //         int temp = a.getFront() * 10 + i;
    //         if (temp <= n && check_prime(temp))
    //             a.enqueue(temp);
    //     }
    //     cout << a.getFront() << " ";
    //     a.dequeue();
    // }

    // int m;
    // cin >> m;
    // int *A = new int[m];
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> A[i];
    // }
    // int k;
    // cin >> k;
    // int *b = new int[1000];
    // a.enqueue(A[0]);
    // int nb_ = 0;
    // b[nb_++] = A[0];
    // int i = 1;
    // int flag = 0;
    // int z = 1;
    // while (i < m)
    // {
    //     for (int j = 0; j < nb_; j++)
    //     {
    //         if (A[i] == b[j])
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag != 1 && z < k)
    //     {
    //         a.enqueue(A[i]);
    //         b[nb_++] = A[i];
    //         z++;
    //     }
    //     else if (flag != 1)
    //     {
    //         a.dequeue();
    //         a.enqueue(A[i]);
    //         b[nb_++] = A[i];
    //     }
    //     else if (flag == 1 && z >= k)
    //     {
    //         if (!a.exists(A[i]))
    //         {
    //             a.dequeue();
    //             a.enqueue(A[i]);
    //         }
    //     }
    //     if (flag == 1)
    //         flag = 0;
    //     i++;
    // }
    // a.display();

    cirqueue a(5);
    int i = 0;
    while (i < 5)
    {
        a.enqueue(i);
        i++;
    }
    a.display();

    a.dequeue().dequeue();
    a.enqueue(100).enqueue(200);
    a.enqueue(300);

    cout << endl;
    a.display();

    return 0;
}

bool check_prime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i <= x / 2; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
