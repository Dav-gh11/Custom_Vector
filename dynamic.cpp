#include "vector.hpp"
#include <iostream>

int main()
{   
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    
    v.print();
    std::cout << "Vector after pushing 1, 2, 3:" << std::endl;
    v.print();

    v.insert(3, 99);
    std::cout << "Vector after inserting 99 at position 2:" << std::endl;
    v.print();

    v.remove(0);
    std::cout << "Vector after removing value " << std::endl;
    v.print();

     v.resize(5);
     std::cout << "Vector after resizing to 5:" << std::endl;
     v.print();

     std::cout << "Vector size: " << v.get_size() << std::endl;
     std::cout << "Vector capacity: " << v.get_capacity() << std::endl;

    return 0;
}
