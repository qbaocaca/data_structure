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
void preorder(node *a);
void postorder(node *a);
node *search(node *a, int x);
void findsuccessor(node *&t, node *&a);
void delete_node(node *&t, int x);
void findsuccessor2(node *&t, node *&a);

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
    // cout << endl
    //      << "preorder: ";
    // preorder(a);
    // cout << endl
    //      << "postorder: ";
    // postorder(a);
    delete_node(a, 29);
    cout << endl;
    inorder(a);

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

void preorder(node *a)
{
    if (a != NULL)
    {
        cout << a->data << " ";
        inorder(a->left);
        inorder(a->right);
    }
}

void postorder(node *a)
{
    if (a != NULL)
    {
        inorder(a->left);
        inorder(a->right);
        cout << a->data << " ";
    }
}

node *search(node *a, int x)
{
    node *p = a;
    if (p != NULL)
    {
        if (p->data == x)
            return p;
        else if (p->data > x)
            return search(p->left, x);
        else
            return search(p->right, x);
    }
    return NULL;
}

void findsuccessor(node *&t, node *&a) // remember both of these
                                       // need to be referenced.
{
    if (t->left != NULL)
        findsuccessor(t->left, a);
    else
    {                      // a currently at the node
                           // needed to be deleted.
        a->data = t->data; // now a finds the leftmost node
                           // and keeps its value
        a = t;             // t is the leftmost node
        t = t->right;      // which is the smallest node
    }                      // a smallest node cannot have
                           // a left branch. so we assign
                           // it to its right branch (if available!)
}

// a is assigned to the leftmost node. i.e: a=t
// since it is going to be deleted.
// deleting node in BST does not delete the node itself
// but found a substitute value and delete its keeper.

void delete_node(node *&t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
        {
            node *p;
            p = t;
            if (t->left == NULL)
                t = t->right;
            else
            {
                if (t->right == NULL)
                    t = t->left;
                else
                    // smallest value on the right branch
                    // findsuccessor(t->right, p);
                    findsuccessor2(t->left, p);
                // largest value on the left branch
            }
            delete p;
        }
        else if (t->data < x)
            delete_node(t->right, x);
        else
            delete_node(t->left, x);

        // make sure this is nested if
        // otherwise, last line will be printed out.
    }
    else
        cout << "there's no key " << x;
}

void findsuccessor2(node *&t, node *&a)
{
    if (t->right != NULL)
        findsuccessor2(t->right, a);
    else
    {
        a->data = t->data;
        a = t;
        t = t->left;
    }
}