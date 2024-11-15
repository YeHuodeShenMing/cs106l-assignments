#pragma once
 
#include <cstddef>

template <typename T>
class Vector{
    public:
        using iterator = T*;

        Vector();
        Vector(size_t size, size_t capacity);
        ~Vector();

        // T& 表示引用，别名 。不复制，光修改
        T& at(size_t index) const;
        void push_back(const T& elem);
        T& operator[] (size_t index);

        bool empty() const;
        size_t get_size() const;

        void set_capacity(size_t new_capacity);

        iterator begin();
        iterator end();

    
    private:
        size_t _size;
        size_t _capacity;
        // T* 表示指向T类型的指针
        T* _elem;

        void set_capacity_bigger();        

};


#include "class.cpp"