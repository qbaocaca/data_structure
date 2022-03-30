#include "double_hash.h"
#include <iostream>

using namespace std;

void doubleHash::__setsieve()
{
    this->check = new bool[MAX];
    for (int i = 0; i < MAX; i++)
    {
        this->check[i] = 1;
    }

    for (int i = 2; i <= MAX / 2; i++)
    {
        if (this->check[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                this->check[j] = 0;
            }
        }
    }
}

doubleHash::doubleHash(int n)
{
    this->__setsieve();
    this->table_size = n;
    this->prime_num = n - 1;
    while (this->check[this->prime_num] != 1)
    {
        if (this->check[this->prime_num] == 1)
            break;
        this->prime_num--;
    }
    this->na = 0;
    this->hash = new int[this->table_size];
    for (int i = 0; i < this->table_size; i++)
    {
        this->hash[i] = -1;
    }
}

void doubleHash::print()
{
    for (int i = 0; i < this->table_size - 1; i++)
    {
        cout << this->hash[i] << " ";
    }
    cout << this->hash[this->table_size - 1];
}

int doubleHash::getPrimeNum()
{
    return this->prime_num;
}

int doubleHash::hash1(int x)
{
    return x % this->table_size;
}

int doubleHash::hash2(int x)
{
    return this->prime_num - (x % this->prime_num);
}

bool doubleHash::isfull()
{
    return this->na == this->table_size;
}

void doubleHash::insert(int x)
{
    if (x == -1 || x == -2)
    {
        cout << "x could not be -1 or -2!" << endl;
    }
    else if (this->isfull())
        cout << "Table is full!" << endl;
    else
    {
        int probe = this->hash1(x);
        int offset = this->hash2(x);
        while (this->hash[probe] != -1)
        {
            if (this->hash[probe] == -2)
                break;
            probe = (probe + offset) % this->table_size;
        }

        this->hash[probe] = x;
        this->na++;
    }
}

bool doubleHash::search(int x)
{
    int probe = this->hash1(x);
    int offset = this->hash2(x);
    int initialPos = probe;
    bool firstItr = true;

    while (1)
    {
        if (this->hash[probe] == -1)
            return 0;
        else if (this->hash[probe] == x)
            return 1;
        else if (probe == initialPos && !firstItr)
            return 0;
        else
            probe = (probe + offset) % this->table_size;

        firstItr = false;
    }

    return 0;
}

doubleHash &doubleHash::erase(int x)
{
    if (!this->search(x))
        return *this;
    else
    {

        int hash1 = this->hash1(x);
        int offset = this->hash2(x);
        int probe = hash1;

        while (this->hash[probe] != -1)
        {
            if (this->hash[probe] == x)
            {
                this->hash[probe] = -2;
                this->na--;
                return *this;
            }
            else
                probe = (probe + offset) % this->table_size;
        }
    }
    return *this;
}