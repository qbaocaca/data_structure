#include <iostream>

using namespace std;

struct node
{
    int info;
    node *prev;
    node *next;
};
void display(node *list);
void add_head(node **list, int x);
void add_tail(node **list, int x);
void insertAfter(node **list, node *q, int x);
void delete_(node **list, int x);

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
    display(LIST);

    cout << endl;
    cin >> x;
    // int a;
    // cin >> a;
    // node *temp = LIST;
    // while (temp->next != LIST)
    // {
    //     if (temp->info == a)
    //         break;
    //     temp = temp->next;
    // }
    // if (temp == LIST->prev)
    // {
    //     if (temp->info == a)
    //     {
    //         insertAfter(&LIST, temp, x);
    //     }
    // }
    // else
    //     insertAfter(&LIST, temp, x);

    delete_(&LIST, x);
    display(LIST);
    return 0;
}

void add_head(node **list, int x)
{
    node *p = new node;
    p->info = x;
    p->prev = p->next = NULL;

    if (*list == NULL)
    {
        p->next = p->prev = p;
        *list = p;
    }
    else
    {
        p->next = *list;
        node *last = (*list)->prev;
        p->prev = last;
        last->next = (*list)->prev = p;
        *list = p;
    }
}

void display(node *list)
{
    node *temp = list;
    cout << "Print forward: ";
    while (temp->next != list)
    {
        cout << temp->info << "->";
        temp = temp->next;
    }
    cout << temp->info << endl;

    cout << "Print backward: ";
    while (temp != list)
    {
        cout << temp->info << "<-";
        temp = temp->prev;
    }
    cout << temp->info;
}

void add_tail(node **list, int x)
{
    node *p = new node;
    p->info = x;
    p->prev = p->next = NULL;

    if (*list == NULL)
    {
        p->next = p->prev = p;
        *list = p;
    }
    else
    {
        node *last = (*list)->prev;
        last->next = (*list)->prev = p;
        p->prev = last;
        p->next = *list;
    }
}

void insertAfter(node **list, node *q, int x)
{
    node *p = new node;
    p->info = x;
    p->prev = p->next = NULL;

    if (q == (*list)->prev)
    {
        p->next = *list;
        p->prev = (*list)->prev;
        (*list)->prev->next = p;
        (*list)->prev = p;
    }
    else if (q == *list)
    {
        p->next = (*list)->next;
        p->prev = (*list);
        (*list)->next->prev = p;
        (*list)->next = p;
    }
    else
    {

        node *temp = *list;
        while (temp->next != *list)
        {
            if (temp == q)
                break;
            temp = temp->next;
        }

        p->next = temp->next;
        p->prev = temp;
        temp->next->prev = p;
        temp->next = p;
    }
}

void delete_(node **list, int x)
{
    node *temp = *list;
    while (temp->next != *list)
    {
        if (temp->info == x)
            break;
        temp = temp->next;
    }
    if (temp == *list)
    {
        if (temp->info == x)
        {
            (*list)->next->prev = temp->prev;
            (*list)->prev->next = temp->next;
            *list = (*list)->next;
        }
    }
    else if (temp == (*list)->prev)
    {
        if (temp->info == x)
        {
            (*list)->prev = temp->prev;
            temp->prev->next = *list;
        }
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete[] temp;
}
