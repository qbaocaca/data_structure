#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

int insert(node *&a, int x);
void inorder(node *a);
bool isFuLLBT(node *t);
void cal_height(node *t, int i, int &h);
bool isPerfectBT(node *t);
int count_node_at_level(node *t, int i, int m);
void checklastlevel(node *t, int i, int m, int *a, int &na);
bool isComplete(node *t);
int power(int a, int b);
void display(node *t);

int main()
{
    node *a = new node;
    a = NULL;
    int x;
    while (true)
    {
        cin >> x;
        if (x == 0)
            break;
        insert(a, x);
    }
    // cout << "inorder: ";
    // inorder(a);
    cout << endl;
    display(a);
    // cout << endl
    //      << isFuLLBT(a);

    // cout << endl
    //      << isPerfectBT(a);

    // int m;
    // cin >> m;
    // cout << count_node_at_level(a, 0, m);

    // int h = 0;
    // cal_height(a, 0, h);
    // int second2last = count_node_at_level(a, 0, h - 1);
    // int *arr = new int[second2last];
    // int na = 0;
    // checklastlevel(a, 0, h - 1, arr, na);
    // cout << endl;
    // for (int i = 0; i < na; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl
    //      << "na=" << na;

    // cout << endl
    //      << isComplete(a);

    // cout << power(2, 3);
    return 0;
}

// binary tree allows duplicate values.
// binary search tree doesn't!

int insert(node *&a, int x)
{
    if (a != NULL)
    {
        // if (a->data == x)
        //     return 0;
        if (a->data > x)
            return insert(a->left, x);
        if (a->data <= x)
            return insert(a->right, x);
    }
    a = new node;
    a->data = x;
    a->left = a->right = NULL;
    return 1;
}

void inorder(node *a)
{
    if (a != NULL)
    {
        inorder(a->left);
        cout << a->data << " ";
        inorder(a->right);
    }
}

bool isFuLLBT(node *t)
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
            return 1;
        else if (t->left != NULL && t->right != NULL)
            return isFuLLBT(t->left) && isFuLLBT(t->right);
    }
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

bool isPerfectBT(node *t)
{
    if (t != NULL)
    {
        int h = 0;
        if (t->left == NULL || t->right == NULL)
        {
            cal_height(t, 0, h);
            if (h != 0)
                return 0;
            return 1;
        }
        else
        {
            cal_height(t, 0, h);
            int h_left = 0, h_right = 0;
            cal_height(t->left, 0, h_left);
            cal_height(t->right, 0, h_right);
            if (h_left == h - 1 && h_right == h - 1)
            {
                if (isPerfectBT(t->left) && isPerfectBT(t->right))
                    return 1;
            }
        }
    }
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

bool isComplete(node *t)
{
    if (t != NULL)
    {
        int h = 0;
        cal_height(t, 0, h);
        int numnodes = 0;
        for (int i = 0; i < h; i++)
        {
            int numnodesdefault = power(2, i);
            numnodes = count_node_at_level(t, 0, i);
            if (numnodes != numnodesdefault)
                return 0;
        }

        int *arr = new int[numnodes];
        int na = 0;
        checklastlevel(t, 0, h - 1, arr, na);

        if (arr[0] == 2)
        {
            for (int i = 1; i < na; i++)
            {
                if (arr[i] == -1)
                    return 0;
                if (arr[i] == 1)
                {
                    for (int j = i + 1; j < na; j++)
                    {
                        if (arr[j] == 1 || arr[j] == 2)
                            return 0;
                    }
                }
            }
        }
        else if (arr[0] == 1 || arr[0] == 0)
        {
            for (int i = 1; i < na; i++)
            {
                if (arr[i] != 0)
                    return 0;
            }
        }
        return 1;
    }
}

int count_node_at_level(node *t, int i, int m)
{
    if (t != NULL)
    {
        if (i == m)
            return 1;
        return count_node_at_level(t->left, i + 1, m) +
               count_node_at_level(t->right, i + 1, m);
    }
    else
        return 0;
}

bool degree1(node *t)
{

    return (t->left == NULL && t->right != NULL) ||
           (t->left != NULL && t->right == NULL);
}

bool degree2(node *t)
{
    return t->left != NULL && t->right != NULL;
}

bool degree0(node *t)
{
    return t->left == NULL && t->right == NULL;
}

int checkdegree(node *t)
{
    if (t != NULL)
    {
        if (degree0(t))
            return 0;
        else if (degree1(t))
            return 1;
        else
            return 2;
    }
}

void checklastlevel(node *t, int i, int m, int *a, int &na)
{
    if (t != NULL)
    {
        if (i == m)
        {
            int degree = checkdegree(t);
            if (degree == 1 && t->left == NULL)
            {
                a[na++] = -1;
            }
            else
                a[na++] = degree;
        }
        checklastlevel(t->left, i + 1, m, a, na);
        checklastlevel(t->right, i + 1, m, a, na);
    }
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
