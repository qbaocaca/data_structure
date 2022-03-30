#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    bool check[n + 1];
    for (int i = 0; i <= n; i++)
    {
        check[i] = 1;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (check[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
                check[j] = 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (check[i] == 1)
            cout << i << " ";
    }

    return 0;
}
