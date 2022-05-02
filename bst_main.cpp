#include <iostream>
#include "bst.h"
#include "bst_class.cpp"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    BST t;
    int x;
    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        t.insert(x);
        // cout << "tree after insert " << x << endl;
        // t.printTree();
        // t.display();
    }
    // t.inorder();
    // cout << endl
    //      << "height=" << t.height();
    // cout << endl
    //      << "height2=" << t.height2();
    // cout << endl
    //      << "depth=" << t.depth();
    // cout << endl;
    // int m;
    // cin >> m;
    // cout << endl
    //      << "Nodes at level " << m << " is ";
    // vector<int> v;
    // // v = t.getNodeAtLevel(m);
    // // v = t.getPosition(m);
    // v = t.getNodeAtLevelnoPos(m);
    // for (int i = 0; i < v.size() - 1; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << v[v.size() - 1];

    // cout << endl;
    t.printTree();
    // t.display();

    // int rows, cols;
    // cin >> rows >> cols;

    // vector<vector<string>> v;
    // std::string default_value = "iloveyou";

    // for (int i = 0; i < rows; i++)
    // {
    //     vector<string> v1;
    //     for (int j = 0; j < cols; j++)
    //     {
    //         v1.push_back(default_value);
    //     }
    //     v.push_back(v1);
    // }

    // v[3][2] = "ihateyou";

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int x = 5;
    // int y = 6;
    // stringstream ss;
    // std::string str;
    // ss << x;
    // ss >> str;
    // cout << ss.str() << endl;
    // ss.clear();
    // ss.str("");
    // ss << y;
    // ss >> str;
    // cout << ss.str() << endl;

    // srand(time(NULL));
    // BST a;
    // int n;
    // cin >> n;
    // int i = 0;
    // int x;
    // vector<int> v;
    // while (i < n)
    // {
    //     x = rand() % 100 + 1;
    //     a.insert(x);
    //     v.push_back(x);
    //     i++;
    // }
    // cout << "array: ";
    // for (int i = 0; i < v.size() - 1; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << v[v.size() - 1];
    // cout << endl;

    // a.display();
    // a.printTree();

    // int n;
    // cin >> n;
    // vector<int> v[n];
    // int x;
    // for (int i = 0; i < n; i++)
    // {
    //     while (1)
    //     {
    //         cin >> x;
    //         if (x == 0)
    //             break;
    //         v[i].push_back(x);
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     vector<int>::iterator it;
    //     for (it = v[i].begin(); it != v[i].end(); it++)
    //     {
    //         cout << *it << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    // vector<int> res(v[2]);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }

    // BST t1(t);
    // // t1.printTree();

    // BST t2;
    // while (1)
    // {
    //     cin >> x;
    //     if (x == 0)
    //         break;
    //     t2.insert(x);
    // }
    // t2.printTree();

    // t2 = t1;
    // t2.printTree();

    // BST a(7);
    // cin >> a;
    // cout << a;

    // BST t1;
    // for (int i = 0; i < 100000; i++)
    // {
    //     t1 = t;
    // }

    // vector<int> v, v1;
    // int h = t.height();
    // int flag = 0;
    // for (int i = 0; i <= h; i++)
    // {
    //     v = t.getNodeAtLevelnoPos(i);
    //     v1 = t1.getNodeAtLevelnoPos(i);
    //     for (int j = 0; j < v.size(); j++)
    //     {
    //         if (v[j] != v1[j])
    //         {
    //             cout << "WRONG!";
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 1)
    //         break;
    //     v.clear();
    //     v1.clear();
    // }
    // if (flag == 0)
    //     cout << "OK!";

    return 0;
}