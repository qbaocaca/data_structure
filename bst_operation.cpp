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
void cal_height(node *t, int i, int &h);
int cal_height2(node *t);
bool degree2(node *);
bool degree1(node *);
bool degree0(node *);
int checkdegree(node *t, int x);

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
    cout << "inorder: ";
    inorder(a);
    // int i = 0, h = 0;
    // cout << endl
    //  << "height tree=";
    // cal_height(a, i, h);
    // cout << h;
    // cout << cal_height2(a);

    int m;
    cin >> m;
    cout << checkdegree(a, m);

    return 0;
}

int insert(node *&a, int x)
{
    if (a != NULL)
    {
        if (a->data == x)
            return 0;
        if (a->data > x)
            return insert(a->left, x);
        if (a->data < x)
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

void cal_height(node *t, int i, int &h)
{
    // cout << "incalheight i=" << i << "h=" << h << endl;
    if (t != NULL)
    {
        cal_height(t->left, i + 1, h);
        if (i > h)
            h = i;
        cal_height(t->right, i + 1, h);
    }
}

int cal_height2(node *t)
{
    if (t != NULL)
    {
        int left = cal_height2(t->left);
        int right = cal_height2(t->right);
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
    else
        return -1;
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

int checkdegree(node *t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
        {
            if (degree0(t))
                return 0;
            else if (degree1(t))
                return 1;
            else if (degree2(t))
                return 2;
        }
        else if (t->data > x)
            return checkdegree(t->left, x);
        else
            return checkdegree(t->right, x);
    }
    else
        return -1;
}
