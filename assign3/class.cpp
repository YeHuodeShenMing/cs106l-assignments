#include "class.h"

// public:
template <typename T>
Vector<T>::Vector() {
    _size = 0;
    _capacity = 8;
    _elem = new T[_capacity];
}

template <typename T>
Vector<T>::Vector(size_t size, size_t capacity) {
    this->_size = size;
    this->_capacity = capacity;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] _elem;
}

// T& 表示引用，别名 。不复制，光修改
template <typename T>
T& Vector<T>::at(size_t index) const{
    if (index < this->_size) {
        return _elem[index];
    }
    else {
        throw std::out_of_range("Out of range!");
    }

}

template <typename T>
void Vector<T>::push_back(const T &elem) {
    if (this->_size == _capacity) {
        set_capacity_bigger();
    }
    
    _elem[_size] == elem;
    this->_size ++;

}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return this->_elem[index];
}

template <typename T>
bool Vector<T>::empty() const{
    return _size == 0;
}

template <typename T>
size_t Vector<T>::get_size() const{
    return this->_size;
}

template <typename T>
void Vector<T>::set_capacity(size_t new_capacity) {
    this->_capacity = new_capacity;
    
}

/* Changed from lecture:
 * Some compilers (e.g. g++) will require that when returning a
 * type that depends on a template type (for example, iterator in this example)
 * that you preface the return type with `typename`.
 * 
 * There are on-going proposals to get rid of this requirement from the language,
 * but alas, here we are.
 */

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return _elem;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return _elem + _size;
}

template <typename T>
void Vector<T>::set_capacity_bigger() {
    auto _newData = new T[_capacity * 2];
    for (size_t i = 0; i < this->_size; ++i) {
        _newData[i] = _elem[i];
    }

    _capacity *= 2;
    _elem = _newData;
}