#ifndef double_h
#define double_h
#define MAX 1000

class doubleHash
{
private:
    int table_size;
    int na;
    int prime_num;
    bool *check;
    int *hash;

    void __setsieve();

public:
    doubleHash(int);
    void print();
    int getPrimeNum();
    int hash1(int);
    int hash2(int);
    bool isfull();
    void insert(int);
    bool search(int);
    doubleHash &erase(int);
};

#endif