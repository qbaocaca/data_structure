#include <iostream>
#define MAX 100
using namespace std;

struct stack
{
    int items[MAX];
    int top;
};
typedef struct stack st;
int size = 0;

void initialize(st *);
int isFull(st *);
int isEmpty(st *);
void pop(st *);
void push(st *, int);
void printStack(st *);

int main()
{
    st *a = new st[MAX];
    initialize(a);
    int x;
    while (true)
    {
        cin >> x;
        if (x == 0)
        {
            break;
        }
        push(a, x);
    }
    printStack(a);
    pop(a);
    cout << endl;
    printStack(a);

    return 0;
}

void initialize(st *s)
{
    s->top = -1;
}

int isFull(st *s)
{
    if (s->top == MAX - 1)
        return 1;
    return 0;
}

int isEmpty(st *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

void pop(st *s)
{
    if (isEmpty(s))
        cout << "Stack Empty";
    else
    {
        cout << s->items[s->top];
        s->top--;
    }
    --size;
}

void push(st *s, int x)
{
    if (isFull(s))
        cout << "Stack Full";
    else
    {
        s->top++;
        s->items[s->top] = x;
    }
    ++size;
}

void printStack(st *s)
{
    for (int i = 0; i < size; i++)
    {
        cout << s->items[i] << " ";
    }
}
