#include <iostream>

using namespace std;

struct node
{
    int info;
    node *next;
};

struct queue
{
    node *front, *rear;
};

void display(queue *q);
void enqueue(queue *q, int x);
void dequeue(queue *q);

int main()
{
    queue *q = new queue;
    q->front = q->rear = NULL;
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        enqueue(q, x);
    }
    display(q);
    dequeue(q);
    dequeue(q);
    cout << endl;
    display(q);

    return 0;
}

void enqueue(queue *q, int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;

    if (q->front == NULL)
    {
        q->front = q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
        q->rear->next = q->front;
    }
}

void dequeue(queue *q)
{
    if (q->front == NULL)
    {
        cout << "Queue Empty";
        return;
    }
    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
        q->rear->next = q->front;
    }
}

void display(queue *q)
{
    if (q->front == NULL)
    {
        cout << "Queue Empty";
        return;
    }

    node *p = q->front;
    while (p->next != q->front)
    {
        cout << p->info << " <--- ";
        p = p->next;
    }
    cout << p->info;
}