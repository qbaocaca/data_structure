#include <iostream>

using namespace std;
int num_vertices;
bool *visited = new bool[num_vertices];

struct node
{
    int info;
    node *next;
};

node **adj = new node *[num_vertices];

void add_tail(node **list, int x);
void printlist(node *list);
void dfs(int x);

int main()
{
    int num_edges;
    cin >> num_vertices;
    cin >> num_edges;

    for (int i = 0; i < num_vertices; i++)
    {
        visited[i] = 0;
    }

    // for (int i = 0; i < num_vertices; i++)
    // {
    //     cout << visited[i] << " ";
    // }

    for (int i = 0; i < num_vertices; i++)
    {
        adj[i] = NULL;
    }
    int x, y;
    for (int i = 0; i < num_edges; i++)
    {
        cin >> x >> y;
        add_tail(&adj[x], y);
        add_tail(&adj[y], x);
    }

    // for (int i = 0; i < num_vertices; i++)
    // {
    //     printlist(adj[i]);
    //     cout << endl;
    // }

    for (int i = 1; i <= num_vertices; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }

    // node *list = NULL;
    // int x;
    // while (1)
    // {
    //     cin >> x;
    //     if (x == 0)
    //         break;
    //     add_tail(&list, x);
    // }
    // printlist(list);

    return 0;
}

void add_tail(node **list, int x)
{
    node *pnew = new node;
    pnew->info = x;
    pnew->next = NULL;

    if (*list == NULL)
    {
        *list = pnew;
    }
    else
    {
        node *temp = *list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pnew;
    }
}

void printlist(node *list)
{
    node *temp = list;
    while (temp->next != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << temp->info;
}

void dfs(int x)
{
    visited[x] = 1;
    cout << x << " ";
    node *temp = adj[x];
    while (temp != NULL)
    {
        if (visited[temp->info] == 0)
            dfs(temp->info);
        temp = temp->next;
    }
}