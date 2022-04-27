#include "String.h"
#include <iostream>
#include <string>
using namespace std;

void STRING::deepcopy(const STRING &other)
{
    this->len = other.len;
    for (int i = 0; i < this->len; i++)
    {
        this->content[i] = other.content[i];
    }
}

STRING::STRING()
{
    this->content = NULL;
    this->len = 0;
}

// STRING::~STRING()
// {
//     delete[] this->content;
// }

STRING::STRING(std::string str)
{
    _allocate(this->content, str.size() + 1);
    for (int i = 0; i < str.size(); i++)
    {
        this->content[i] = str[i];
    }
    this->len = str.size();
}

STRING::STRING(const STRING &other)
{
    if (this->content != NULL)
        delete[] this->content;
    _allocate(this->content, other.len + 1);
    this->len = other.len;
    this->deepcopy(other);
}

STRING &STRING::operator=(const STRING &other)
{
    if (this == &other)
        return *this;
    if (this->content != NULL)
        delete[] this->content;
    _allocate(this->content, other.len + 1);
    this->len = other.len;
    this->deepcopy(other);
    return *this;
}

bool STRING::operator==(STRING &other)
{
    for (int i = 0; i < this->len; i++)
    {
        if (this->content[i] != other.content[i])
            return 0;
    }
    return 1;
}

bool STRING::operator==(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (this->content[i] != str[i])
            return 0;
    }
    return 1;
}

bool STRING::operator!=(STRING other)
{
    for (int i = 0; i < other.len; i++)
    {
        if (this->content[i] != other.content[i])
            return 0;
    }
    return 1;
}

char STRING::getContent(int index)
{
    return this->content[index];
}

char *STRING::getWholeContent()
{
    return this->content;
}

void STRING::deleteContent()
{
    delete[] this->content;
}

void STRING::allocateContent(int size)
{
    this->content = new char[size];
}

int STRING::getLen()
{
    return this->len;
}

void STRING::setLen(int value)
{
    this->len = value;
}

void STRING::setContent(int index, char value)
{
    this->content[index] = value;
}

void STRING::input()
{
    std::string str;
    getline(std::cin, str);
    if (this->content != NULL)
        delete[] this->content;
    _allocate(this->content, str.size() + 1);
    for (int i = 0; i < str.size(); i++)
    {
        this->content[i] = str[i];
    }
    this->len = str.size();
}

void STRING::output()
{
    std::string str;
    for (int i = 0; i < this->len; i++)
    {
        str.push_back(this->content[i]);
    }
    cout << str;
}

void STRING::removeBlankHead()
{
    while (this->content[0] == ' ')
    {
        for (int i = 0; i < this->len; i++)
        {
            this->content[i] = this->content[i + 1];
        }
        this->len--;
    }
}

void STRING::removeBlankTail()
{
    while (this->content[this->len - 1] == ' ')
    {
        this->content[this->len - 1] = this->content[this->len];
        this->len--;
    }
}

void STRING::RemoveExtraSpaces()
{
    this->removeBlankHead();
    this->removeBlankTail();
    for (int i = 0; i < this->len; i++)
    {
        if (this->content[i] == ' ' && this->content[i + 1] == ' ')
        {
            for (int j = i; j < this->len; j++)
            {
                this->content[j] = this->content[j + 1];
            }
            this->len--;
            i--; // update i!
        }
    }
}

std::istream &operator>>(std::istream &in, STRING &a)
{
    std::string str;
    getline(in, str);
    if (a.getWholeContent() != NULL)
        a.deleteContent();
    a.allocateContent(str.size() + 1);
    for (int i = 0; i < str.size(); i++)
    {
        a.setContent(i, str[i]);
    }
    a.setLen(str.size());
    return in;
}

std::ostream &operator<<(std::ostream &out, STRING a)
{
    std::string str;
    for (int i = 0; i < a.getLen(); i++)
    {
        str.push_back(a.getContent(i));
    }
    out << str;
    return out;
}