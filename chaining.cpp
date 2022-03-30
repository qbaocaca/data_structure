#include <iostream>

using namespace std;
struct node
{
    int info;
    node *prev;
    node *next;
};
void add_tail(node **list, int x);
void printForward(node *list);
void printBackward(node *list);
bool search_list(node *list, int x);
bool search(node **list, int x);
void insert(node **list, int x);
void delete_(node **list, int x);
void deletekey(node **list, int x);
void display(node **list, int n);

int main()
{

    // int *arr, n;
    // cin >> n;
    // arr = new int[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    node *LIST = NULL;
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        add_tail(&LIST, x);
    }
    printForward(LIST);
    cout << endl;
    printBackward(LIST);

    cin >> x;
    delete_(&LIST, x);
    printForward(LIST);
    cout << endl;
    printBackward(LIST);

    // int m;
    // cin >> m;
    // node **list = new node *[m];
    // for (int i = 0; i < m; i++)
    // {
    //     list[i] = NULL;
    // }
    // int x;
    // for (int i = 0; i < m; i++)
    // {
    //     while (1)
    //     {
    //         cin >> x;
    //         if (x == 0)
    //             break;
    //         add_tail(&list[i], x);
    //     }
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     printForward(list[i]);
    //     cout << endl;
    // }

    // node **list = new node *[n];
    // for (int i = 0; i < n; i++)
    // {
    //     list[i] = NULL;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     int index = arr[i] % 7;
    //     add_tail(&list[index], arr[i]);
    // }
    // cout << endl;
    // display(list, n);

    // cout << endl;
    // int x;
    // // cin >> x;
    // // cout << search(list, x);

    // while (1)
    // {
    //     cin >> x;
    //     if (x == 0)
    //         break;
    //     insert(list, x);
    // }
    // cout << endl;
    // display(list, n);

    // cout << endl;
    // while (1)
    // {
    //     cin >> x;
    //     if (x == 0)
    //         break;
    //     deletekey(list, x);
    // }
    // cout << endl;
    // display(list, n);
    // delete[] arr;
    // delete[] list;

    return 0;
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

void printForward(node *list)
{
    node *temp = list;
    while (temp->next != NULL)
    {
        cout << temp->info << "->";
        temp = temp->next;
    }
    cout << temp->info;
}

void printBackward(node *list)
{
    node *temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp->prev != NULL)
    {
        cout << temp->info << "<-";
        temp = temp->prev;
    }
    cout << temp->info;
}

void insert(node **list, int x)
{
    add_tail(&list[x % 7], x);
}

bool search_list(node *list, int x)
{
    while (list != NULL)
    {
        if (list->info == x)
            return 1;
        list = list->next;
    }
    return 0;
}

bool search(node **list, int x)
{
    if (search_list(list[x % 7], x))
        return 1;
    return 0;
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
    if (temp == *list)
    {
        if (temp->info == x)
        {
            *list = temp->next;
            (*list)->prev = NULL;
        }
    }
    else
    {
        btemp->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = btemp;
        }
    }
    delete[] temp;
}

void deletekey(node **list, int x)
{
    if (search(&list[x % 7], x))
        delete_(&list[x % 7], x);
}

void display(node **list, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i] != NULL)
        {
            cout << "key=" << i << ": ";
            printForward(list[i]);
            cout << endl;
        }
        else
            cout << "key=" << i << endl;
    }
}