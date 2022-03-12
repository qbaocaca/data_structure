#include <iostream>
#define MAX 100
using namespace std;

struct queue
{
    int front, rear, capacity;
    int A[MAX];
};

bool checkEmpty(queue *);
bool checkFull(queue *);

void enqueue(queue *, int);
void dequeue(queue *);
void display(queue *);
int peek(queue *);
void initialize(queue *);

int main()
{
    queue *a = new queue[MAX];
    initialize(a);
    int x;
    while (true)
    {
        cin >> x;
        if (x == 0)
            break;
        enqueue(a, x);
    }
    display(a);
    while (!checkEmpty(a))
    {
        dequeue(a);
        cout << endl;
        display(a);
    }

    return 0;
}

void initialize(queue *a)
{
    a->front = a->rear = -1;
    a->capacity = 0;
}

bool checkEmpty(queue *a)
{
    return a->front == -1;
}

bool checkFull(queue *a)
{
    return a->front == 0 && a->rear == MAX - 1;
}

void enqueue(queue *a, int x)
{
    if (checkFull(a))
        cout << "Full Queue";
    else
    {
        if (a->front == -1)
            a->front = 0;
        a->rear++;
        a->A[a->rear] = x;
        a->capacity = a->rear + 1;
    }
}

void dequeue(queue *a)
{
    if (checkEmpty(a))
        cout << "Queue Empty";
    else
    {
        for (int i = 0; i < a->capacity; i++)
        {
            a->A[i] = a->A[i + 1];
        }
        a->rear--;
        if (a->capacity == 1)
            a->front = -1;
        a->capacity--;
    }
}

void display(queue *a)
{
    if (checkEmpty(a))
        cout << "Queue Empty";
    else
    {
        for (int i = a->front; i < a->capacity; i++)
        {
            if (i == a->rear)
                cout << a->A[i];
            else
                cout << a->A[i] << " <--- ";
        }
    }
}

int peek(queue *a)
{
    if (checkEmpty(a))
        cout << "Queue Empty";
    else
    {
        cout << a->A[a->front];
    }
}
