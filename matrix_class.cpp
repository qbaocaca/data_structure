#include <iostream>
#include "matrix.h"
#include <stack>
#include <cstdlib>

using namespace std;

void Matrix::deepcopy(const Matrix &other)
{
    this->rows = other.rows;
    this->cols = other.cols;

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->A[i].setElement(j, other.A[i].getElement(j));
        }
    }
}

Matrix::Matrix()
{
    allocate_(this->A, 1, 1);
    this->rows = this->cols = 1;
    this->A[0].setElement(0, 0);
}

Matrix::Matrix(int x, int y)
{
    allocate_(this->A, x, y);
    this->rows = x;
    this->cols = y;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->A[i].setElement(j, 0);
        }
    }
}

void Matrix::input()
{
    for (int i = 0; i < this->rows; i++)
    {
        this->A[i].set_na(this->cols);
        cin >> A[i];
    }
}

void Matrix::output()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            cout << this->A[i].getElement(j) << " ";
        }
        cout << endl;
    }
}

void Matrix::insert(int rows, int cols, int x)
{
    this->A[rows].setElement(cols, x);
}

int Matrix::findCelebrity()
{
    stack<int> st;
    for (int i = 0; i < this->rows; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();
        if (this->knows(A, B))
            st.push(B);
        else
            st.push(A);
    }

    if (st.empty())
        return -1;

    int C;
    C = st.top();
    st.pop();

    for (int i = 0; i < this->rows; i++)
    {
        if ((i != C) && (this->knows(C, i) || !(this->knows(i, C))))
            return -1;
    }

    return C;
}

// Matrix::~Matrix()
// {
//     delete[] this->A;
// }

Matrix::Matrix(const Matrix &other)
{
    allocate_(this->A, other.rows, other.cols);
    this->deepcopy(other);
    this->rows = other.rows;
    this->cols = other.cols;
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
        return *this;
    if (this->rows != other.rows || this->cols != other.cols)
    {
        delete[] this->A;
    }
    allocate_(this->A, other.rows, other.cols);
    this->deepcopy(other);
    this->rows = other.rows;
    this->cols = other.cols;
    return *this;
}

void Matrix::create_identity(int size)
{
    this->rows = this->cols = size;
    allocate_(this->A, this->rows, this->cols);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                this->A[i].setElement(j, 1);
            }
            else
            {
                this->A[i].setElement(j, 0);
            }
        }
    }
}

void Matrix::create_celeb_test(int size)
{
    this->rows = this->cols = size;
    allocate_(this->A, this->rows, this->cols);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                this->A[i].setElement(j, 0);
            }
            else
            {
                int x = rand() % 2;
                this->A[i].setElement(j, x);
            }
        }
    }
}

int Matrix::view_rows()
{
    return this->rows;
}

int Matrix::view_cols()
{
    return this->cols;
}

bool Matrix::knows(int rows, int cols)
{
    return this->A[rows].getElement(cols);
}

istream &operator>>(istream &in, Matrix &a)
{
    for (int i = 0; i < a.view_rows(); i++)
    {
        a.A[i].set_na(a.view_cols());
        in >> a.A[i];
    }
    return in;
}

ostream &operator<<(ostream &out, Matrix a)
{
    for (int i = 0; i < a.view_rows(); i++)
    {
        for (int j = 0; j < a.view_cols(); j++)
        {
            out << a.A[i].getElement(j) << " ";
        }
        cout << endl;
    }
    return out;
}
