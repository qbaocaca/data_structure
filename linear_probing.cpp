#include <iostream>

using namespace std;
int function(int);
int main()
{
    int *arr, n;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int *hash, m;
    cin >> m;
    hash = new int[m];
    for (int i = 0; i < m; i++)
    {
        hash[i] = 0;
    }
    int i = 0, j = 1;
    int na = n;
    while (na > 0)
    {
        int index = function(arr[i]) % m;
        if (hash[index] != 0)
        {
            int new_index = index;
            while (hash[new_index] != 0)
            {
                new_index = (function(arr[i]) + j) % m;
                if (new_index >= m)
                    break;
                j++;
            }
            if (new_index < m)
                hash[new_index] = arr[i];
        }
        else
            hash[index] = arr[i];
        i++;
        --na;
        j = 1;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
            cout << hash[i];
        else
            cout << hash[i] << " ";
    }

    return 0;
}

int function(int x)
{
    return 2 * x + 5;
}
