#include <iostream>

using namespace std;

struct node
{
    int info;
    node *prev;
    node *next;
};

void add_head(node **list, int x);
void add_tail(node **list, int x);
void insertAfter(node **list, node *q, int x);
void display(node *list);
void printForward(node *list);
void printBackward(node *list);
void deleteHead(node **list);
void deleteTail(node **list);
void deletenode(node **list, node *q);
void swap(int *a, int *b);
void sort(node **list);

int main()
{
    node *LIST = NULL;
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        // add_head(&LIST, x);
        add_tail(&LIST, x);
    }
    // display(LIST);
    printForward(LIST);
    cout << endl;
    printBackward(LIST);
    cout << endl;

    // cin >> x;
    // int a;
    // cin >> a;
    // node *temp = LIST;
    // while (temp != NULL)
    // {
    //     if (temp->info == a)
    //         break;
    //     temp = temp->next;
    // }
    // insertAfter(&LIST, temp, x);

    sort(&LIST);
    // deletenode(&LIST, temp);
    // deleteHead(&LIST);
    // deleteTail(&LIST);
    printForward(LIST);
    cout << endl;
    printBackward(LIST);
    // display(LIST);

    return 0;
}

void add_head(node **list, int x)
{
    node *p = new node;
    p->info = x;
    p->prev = p->next = NULL;

    if (*list == NULL)
    {
        *list = p;
    }
    else
    {
        p->next = *list;
        (*list)->prev = p;
        *list = p;
    }
}

void add_tail(node **list, int x)
{
    node *p = new node;
    p->info = x;
    p->prev = p->next = NULL;

    if (*list == NULL)
    {
        *list = p;
    }
    else
    {
        node *temp = *list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}

void insertAfter(node **list, node *q, int x)
{
    node *temp = *list;
    while (temp != NULL)
    {
        if (temp == q)
            break;
        temp = temp->next;
    }

    node *p = new node;
    p->info = x;
    p->prev = temp;
    p->next = temp->next;
    temp->next = p;
    p->next->prev = p; // without this, printBackward
                       // doesn't have a new element!
}

void display(node *list)
{
    node *last;
    cout << "Print forward: ";
    while (list != NULL)
    {
        if (list->next == NULL)
            cout << list->info;
        else
            cout << list->info << "->";
        last = list;
        list = list->next;
    }

    cout << endl;
    cout << "Print backward: ";
    while (last != NULL)
    {
        if (last->prev == NULL)
            cout << last->info;
        else
            cout << last->info << "<-";
        last = last->prev;
    }
}

void printForward(node *list)
{
    while (list != NULL)
    {
        if (list->next == NULL)
            cout << list->info;
        else
            cout << list->info << "->";
        list = list->next;
    }
}

void printBackward(node *list)
{
    while (list->next != NULL)
    {
        list = list->next;
    }

    while (list != NULL)
    {
        if (list->prev == NULL)
            cout << list->info;
        else
            cout << list->info << "<-";
        list = list->prev;
    }
}

void deleteHead(node **list)
{
    *list = (*list)->next;
    (*list)->prev = NULL;
}

void deleteTail(node **list)
{
    node *temp = *list;
    node *btemp = NULL;
    while (temp->next != NULL)
    {
        btemp = temp;
        temp = temp->next;
    }
    btemp->next = NULL;
    delete[] temp;
}

void deletenode(node **list, node *q)
{
    if (q == *list)
    {
        deleteHead(list);
    }
    else
    {
        node *temp = *list;
        node *btemp = NULL;
        while (temp != NULL)
        {
            if (temp == q)
                break;
            btemp = temp;
            temp = temp->next;
        }
        if (btemp->next->next == NULL)
        {
            btemp->next = NULL;
        }
        else
        {
            btemp->next = temp->next;
            temp->next->prev = btemp;
        }
        delete[] temp;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
};

void sort(node **list)
{
    node *p = *list;
    while (p->next->next != NULL)
    {
        node *q = p->next;
        node *min = p;
        while (q->next != NULL)
        {
            if (q->info < p->info)
                min = q;
            q = q->next;
        }
        if (min != p)
            swap(&p->info, &min->info);
        p = p->next;
    }
}
