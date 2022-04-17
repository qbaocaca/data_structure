#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
void cal_height(node *t, int i, int &h);
int insert(node *&t, int x);
void lnr(node *t);
bool isbalance(node *t);
int countnode(node *t);
node *buildBalancedTree(node *t);
void storeInArray(node *t, int *a, int &i);
node *buildTreeUtil(int *a, int start, int end);
int power(int a, int b);
void get_node_at_level(node *t, int i, int m, int *a, int &na);
void display(node *t);

int main()
{
    // node *t = new node;
    // t = NULL;
    // int x;
    // while (1)
    // {
    //     cin >> x;
    //     if (x == 0)
    //         break;
    //     insert(t, x);
    // }
    // lnr(t);
    // cout << endl;
    // cout << "num nodes=" << countnode(t);
    // int h = 0;
    // cal_height(t, 0, h);
    // cout << "h=" << h;
    // cout << "isbalance: ";
    // if (isbalance(t))
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;
    // display(t);
    // cout << endl;
    // node *t1 = new node;
    // t1 = NULL;
    // t1 = buildBalancedTree(t);
    // cout << endl;
    // lnr(t1);
    // cout << endl;
    // cout << "isbalance: ";
    // if (isbalance(t1))
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;
    // display(t1);

    // int size = countnode(t);
    // int *a = new int[size];
    // int n = 0;
    // storeInArray(t, a, n);
    // cout << "n=" << n << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == n - 1)
    //         cout << a[i];
    //     else
    //         cout << a[i] << " ";
    // }

    node *t = new node;
    t = NULL;
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        insert(t, x);
        if (!isbalance(t))
        {
            cout << "tree unbalanced when insert node " << x;
            cout << ", make balance!" << endl;
            node *temp = new node;
            temp = NULL;
            temp = buildBalancedTree(t);
            t = NULL;
            t = temp;
        }
    }
    if (isbalance(t))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

void cal_height(node *t, int i, int &h)
{
    if (t != NULL)
    {
        cal_height(t->left, i + 1, h);
        if (i > h)
            h = i;
        cal_height(t->right, i + 1, h);
    }
}

int insert(node *&t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
            return 0;
        if (t->data < x)
            return insert(t->right, x);
        else
            return insert(t->left, x);
    }
    t = new node;
    t->data = x;
    t->left = t->right = NULL;
    return 1;
}

void lnr(node *t)
{
    if (t != NULL)
    {
        lnr(t->left);
        cout << t->data << " ";
        lnr(t->right);
    }
}

bool isbalance(node *t)
{
    if (t)
    {
        int h1 = 0, h2 = 0;
        cal_height(t->left, 0, h1);
        cal_height(t->right, 0, h2);

        if (abs(h1 - h2) <= 1 && isbalance(t->left) && isbalance(t->right))
            return 1;
        return 0;
    }
    return 1;
}

node *buildTreeUtil(int *a, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node *t = new node;
    t->data = a[mid];
    t->left = buildTreeUtil(a, start, mid - 1);
    t->right = buildTreeUtil(a, mid + 1, end);
    return t;
}

int countnode(node *t)
{
    if (t)
    {
        return 1 + countnode(t->left) + countnode(t->right);
    }
    return 0;
}

void storeInArray(node *t, int *a, int &i)
{
    if (t != NULL)
    {
        storeInArray(t->left, a, i);
        a[i++] = t->data;
        storeInArray(t->right, a, i);
    }
}

node *buildBalancedTree(node *t)
{
    int size = countnode(t);
    int *a = new int[size];
    int n = 0;
    storeInArray(t, a, n);
    return buildTreeUtil(a, 0, n - 1);
}

int power(int a, int b)
{
    int i = 0;
    int t = 1;
    while (i < b)
    {
        t = t * a;
        i++;
    }
    return t;
}

void get_node_at_level(node *t, int i, int m, int *a, int &na)
{
    if (t != NULL)
    {
        if (i == m)
        {
            a[na++] = t->data;
        }
        get_node_at_level(t->left, i + 1, m, a, na);
        get_node_at_level(t->right, i + 1, m, a, na);
    }
}

void display(node *t)
{
    int h = 0;
    cal_height(t, 0, h);
    int numlastlevel = power(2, h);
    int num_cols = 2 * numlastlevel - 1;
    int **matrix = new int *[(h + 1) * num_cols];
    for (int i = 0; i < h + 1; i++)
    {
        matrix[i] = new int[num_cols];
    }
    for (int i = 0; i < h + 1; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
    int *a = new int[num_cols];
    int na = 0;
    get_node_at_level(t, 0, 0, a, na);
    int first_index = num_cols / 2;
    matrix[0][first_index] = a[0];
    delete[] a;
    int index = first_index / 2;
    int index_ = index + first_index + 1;
    for (int i = 1; i <= h; i++)
    {
        a = new int[num_cols];
        na = 0;
        get_node_at_level(t, 0, i, a, na);
        for (int j = 0; j < na; j++)
        {
            if (j == 0)
            {
                matrix[i][index] = a[j];
            }
            else if (index_ <= num_cols)
            {
                matrix[i][index_] = a[j];
                index_ = index_ + first_index + 1;
            }
        }
        delete[] a;
        index = index / 2;
        first_index = first_index / 2;
        index_ = index + first_index + 1;
    }

    for (int i = 0; i < h + 1; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}