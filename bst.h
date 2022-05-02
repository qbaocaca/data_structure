#ifndef bst_h
#define bst_h
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;
};

class BST
{
private:
    node *root;
    int numElements;

    // bool isdegreeZero(node *);

    void deepcopy(const BST &other);

public:
    void printSpaces(int);
    vector<int> getPosition(int);
    // node *search(int);
    // node *search(node *, int);
    BST();
    ~BST();
    BST(int);
    int getNumElement();
    BST(const BST &other);
    BST &operator=(const BST &other);
    void insert(int);
    void insert(node *, int);
    void inorder(node *t);
    void inorder();
    int height() const;
    void height(int, int &) const;
    void height(node *, int, int &) const;
    int height2();
    int height2(node *);
    int depth();
    int depth(node *);
    std::vector<int> getNodeAtLevel(int);
    void getNodeAtLevel(node *, int, int, std::vector<int> &);
    std::vector<int> getNodeAtLevelnoPos(int) const;
    void getNodeAtLevelnoPos(node *, int, int, std::vector<int> &) const;
    void display();
    void printTree();

    friend istream &operator>>(istream &in, BST &a);
    friend ostream &operator<<(ostream &out, BST a);
};

#endif