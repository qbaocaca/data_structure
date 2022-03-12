#ifndef circular_h
#define circular_h

void allocate(int *&a, int size)
{
    a = new int[size];
}

void delete_(int *a)
{
    delete[] a;
}

class cirqueue
{
private:
    int front, rear, size;
    int *A;

public:
    cirqueue(int);
    bool isEmpty();
    bool isFull();
    cirqueue &enqueue(int);
    cirqueue &dequeue();
    void display();
};
#endif