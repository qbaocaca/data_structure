#include "min_heap.h"
#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
min_heap::min_heap(int n)
{
    this->A = new int[n];
    this->capacity_a = n;
    this->na = 0;
}

void min_heap::heapify(int i)
{
    int root = i;
    int left = this->left(i);
    int right = this->right(i);
    if (left < this->na && this->A[left] < this->A[root])
        root = left;
    if (right < this->na && this->A[right] < this->A[root])
        root = right;
    if (root != i)
    {
        swap(&this->A[root], &this->A[i]);
        this->heapify(root);
    }
}

void min_heap::insert(int x)
{
    if (this->na == this->capacity_a)
    {
        cout << "Heap already full!" << endl;
        return;
    }
    else
    {
        this->A[this->na++] = x;
        if (this->A[this->na - 1] < this->parent(this->na - 1))
            this->build_heap();
    }
}

int min_heap::left(int i)
{
    return 2 * i + 1;
}

int min_heap::right(int i)
{
    return 2 * i + 2;
}

int min_heap::parent(int i)
{
    return (i - 1) / 2;
}

void min_heap::print()
{
    for (int i = 0; i < this->na; i++)
    {
        if (i == this->na - 1)
            cout << this->A[i];
        else
            cout << this->A[i] << " ";
    }
}

min_heap &min_heap::decreaseKey(int index, int value)
{
    this->A[index] = value;
    this->build_heap();
    return *this;
}

void min_heap::build_heap()
{
    for (int i = this->na / 2 - 1; i >= 0; i--)
    {
        this->heapify(i);
    }
}

min_heap &min_heap::delete_(int i)
{
    swap(&this->A[0], &this->A[i]);
    this->extract_min();
    return *this;
}

int min_heap::extract_min()
{
    if (this->capacity_a == 1)
    {
        this->capacity_a = this->na = 0;
        return this->A[0];
    }

    int root = this->A[0];
    this->A[0] = this->A[this->na - 1];
    this->na--;
    this->build_heap();
    return root;
}
