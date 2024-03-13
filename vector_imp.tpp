#include "vector.hpp"

template <typename T>
Vector<T>::Vector()
    : capacity{0}, size{0}, array{nullptr}
{
}

template <typename T>
Vector<T>::Vector(int capacity)
{
    this->capacity = capacity;
    array = new T[capacity];
    size = 0;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] array;
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &elems) : capacity(elems.size() * 2), array(new T([capacity]), size(0))
{
    for (auto &i : elems)
    {
        array[size] = i;
        ++size;
    }
}
template <typename T>
void Vector<T>::push_back(T data)
{
    if (size == capacity)
    {
        capacity = capacity ? capacity * 2 : 1;

        T *tmp = new T[capacity];

        for (int i = 0; i < size; ++i)
        {
            tmp[i] = array[i];
        }
        delete[] array;
        array = tmp;
    }
    array[size++] = data;
}

template <typename T>
void Vector<T>::push(T data, int index)
{
    if (index == capacity)
    {
        push(data);
    }
    else
    {
        array[index] = data;
    }
}

template <typename T>
void Vector<T>::pop()
{
    if (size < 0)
    {
        return;
    }
    else
    {
        --size;
    }
}

template <typename T>
int Vector<T>::get_size()
{
    return size;
}

template <typename T>
int Vector<T>::get_capacity()
{
    return capacity;
}

template <class T>
void Vector<T>::print() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void Vector<T>::insert(int index, T value)
{
    if (index > size || index < 0)
    {
        std::cerr << "Invalid index: " << std::endl;
    }
    if (size >= capacity)
    {
        size = capacity;
    }
    for (size_t i = size; i > index; --i)
    {
        array[i] = array[i - 1];
    }
    array[index] = value;
    ++size;
}

template <class T>
void Vector<T>::remove(int index)
{
    if (index >= size || index < 0)
    {
        std::cerr << "Invalid index: " << index << std::endl;
        return;
    }
    for (size_t i = index; i < size - 1; ++i)
    {
        array[i] = array[i + 1];
    }
    --size;
}

template <class T>
void Vector<T>::resize(int new_size)
{
    if (new_size < 0)
    {
        std::cerr << "Invalid size: " << new_size << std::endl;
        return;
    }
    if (new_size > capacity)
    {
        T *new_array = new T[new_size];
        for (int i = 0; i < size; i++)
        {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        capacity = new_size;
    }
    size = new_size;
}
template <class T>
Vector<T> &Vector<T>::operator=(Vector<T> &&oth)
{
    if (this != &oth)
    {
        delete[] array;
        array = oth.array;
        size = oth.size;
        capacity = oth.capacity;

        oth.array = nullptr;
        oth.size = 0;
        oth.capacity = 0;
    }
    std::cout << "move assigment operator" << std::endl;
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector &&oth)
    : array{oth.array}, size{oth.size}, capacity{oth.capacity}
{
    oth.array = nullptr;
    oth.size = 0;
    oth.capacity = 0;
    std::cout << "move constructor" << std::endl;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &oth)
{
    if (this != &oth)
    {
        T *new_array = new T[oth.capacity];
        for (int i = 0; i < oth.size; i++)
        {
            new_array[i] = oth.array[i];
        }

        delete[] array;
        array = new_array;
        size = oth.size;
        capacity = oth.capacity;
    }
    std::cout << "Copy assigment operator" << std::endl;

    return *this;
}

template <typename T>
Vector<T>::Vector(const Vector &oth)
{
    size = oth.size;
    capacity = oth.capacity;
    array = new T[oth.capacity];

    for (int i = 0; i < size; ++i)
    {
        array[i] = oth.array[i];
    }

    std::cout << "Copy constructor" << std::endl;
}
template <typename T>
void Vector<T>::back()
{
    if (size > 0)
    {
        return array[size - 1];
    }
    else
    {
        std::cout << " is empty"
    }
}
