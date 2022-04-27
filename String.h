#ifndef string_h
#define string_h
#include <iostream>
#include <string>

void _allocate(char *&str, int size)
{
    str = new char[size];
}

class STRING
{
private:
    char *content;
    int len;

    void deepcopy(const STRING &other);

public:
    STRING();
    // ~STRING();
    STRING(std::string);

    STRING(const STRING &other);
    STRING &operator=(const STRING &other);
    bool operator==(STRING &other);
    bool operator==(std::string);
    bool operator!=(STRING other);
    char getContent(int);
    char *getWholeContent();
    void deleteContent();
    void allocateContent(int);
    int getLen();
    void setLen(int);
    void setContent(int, char);
    void input();
    void output();
    void removeBlankHead();
    void removeBlankTail();
    void RemoveExtraSpaces();

    friend std::istream &operator>>(std::istream &in, STRING &a);
    friend std::ostream &operator<<(std::ostream &out, STRING a);
};

#endif