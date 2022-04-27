#ifndef astring_h
#define astring_h
#include "String.h"
#include "string_class.cpp"

void _allocate_(STRING *&a, int size)
{
    a = new STRING[size];
}

class Astring
{
private:
    STRING *A;
    int na = 0;
    int capacity_a = 1;

    void deepcopy(const Astring &other);

public:
    Astring();
    Astring(int);
    // ~Astring();
    int getLen();
    int getCapacity();
    STRING getContent(int);
    void setContent(int, STRING);
    void setna(int);

    Astring(const Astring &other);
    Astring &operator=(const Astring &other);
    bool operator!=(Astring other);
    void insert(STRING);
    void output();

    friend std::istream &operator>>(std::istream &in, Astring &a);
    friend std::ostream &operator<<(std::ostream &out, Astring a);
};

#endif