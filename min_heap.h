#ifndef min_heap_h
#define min_heap_h

class min_heap
{
private:
    int *A;
    int capacity_a;
    int na;

public:
    min_heap(int);
    void heapify(int);
    void insert(int);
    int left(int);
    int right(int);
    int parent(int);
    void print();
    min_heap &decreaseKey(int, int);
    void build_heap();
    min_heap &delete_(int);
    int extract_min();
};

#endif