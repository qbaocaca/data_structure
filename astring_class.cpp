#include "Astring.h"
#include <string>

void Astring::deepcopy(const Astring &other)
{
    this->na = other.na;
    for (int i = 0; i < this->na; i++)
    {
        this->A[i] = other.A[i];
    }
}

Astring::Astring()
{
    _allocate_(this->A, 1);
    this->na = 0;
    this->capacity_a = 1;
}

Astring::Astring(int value)
{
    _allocate_(this->A, value);
    this->na = 0;
    this->capacity_a = value;
}

// Astring::~Astring()
// {
//     this->A->deleteContent();
//     this->A->setLen(0);
//     delete[] this->A;
//     this->na = 0;
//     this->capacity_a = 1;
// }

int Astring::getLen()
{
    return this->na;
}

int Astring::getCapacity()
{
    return this->capacity_a;
}

STRING Astring::getContent(int index)
{
    return this->A[index];
}

void Astring::setContent(int index, STRING x)
{
    this->A[index] = x;
}

void Astring::setna(int value)
{
    this->na = value;
}

Astring::Astring(const Astring &other)
{
    _allocate_(this->A, other.na);
    this->deepcopy(other);
}

Astring &Astring::operator=(const Astring &other)
{
    if (this == &other)
        return *this;
    if (this->A->getWholeContent() != NULL)
    {
        // this->A->deleteContent();
        // this->A->setLen(0);
        delete[] this->A;
    }
    _allocate_(this->A, other.na);
    this->deepcopy(other);
    return *this;
}

bool Astring::operator!=(Astring other)
{
    for (int i = 0; i < other.na; i++)
    {
        if (this->A[i] != other.A[i])
            return 0;
    }
    return 1;
}

void Astring::insert(STRING x)
{
    if (this->na == 0)
    {
        _allocate_(this->A, 1);
        this->A[0] = x;
        this->na++;
    }
    else if (this->na == this->capacity_a)
    {
        this->capacity_a = 2 * this->na + 1;
        STRING *B;
        _allocate_(B, this->capacity_a);
        for (int i = 0; i < this->na; i++)
        {
            B[i] = this->A[i];
        }
        B[this->na] = x;
        this->A->deleteContent();
        _allocate_(this->A, this->capacity_a);
        for (int i = 0; i <= this->na; i++)
        {
            this->A[i] = B[i];
        }
        this->na++;
        B->deleteContent();
    }
    else
    {
        this->A[this->na] = x;
        this->na++;
    }
}

void Astring::output()
{
    for (int i = 0; i < this->na - 1; i++)
    {
        cout << this->A[i] << " ";
    }
    cout << this->A[this->na - 1];
}

std::istream &operator>>(std::istream &in, Astring &a)
{
    STRING x;
    while (true)
    {
        in >> x;
        if (x == "null")
            break;
        a.insert(x);
    }
    // STRING x;
    // int i;
    // for (i = 0; i < a.getCapacity(); i++)
    // {
    //     in >> x;
    //     a.setContent(i, x);
    // }
    // a.setna(i);
    return in;
}

std::ostream &operator<<(std::ostream &out, Astring a)
{
    for (int i = 0; i < a.na - 1; i++)
    {
        out << a.A[i] << " ";
    }
    out << a.A[a.na - 1];

    return out;
}
