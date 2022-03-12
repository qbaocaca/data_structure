#ifndef matrix_h
#define matrix_h
#include "array.h"
#include "array_class.cpp"

void allocate_(Array *&a, int rows, int cols)
{
    a = new Array[rows * cols];
}

class Matrix
{
private:
    Array *A;
    int rows = 0, cols = 0;

    void deepcopy(const Matrix &other);

public:
    Matrix();
    Matrix(int x, int y);
    void input();
    void output();

    void insert(int, int, int);
    int findCelebrity();

    // ~Matrix();

    Matrix(const Matrix &other);
    Matrix &operator=(const Matrix &other);
    void create_identity(int);
    void create_celeb_test(int);

    int view_rows();
    int view_cols();
    bool knows(int, int);

    friend istream &operator>>(istream &in, Matrix &a);
    friend ostream &operator<<(ostream &out, Matrix a);
};

#endif