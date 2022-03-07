#ifndef array_h
#define array_h
#include <iostream>
using namespace std;

void allocate(int *&a, int size)
{
    a = new int[size];
}

void delete_(int *a)
{
    delete[] a;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class Array
{
private:
    /* data */
    int *A;
    int na = 0;
    int capacity_a = 1;

    void deepcopy(const Array &a);

public:
    Array(/* args */);
    ~Array();

    Array(int);

    void insert(int);
    Array(const Array &other);
    void print();
    Array &operator=(const Array &other);
    Array operator+(Array other);
    int view_na();
    void set_na(int);
    int getElement(int index);
    void setElement(int index, int value);
    void quicksort(int left, int right);

    friend istream &operator>>(istream &in, Array &a);
    friend ostream &operator<<(ostream &out, Array a);
};

#endif