#include <iostream>
#include "array.h"
using namespace std;

void Array::deepcopy(const Array &a)
{
    this->na = a.na;
    for (int i = 0; i < this->na; i++)
    {
        this->A[i] = a.A[i];
    }
}

Array::Array()
{
    allocate(this->A, 1);
    this->na = 0;
    this->capacity_a = 1;
}

Array::~Array()
{
    delete_(this->A);
}

Array::Array(int num_elements)
{
    allocate(this->A, num_elements);
    this->na = 0;
    this->capacity_a = num_elements;
}

void Array::insert(int x)
{
    if (this->na == 0)
    {
        allocate(this->A, 1);
        this->A[0] = x;
        this->na++;
    }
    else if (this->na == this->capacity_a)
    {
        this->capacity_a = 2 * this->na + 1;
        int *B;
        allocate(B, this->capacity_a);
        for (int i = 0; i < this->na; i++)
        {
            B[i] = this->A[i];
        }
        B[this->na] = x;
        delete_(this->A);
        allocate(this->A, this->capacity_a);
        for (int i = 0; i <= this->na; i++)
        {
            this->A[i] = B[i];
        }
        this->na++;
        delete_(B);
    }
    else
    {
        this->A[this->na] = x;
        this->na++;
    }
}

Array::Array(const Array &other)
{
    allocate(this->A, other.na);
    this->deepcopy(other);
}

void Array::print()
{
    for (int i = 0; i < this->na; i++)
    {
        cout << this->A[i] << " ";
    }
}

Array &Array::operator=(const Array &other)
{
    delete_(this->A);
    allocate(this->A, other.na);
    this->deepcopy(other);
    return *this;
}

Array Array::operator+(Array other)
{
    Array a;
    a.na = this->na + other.na;
    for (int i = 0; i < a.na; i++)
    {
        if (i < this->na)
        {
            a.A[i] = this->A[i];
        }
        else
        {
            a.A[i] = other.A[i - this->na];
        }
    }
    return a;
}

int Array::view_na()
{
    return this->na;
}

void Array::set_na(int x)
{
    this->na = x;
}

int Array::getElement(int index)
{
    return this->A[index];
}

void Array::setElement(int index, int value)
{
    this->A[index] = value;
}

void Array::quicksort(int left, int right)
{
    int i = left, j = right;
    int x = this->A[(left + right) / 2];
    while (i <= j)
    {
        while (this->A[i] < x)
            i++;
        while (this->A[j] > x)
            j--;
        if (i <= j)
        {
            swap(&this->A[i], &this->A[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        this->quicksort(left, j);
    if (i < right)
        this->quicksort(i, right);
}

istream &operator>>(istream &in, Array &a)
{
    // int x;
    // while (true)
    // {
    //     in >> x;
    //     if (x == 0)
    //         break;
    //     a.insert(x);
    // }
    // return in;

    int x;
    for (int i = 0; i < a.view_na(); i++)
    {
        in >> x;
        a.A[i] = x;
    }
    return in;
}

ostream &operator<<(ostream &out, Array a)
{
    for (int i = 0; i < a.na; i++)
    {
        out << a.A[i] << " ";
    }
    return out;
}
