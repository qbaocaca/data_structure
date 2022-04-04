#include <iostream>

using namespace std;

int gcd(int a, int b);
int gcd2(int, int);
int modulo_inverse(int a, int b);
int power(int a, int b);
int encrypt(int m, int key, int n);
int decrypt(int c, int key, int n);

int main()
{
    // cout << modulo_inverse(5, 48);
    cout << power(8, 5);
    // int M = 8;
    // int C = encrypt(M, 5, 65);
    // cout << "C=" << encrypt(M, 5, 65) << " ";
    // if (M == decrypt(C, 29, 65))
    //     cout << "true";

    return 0;
}

int gcd(int a, int b)
{
    int gcd = 1;
    if (a % b == 0)
        return b;
    else
    {
        for (int i = b / 2; i > 1; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                gcd = i;
                break;
            }
        }
    }
    return gcd;
}

int gcd2(int a, int b)
{
    return b == 0 ? a : gcd2(b, a % b);
}

int modulo_inverse(int a, int b)
{
    int y0 = 0, y1 = 1;
    int r, q, d;
    int phi = b;
    while (a > 0)
    {
        r = b % a;
        if (r == 0)
            break;
        q = b / a;
        d = y0 - y1 * q;
        b = a;
        a = r;
        y0 = y1;
        y1 = d;
    }
    while (d < 0)
        d += phi;
    return d;
}

int power(int a, int b)
{
    int t = 1;
    int i = 0;
    while (i < b)
    {
        t *= a;
        i++;
    }
    return t;
}

int encrypt(int m, int key, int n)
{
    return power(m, key) % n;
}

int decrypt(int c, int key, int n)
{
    return power(c, key) % n;
}
