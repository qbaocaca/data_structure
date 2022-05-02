#include "bst.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
using namespace std;

void BST::deepcopy(const BST &other)
{
    int h = other.height();
    vector<int> v;
    for (int i = 0; i <= h; i++)
    {
        v = other.getNodeAtLevelnoPos(i);
        for (int j = 0; j < v.size(); j++)
        {
            this->insert(v[j]);
        }
        v.clear();
    }
}

// node *BST::search(int x)
// {
//     return this->search(this->root, x);
// }

// node *BST::search(node *t, int x)
// {
//     if (t->info == x)
//         return t;
//     else if (t->info > x)
//         this->search(t->left, x);
//     else
//         this->search(t->right, x);
// }

BST::BST()
{
    this->root = new node;
    root = NULL;
}

BST::~BST()
{
    delete[] this->root;
}

BST::BST(int value)
{
    this->root = NULL;
    this->numElements = value;
}

BST::BST(const BST &other)
{
    if (this->root != NULL)
    {
        this->~BST();
    }
    this->root = NULL;
    this->deepcopy(other);
}

BST &BST::operator=(const BST &other)
{
    if (this == &other)
        return *this;
    if (this->root != NULL)
    {
        this->~BST();
    }
    this->root = NULL;
    this->deepcopy(other);
    return *this;
}

// void BST::insert(int x)
// {
//     node *p = new node;
//     p->info = x;
//     p->left = p->right = NULL;

//     if (this->root == NULL)
//     {
//         this->root = p;
//     }
//     else
//     {
//         int flag = 0;
//         node *bleaf = NULL;
//         node *leaf = this->root;
//         while (leaf != NULL)
//         {
//             bleaf = leaf;
//             if (leaf->info == x)
//             {
//                 flag = 1;
//                 break;
//             }
//             else if (leaf->info > x)
//                 leaf = leaf->left;
//             else
//                 leaf = leaf->right;
//         }

//         if (flag == 0)
//         {
//             if (bleaf->info > x)
//                 bleaf->left = p;
//             else
//                 bleaf->right = p;
//         }
//     }
// }

void BST::insert(int x)
{

    node *p = new node;
    p->info = x;
    p->left = p->right = NULL;
    if (this->root == NULL)
    {
        this->root = p;
    }
    else
        this->insert(this->root, x);
}

void BST::insert(node *t, int x)
{
    if (x != t->info)
    {
        node *p = new node;
        p->info = x;
        p->left = p->right = NULL;
        if (x < t->info)
        {
            if (t->left != NULL)
            {
                this->insert(t->left, x);
            }
            else
                t->left = p;
        }
        else
        {
            if (t->right != NULL)
            {
                this->insert(t->right, x);
            }
            else
                t->right = p;
        }
    }
}

void BST::inorder(node *t)
{
    if (t != NULL)
    {
        this->inorder(t->left);
        cout << t->info << " ";
        this->inorder(t->right);
    }
}

void BST::inorder()
{
    this->inorder(this->root);
}

int BST::height() const
{
    int h = 0, i = 0;
    this->height(0, h);
    return h;
}

void BST::height(int i, int &h) const
{
    this->height(this->root, i, h);
}

void BST::height(node *t, int i, int &h) const
{
    if (t != NULL)
    {
        this->height(t->left, i + 1, h);
        if (i > h)
            h = i;
        this->height(t->right, i + 1, h);
    }
}

int BST::height2()
{
    return this->height2(this->root);
}

int BST::height2(node *t)
{
    if (t == NULL)
        return -1;
    else
    {
        int left = this->height2(t->left);
        int right = this->height2(t->right);

        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}

int BST::depth()
{
    return this->depth(this->root);
}

int BST::depth(node *t)
{
    if (t == NULL)
        return 0;
    else
    {
        int left = this->depth(t->left);
        int right = this->depth(t->right);

        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}

std::vector<int> BST::getNodeAtLevel(int level)
{
    vector<int> v;
    this->getNodeAtLevel(this->root, 0, level, v);
    return v;
}

void BST::getNodeAtLevel(node *t, int i, int m, std::vector<int> &arr)
{
    if (t != NULL)
    {
        this->getNodeAtLevel(t->left, i + 1, m, arr);
        if (i == m)
            arr.push_back(t->info);
        this->getNodeAtLevel(t->right, i + 1, m, arr);
    }
    else if (i == m)
        arr.push_back(0);
}

std::vector<int> BST::getNodeAtLevelnoPos(int level) const
{
    vector<int> v;
    this->getNodeAtLevelnoPos(this->root, 0, level, v);
    return v;
}

void BST::getNodeAtLevelnoPos(node *t, int i, int m, std::vector<int> &arr) const
{
    if (t != NULL)
    {
        this->getNodeAtLevelnoPos(t->left, i + 1, m, arr);
        if (i == m)
            arr.push_back(t->info);
        this->getNodeAtLevelnoPos(t->right, i + 1, m, arr);
    }
}

// bool BST::isdegreeZero(node *t)
// {
//     return (t->left == NULL && t->right == NULL);
// }

vector<int> BST::getPosition(int level)
{
    vector<int> res;
    if (level == 0)
    {
        res.push_back(this->root->info);
        return res;
    }
    vector<int> prev, curr, temp;
    this->getNodeAtLevel(this->root, 0, 1, prev);

    int h = this->height();
    vector<int> v[h + 1];
    v[1].push_back(prev[0]);
    v[1].push_back(prev[1]);
    prev.clear();
    int m = 2;
    for (int i = 2; i <= h; i++)
    {
        if (i > 3)
        {
            vector<int>::iterator it;
            for (it = v[m - 1].begin(); it != v[m - 1].end(); it++)
            {
                prev.push_back(*it);
            }
        }
        else
            this->getNodeAtLevel(this->root, 0, i - 1, prev);

        this->getNodeAtLevel(this->root, 0, i, curr);
        int numnodes = pow(2, i);

        if (curr.size() != numnodes)
        {
            temp.assign(numnodes, -2);
            for (int k = 0; k < prev.size(); k++)
            {
                if (prev[k] == 0) //|| isdegreeZero(this->search(prev[k])))
                {
                    temp[2 * k] = 0;
                    temp[2 * k + 1] = 0;
                }
            }
            for (int l = 0; l < temp.size(); l++)
            {
                if (temp[l] == -2)
                {
                    temp[l] = curr.front();
                    curr.erase(curr.begin());
                }
            }
            // if (i == 5)
            //     break;
            for (int j = 0; j < temp.size(); j++)
            {
                v[m].push_back(temp[j]);
            }
            temp.clear();
        }
        else
        {
            for (int j = 0; j < curr.size(); j++)
            {
                v[m].push_back(curr[j]);
            }
        }

        curr.clear();
        prev.clear();
        m++;
    }

    vector<int>::iterator it;
    for (it = v[level].begin(); it != v[level].end(); it++)
    {
        res.push_back(*it);
    }

    return res;
}

void BST::display()
{
    if (this->root != NULL)
    {
        int h = this->height();
        int numlastlevel = pow(2, h);
        int num_cols = 2 * numlastlevel - 1;
        vector<vector<string>> v;
        std::string default_value = " ";
        for (int i = 0; i <= h; i++)
        {
            vector<string> v1;
            for (int j = 0; j < num_cols; j++)
            {
                v1.push_back(default_value);
            }
            v.push_back(v1);
        }
        int first_index = num_cols / 2;
        int x = this->root->info;
        stringstream ss;
        ss << x;
        std::string str;
        ss >> str;
        ss.clear();
        ss.str("");
        v[0][first_index] = str;
        int index = first_index / 2;
        int index_ = index + first_index + 1;
        vector<int> arr;
        for (int i = 1; i <= h; i++)
        {
            // arr = this->getNodeAtLevel(i);
            arr = this->getPosition(i);
            x = arr[0];
            if (x != 0)
            {
                ss << x;
                ss >> str;
                ss.clear();
                ss.str("");
            }
            else
                str = " ";

            v[i][index] = str;
            for (int j = 1; j < arr.size() && index_ <= num_cols; j++)
            {
                x = arr[j];
                if (x != 0)
                {
                    ss << x;
                    ss >> str;
                    ss.clear();
                    ss.str("");
                }
                else
                    str = " ";

                v[i][index_] = str;
                index_ = index_ + first_index + 1;
            }
            index = index / 2;
            first_index = first_index / 2;
            index_ = index + first_index + 1;
            arr.clear();
        }

        for (int i = 0; i <= h; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                cout << v[i][j];
            }
            cout << endl;
        }
    }
}

void BST::printSpaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " ";
    }
}

void BST::printTree()
{
    int h = this->height();
    int whitespaces = pow(2, h + 1) - 1;

    for (int i = 0; i <= h; i++)
    {
        whitespaces /= 2;
        vector<int> var;
        var = this->getPosition(i);
        for (int j = 0; j < var.size(); j++)
        {
            if (j == 0)
                this->printSpaces(whitespaces);
            if (var[j] == 0)
                cout << " ";
            else
                cout << var[j];
            this->printSpaces(1 + 2 * whitespaces);
        }
        cout << endl;
        var.clear();
    }
}

int BST::getNumElement()
{
    return this->numElements;
}

istream &operator>>(istream &in, BST &a)
{
    int i = 0;
    int x;
    while (i < a.getNumElement())
    {
        in >> x;
        a.insert(x);
        i++;
    }
    return in;
}

ostream &operator<<(ostream &out, BST a)
{
    int h = a.height();
    int whitespaces = pow(2, h + 1) - 1;

    for (int i = 0; i <= h; i++)
    {
        whitespaces /= 2;
        vector<int> var;
        var = a.getPosition(i);
        for (int j = 0; j < var.size(); j++)
        {
            if (j == 0)
                a.printSpaces(whitespaces);
            if (var[j] == 0)
                out << " ";
            else
                out << var[j];
            a.printSpaces(1 + 2 * whitespaces);
        }
        out << endl;
        var.clear();
    }
    return out;
}
