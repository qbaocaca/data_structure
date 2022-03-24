#include <iostream>

using namespace std;
struct node
{
    int info;
    node *next;
};
void add_head(node **list, int x);
void add_tail(node **list, int x);
void display(node *list);
void insertAfter(node **list, node *q, int x);
void deletenode(node **list, int x);

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
    int a;
    cin >> a;

    node *temp = LIST;
    while (temp->next != LIST) // working with circular list
    {                          // please don't ever use
        if (temp->info == a)   // node*temp = LIST
            break;             // while(temp != LIST) WRONG!
        temp = temp->next;
    }

    insertAfter(&LIST, temp, x);
    // deletenode(&LIST, x);
    cout << endl;
    display(LIST);

    return 0;
}

void add_head(node **list, int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;

    if (*list == NULL)
    {
        p->next = p; // the first node points to itself.
    }
    else
    {
        node *temp = *list;
        while (temp->next != *list)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = *list;
    }
    *list = p; // the newnode is always the head.
}

void add_tail(node **list, int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;

    if (*list == NULL) // if used if-else, have to be *list!
    {                  // because the else needs *this!
        p->next = p;
        *list = p; // the first node points to itself.
    }              // itself is the head.
    else           // otherwise, append to node before head
    {
        node *temp = *list;
        while (temp->next != *list)
        {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }
}

void display(node *list)
{
    node *temp = list;
    if (list != NULL)
    {
        do
        {
            if (temp->next == list)
                cout << temp->info;
            else
                cout << temp->info << "->";
            temp = temp->next;
        } while (temp != list);
    }
}

void insertAfter(node **list, node *q, int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;

    node *temp = *list;
    while (temp->next != *list)
    {
        if (temp == q)
            break;
        temp = temp->next;
    }

    p->next = temp->next;
    temp->next = p;
}

void deletenode(node **list, int x)
{
    node *temp = *list;
    node *btemp;
    while (temp->next != *list)
    {
        if (temp->info == x)
            break;
        btemp = temp;
        temp = temp->next;
    }
    if (temp == *list)
    {
        while (temp->next != *list)
        {
            temp = temp->next;
        }
        temp->next = (*list)->next;
        *list = (*list)->next;
    }
    else
    {
        btemp->next = temp->next;
        delete[] temp;
    }
}