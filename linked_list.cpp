#include <iostream>

using namespace std;

struct node
{
    int info;
    node *next;
};

void add_head(node **list, int x);
void printlist(node *list);
void swap(int *a, int *b);
void bubblesort(node **list);
void add_tail(node **list, int x);
void insertAfter(node **list, node *p, int x);
void delete_(node **list, int x);
void deletefirst(node **list);
void deletelast(node **list);
void reverse(node **list);
void printalternate(node *list);
node *removeAfter(node **list, node *p);
void addAfter(node **list, node *e, node *q);
void insertionsort(node **list);
void mergersort(node **list);
void merge(node **l1, node **l2, node **list);
void partition(node **list, node **l1, node **l2);

int main()
{
    node *LIST = NULL;
    int x;
    while (true)
    {
        cin >> x;
        if (x == 0)
            break;
        // add_head(&LIST, x);
        add_tail(&LIST, x);
    }
    printlist(LIST);

    // insertAfter
    // cin >> x;
    // node *temp = LIST;
    // int a;
    // cin >> a;
    // while (temp != NULL)
    // {
    //     if (temp->info == a)
    //         break;
    //     temp = temp->next;
    // }
    // insertAfter(&LIST, temp, x);
    // printlist(LIST);

    // bubblesort(&LIST);
    // cout << endl;
    // printlist(LIST);

    // cin >> x;
    // delete_(&LIST, x);
    // printlist(LIST);

    // deletefirst(&LIST);
    // cout << endl;
    // printlist(LIST);
    // deletelast(&LIST);
    // cout << endl;
    // printlist(LIST);

    cout << endl;
    // reverse(&LIST);
    // printlist(LIST);
    // printalternate(LIST);
    // insertionsort(&LIST);
    mergersort(&LIST);
    printlist(LIST);

    // cin >> x;
    // node *temp = LIST;
    // while (temp != NULL)
    // {
    //     if (temp->info == x)
    //         break;
    //     temp = temp->next;
    // }

    // node *e = new node;
    // cin >> x;
    // e->info = x;
    // e->next = NULL;

    // node *e = removeAfter(&LIST, temp);
    // addAfter(&LIST, e, temp);
    // printlist(LIST);

    // node *l1, *l2;
    // partition(&LIST, &l1, &l2);
    // printlist(l1);
    // cout << endl;
    // printlist(l2);
    // printlist(LIST);
    // node *l3, *l4, *l5, *l6;
    // partition(&l1, &l3, &l4);
    // merge(&l3, &l4, &l1);
    // partition(&l2, &l5, &l6);
    // merge(&l5, &l6, &l2);
    // merge(&l1, &l2, &LIST);
    // printlist(LIST);
    return 0;
}

// with pointer, you dont know whether a single value is assigned
// or an array is assigned
// node*p = new node;
// assign to a single node data type dynamically
// node**list
// can be explained as an array of dynamically allocated nodes.

// with operation like add, insert, and delete
// the structure of the list might be altered
// therefore, it needs to be of referenced type.

void add_head(node **list, int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;

    if (*list == NULL)
    {
        *list = p;
    }
    else
    {
        p->next = *list;
        *list = p;
    }
}

void printlist(node *list)
{
    while (list != NULL)
    {
        if (list->next == NULL)
            cout << list->info;
        else
            cout << list->info << " ";
        list = list->next;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(node **list)
{
    node *ptr1;
    node *lptr = NULL;
    bool flag;
    do
    {
        flag = 0;
        ptr1 = *list;

        while (ptr1->next != lptr)
        {
            if (ptr1->info > ptr1->next->info)
            {
                swap(&ptr1->next->info, &ptr1->info);
                flag = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (flag);
}

// ptr1 keeps the head of the list every time
// the loop turns back to the beginning of the list
// ptr1 gradually moves to the end of the list
// lptr keeps track of the tail of the list
// after every loop, ptr1 handles the tail of the list
// to lptr1, which limits the unsorted list
// like in 1d array.
// the flag variable prevents any loop that there is
// no swap happening.

void add_tail(node **list, int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;

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
    }
}

void insertAfter(node **list, node *p, int x)
{
    node *q = new node;
    q->info = x;
    q->next = NULL;

    if (p == NULL)
        return;
    node *temp = *list;
    while (temp != NULL)
    {
        if (temp == p)
        {
            break;
        }
        temp = temp->next;
    }
    q->next = temp->next;
    temp->next = q;
}

void delete_(node **list, int x)
{
    node *temp = *list;
    node *btemp = NULL;
    while (temp != NULL)
    {
        if (temp->info == x)
            break;
        btemp = temp;
        temp = temp->next;
    }

    if (btemp == NULL)
    {
        *list = temp->next;
    }
    else
        btemp->next = temp->next;

    delete[] temp;
}

void deletefirst(node **list)
{
    node *temp = *list;
    *list = temp->next;
    delete[] temp;
}

void deletelast(node **list)
{
    node *temp = *list;
    node *btemp = NULL;
    while (temp->next != NULL)
    {
        btemp = temp;
        temp = temp->next;
    }
    btemp->next = temp->next;
    delete[] temp;
}

void reverse(node **list)
{
    node *prev = NULL;
    node *next = NULL;
    node *curr = *list;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *list = prev;
}

void printalternate(node *list)
{
    if (list == NULL)
        return;
    cout << list->info << " ";

    if (list->next != NULL)
    {
        printalternate(list->next->next);
    }
}

node *removeAfter(node **list, node *p)
{
    if (p->next == NULL)
        return NULL;
    node *temp = *list;
    while (temp->next != NULL)
    {
        if (temp == p)
            break;
        temp = temp->next;
    }
    node *e;
    e = temp->next;
    temp->next = temp->next->next;
    e->next = NULL;
    return e;
}

void addAfter(node **list, node *e, node *q)
{
    if (q == NULL)
    {
        e->next = *list;
        *list = e;
    }
    else
    {
        node *temp = *list;
        while (temp != NULL)
        {
            if (temp == q)
                break;
            temp = temp->next;
        }
        e->next = temp->next;
        temp->next = e;
    }
}

void insertionsort(node **list)
{
    node *i = *list, *k, *e, *q;
    while (i->next != NULL)
    {
        q = NULL;
        k = *list;
        e = removeAfter(list, i);

        while (k != i->next)
        {
            if (k->info >= e->info)
                break;
            q = k;
            k = q->next;
        }
        addAfter(list, e, q);
        if (i->next == e)
            i = i->next;
    }
}

void mergersort(node **list)
{
    if (*list == NULL)
        return;
    node *l1, *l2;
    partition(list, &l1, &l2);
    mergersort(&l1); // didn't work when having this :(
    mergersort(&l2);
    merge(&l1, &l2, list);
}

void partition(node **list, node **l1, node **l2)
{
    *l1 = NULL;
    *l2 = NULL;
    int lane = 0;
    while (*list != NULL)
    {
        node *p = *list;
        *list = p->next;
        p->next = NULL;
        if (lane)
            add_tail(l2, p->info);
        else
            add_tail(l1, p->info);
        lane = !lane;
    }
}

void merge(node **l1, node **l2, node **list)
{
    node *p;
    while (*l1 && *l2)
    {
        if ((*l1)->info < (*l2)->info)
        {
            p = *l1;
            *l1 = (*l1)->next;
        }
        else
        {
            p = *l2;
            *l2 = (*l2)->next;
        }
        p->next = NULL;
        add_tail(list, p->info);
    }

    while (*l1)
    {
        p = *l1;
        *l1 = (*l1)->next;
        p->next = NULL;
        add_tail(list, p->info);
    }

    while (*l2)
    {
        p = *l2;
        *l2 = (*l2)->next;
        p->next = NULL;
        add_tail(list, p->info);
    }
}
