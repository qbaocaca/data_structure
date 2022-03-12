#ifndef queue_h
#define queue_h

void allocate(int *&a, int size)
{
    a = new int[size];
}

void delete_(int *a)
{
    delete[] a;
}

class Queue
{
private:
    int capacity, front, rear, size;
    int *A;

public:
    Queue(int);
    bool isFull();
    bool isEmpty();
    // Queue &enqueue(int);
    Queue &enqueue(int);
    // Queue &dequeue();
    // Queue &dequeue();
    Queue &dequeue();
    void display();
    int getCapacity();
    int getFront();
    bool exists(int);
};

#endif