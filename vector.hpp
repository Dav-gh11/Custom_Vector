#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdio.h>
#include <initializer_list>
template <typename T>
class Vector
{
public:
    Vector();
    Vector(int capacity);
    Vector(const Vector &oth);
    Vector(Vector &&oth);
    Vector(const std::initializer_list<T>& elems);
    ~Vector();
    void push_back(T data);
    void push(T data, int index);
    void pop();
    void back();
    int get_size();
    int get_capacity();
    void print() const;
    void insert(int index, T value);
    void resize(int new_size);
    void remove(int index);
    Vector &operator=(const Vector &oth);
    Vector &operator=(Vector &&oth);
private:
    T *array;
    int size;
    int capacity;
};

#include "vector_imp.tpp"
#endif
