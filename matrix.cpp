#include <iostream>

using namespace std;

void input(int a[][100], int, int);
void output(int a[][100], int, int);

void input_(int **, int, int);
void output_(int **, int, int);

void _input(int **&, int &, int &);

int main()
{
    // int a[100][100];
    // int rows, cols;
    // cin >> rows >> cols;
    // input(a, rows, cols);
    // cout << endl;
    // output(a, rows, cols);

    // int **matrix = new int *[rows * cols];
    // for (int i = 0; i < rows; i++)
    // {
    //     // matrix[i] = new int[cols];
    //     *(matrix + i) = new int[cols];
    // }
    // input_(matrix, rows, cols);
    // output_(matrix, rows, cols);

    int **matrix, rows, cols;
    _input(matrix, rows, cols);
    output_(matrix, rows, cols);

    // int var = 20;
    // cout << "var=" << var << endl;
    // cout << "address of var=" << &var << endl;
    // int *p;
    // p = &var;
    // cout << "address of p=" << p << endl;
    // cout << "value of p=" << *p;

    // int arr[5];
    // int *p;
    // p = arr;
    // int(*ptr)[5];
    // ptr = &arr;

    // cout << "p=" << p << " ptr=" << ptr << endl;
    // p++;
    // ptr++;
    // cout << "p=" << p << " ptr=" << ptr << endl;

    return 0;
}

void input(int a[][100], int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "a[" << i << "]"
                 << "[" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void output(int a[][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void input_(int **a, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "a[" << i << "]"
                 << "[" << j << "]: ";
            // cin >> a[i][j];
            cin >> *(*(a + i) + j);
        }
    }
}

void output_(int **a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // cout << a[i][j] << " ";
            cout << *(*(a + i) + j) << " ";
        }
        cout << endl;
    }
}

void _input(int **&a, int &rows, int &cols)
{
    cin >> rows >> cols;
    a = new int *[rows * cols];
    for (int i = 0; i < rows; i++)
    {
        // a[i] = new int[cols];
        *(a + i) = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "a[" << i << "]"
                 << "[" << j << "]: ";
            // cin >> a[i][j];
            cin >> *(*(a + i) + j);
        }
    }
}
