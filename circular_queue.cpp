#include "circular_queue.h"
#include <iostream>
using namespace std;

cirqueue::cirqueue(int size)
{
    this->front = this->rear = -1;
    allocate(this->A, size);
    this->size = size;
}

bool cirqueue::isEmpty()
{
    return this->front == -1;
}

bool cirqueue::isFull()
{
    if (this->front == 0 && this->rear == this->size - 1)
        return 1;
    else if (this->front == this->rear + 1)
        return 1;
    return 0;
}

// cirqueue &cirqueue::enqueue(int x)
// {
//     if (isFull())
//         cout << "Queue Full";
//     else if (this->front == -1)
//         this->front = 0;
//     this->rear = (this->rear + 1) % this->size;
//     this->A[this->rear] = x;
//     return *this;
// }

cirqueue &cirqueue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Full";
        return *this;
    }

    if (this->front == -1)
        this->front = 0;

    if (this->rear == this->size - 1 && this->front != 0)
    {
        this->rear = -1;
    }
    this->rear++;
    this->A[this->rear] = x;
    return *this;
}

// cirqueue &cirqueue::dequeue()
// {
//     if (isEmpty())
//         cout << "Queue Empty";
//     else if (this->front == this->rear)
//         this->front = this->rear = -1;
//     else
//         this->front = (this->front + 1) % this->size;
//     return *this;
// }

cirqueue &cirqueue::dequeue()
{
    if (this->isEmpty())
    {
        cout << "Queue Empty";
        return *this;
    }

    this->front++;
    if (this->front == this->rear)
        this->front = this->rear = -1;
    else if (this->front == this->size - 1)
        this->front = 0;
    return *this;
}

// void cirqueue::display()
// {
//     int i = this->front;
//     while (i != this->rear)
//     {
//         cout << this->A[i] << " <--- ";
//         i = (i + 1) % this->size;
//     }
//     cout << this->A[this->rear];
// }

// visualize cirqueue in practice
void cirqueue::display()
{
    if (isEmpty())
        cout << "Queue Empty";
    else
    {
        if (this->front <= rear)
        {
            for (int i = this->front; i < this->rear; i++)
            {
                cout << this->A[i] << " <--- ";
            }
            cout << this->A[this->rear];
        }
        else
        {
            for (int i = 0; i <= this->rear; i++)
            {
                cout << this->A[i] << " <--- ";
            }

            for (int i = this->front; i < this->size - 1; i++)
            {
                cout << this->A[i] << " <--- ";
            }
            cout << this->A[this->size - 1];
        }
    }
}