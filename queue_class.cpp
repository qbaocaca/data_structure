#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue(int size)
{
    allocate(this->A, size);
    this->size = size;
    this->front = this->rear = -1;
    this->capacity = 0;
}

bool Queue::isFull()
{
    return this->front == 0 && this->rear == this->size - 1;
}

bool Queue::isEmpty()
{
    return this->capacity == 0;
}

// Queue &Queue::enqueue(int x)
// {
//     if (isFull())
//         cout << "Queue Full";
//     else
//     {
//         if (this->front == -1)
//         {
//             this->front = 0;
//             this->A[this->front] = x;
//             this->capacity++;
//             this->rear++;
//         }
//         else
//         {
//             int *a = new int[this->size];
//             for (int i = 0; i < this->capacity; i++)
//             {
//                 a[i] = this->A[i];
//             }
//             a[this->capacity] = x;
//             delete_(this->A);
//             allocate(this->A, this->size);
//             for (int i = 0; i <= this->capacity; i++)
//             {
//                 this->A[i] = a[i];
//             }
//             this->rear++;
//             this->capacity++;
//         }
//     }

//     return *this;
// }

Queue &Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Full";
    }
    else
    {
        if (this->front == -1)
            this->front = 0;
        this->rear++;
        this->A[this->rear] = x;
        this->capacity++;
    }
    return *this;
}

// Queue &Queue::dequeue()
// {
//     if (isEmpty())
//         cout << "Queue Empty";
//     else
//     {
//         if (this->capacity == 1)
//         {
//             delete_(this->A);
//             allocate(this->A, this->size);
//             this->front = this->rear = -1;
//             this->capacity = 0;
//         }
//         else
//         {
//             int *a = new int[this->size];
//             for (int i = 0; i < this->capacity - 1; i++)
//             {
//                 a[i] = this->A[i + 1];
//             }
//             delete_(this->A);
//             this->capacity--;
//             allocate(this->A, this->size);
//             for (int i = 0; i < this->capacity; i++)
//             {
//                 this->A[i] = a[i];
//             }
//             this->rear--;
//         }
//         return *this;
//     }
// }

// Queue &Queue::dequeue()
// {
//     if (isEmpty())
//     {
//         cout << "Queue Empty";
//     }
//     else
//     {
//         for (int i = this->front; i < this->capacity; i++)
//         {
//             this->A[i] = this->A[i + 1];
//         }
//         this->capacity--;
//         this->rear--;
//     }
//     return *this;
// }

Queue &Queue::dequeue()
{
    if (isEmpty())
        cout << "Queue Empty";
    else
    {
        this->front++;
        this->capacity--;
        if (this->capacity == 0)
        {
            this->front = this->rear = -1;
        }
    }
    return *this;
}

void Queue::display()
{
    if (isEmpty())
        cout << "Queue Empty";
    else
    {
        for (int i = this->front; i <= this->rear; i++)
        {
            if (i == this->rear)
            {
                cout << this->A[i];
            }
            else
                cout << this->A[i] << " <--- ";
        }
    }
}

int Queue::getCapacity()
{
    return this->capacity;
}

int Queue::getFront()
{
    return this->A[this->front];
}

bool Queue::exists(int x)
{
    for (int i = this->front; i <= this->rear; i++)
    {
        if (this->A[i] == x)
            return 1;
    }
    return 0;
}
