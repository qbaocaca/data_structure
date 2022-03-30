#include <iostream>
#include <math.h>
#define MAX 1000
using namespace std;

bool has[MAX + 1][2];
void insert(int *a, int n);
bool search(int key);

int main()
{
    int *a, n;
    cin >> n;
    a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insert(a, n);
    int x;
    cin >> x;
    cout << endl;
    cout << search(x) << endl;
    delete[] a;
    return 0;
}

void insert(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            has[a[i]][0] = 1;
        else
            has[abs(a[i])][1] = 1;
    }
}

bool search(int key)
{
    if (key >= 0)
    {
        if (has[key][0] == 1)
            return 1;
    }
    else if (has[abs(key)][1] == 1)
        return 1;
    return 0;
}
