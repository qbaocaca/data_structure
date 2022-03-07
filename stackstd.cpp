#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // stack<int> my_stack;
    // int x;
    // while (true)
    // {
    //     cin >> x;
    //     if (x == 0)
    //     {
    //         break;
    //     }
    //     my_stack.push(x);
    // }

    // while (!my_stack.empty())
    // {
    //     cout << my_stack.top() << " ";
    //     my_stack.pop();
    // }

    // string s;
    // stack<char> st;
    // getline(cin, s);
    // for (int i = 0; i < s.length(); i++)
    // {
    //     st.push(s[i]);
    // }

    // while (!st.empty())
    // {
    //     cout << st.top();
    //     st.pop();
    // }

    // stack<int> st;
    // int n;
    // cin >> n;

    // while (n != 0)
    // {
    //     int rem = n % 2;
    //     st.push(rem);
    //     n = n / 2;
    // }

    // while (!st.empty())
    // {
    //     cout << st.top();
    //     st.pop();
    // }

    // stack<char> st;
    // string s;
    // getline(cin, s);
    // string a;
    // for (int i = s.length() - 1; i >= 0; i--)
    // {
    //     st.push(s[i]);
    // }

    // int j = 0;

    // int count = 1;
    // a.push_back(st.top());
    // st.pop();
    // char ch;
    // while (!st.empty())
    // {
    //     if (st.top() != a[j])
    //     {
    //         ch = count + '0';
    //         a.push_back(ch);
    //         count = 0;
    //         j++;
    //         a.push_back(st.top());
    //         j++;
    //     }
    //     count++;
    //     st.pop();
    // }
    // ch = count + '0';
    // a.push_back(ch);
    // j += 2;

    // for (int i = 0; i < j; i++)
    // {
    //     cout << a[i];
    // }

    stack<int> st;
    int n, base;
    cin >> n >> base;

    while (n > 0)
    {
        int rem = n % base;
        st.push(rem);
        n = n / base;
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}
