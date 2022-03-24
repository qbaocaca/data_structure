#include <iostream>

using namespace std;

void swap(int *a, int *b);
void heapify(int *a, int n, int i);
void insert(int *a, int &n, int x);
int binary_search(int *a, int n, int x);
void quicksort(int *a, int left, int right);
void delete_(int *a, int &n, int x);

int main()
{
    int *arr, n;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // int a;
    // cin >> a;
    // cout << binary_search(arr, n, a);

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int x;
    while (true)
    {
        cin >> x;
        if (x == 0)
            break;
        // insert(arr, n, x);
        delete_(arr, n, x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *a, int n, int i)
{
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[root]) // max heap
                                       // if (left < n && a[left] < a[root]) // min heap
        root = left;
    if (right < n && a[right] > a[root]) // max heap
                                         // if (right < n && a[right] < a[root]) // min heap
        root = right;
    if (root != i)
    {
        swap(a[root], a[i]);
        heapify(a, n, root);
    }
}

void insert(int *a, int &n, int x)
{
    a[n++] = x;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}

void quicksort(int *a, int left, int right)
{
    int i = left, j = right;
    int x = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quicksort(a, left, j);
    if (i < right)
        quicksort(a, i, right);
}

int binary_search(int *a, int n, int x)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void delete_(int *a, int &n, int x)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            index = i;
            break;
        }
    }
    if (index != n - 1)
        swap(&a[index], &a[n - 1]);

    a[n - 1] = a[n];
    --n;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}