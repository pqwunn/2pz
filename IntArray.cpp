#include "IntArray.h"
#include <algorithm> 

// Конструктор
IntArray::IntArray(size_t sz) : size(sz) {
    data = new int[size]{0}; 
}

// Копирующий конструктор
IntArray::IntArray(const IntArray& other) : size(other.size) {
    data = new int[size];
    std::copy(other.data, other.data + size, data);
}

// Деструктор
IntArray::~IntArray() {
    delete[] data;
}

// Вывод массива
void IntArray::print() const {
    std::cout << "Array: ";
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// Сеттер
bool IntArray::set(size_t index, int value) {
    if (index >= size)
        return false;
    if (value < -100 || value > 100)
        return false;
    data[index] = value;
    return true;
}

// Геттер
bool IntArray::get(size_t index, int& value) const {
    if (index >= size)
        return false;
    value = data[index];
    return true;
}

// Расширение массива
void IntArray::resize(size_t new_size) {
    int* new_data = new int[new_size]{0};
    size_t min_size = std::min(size, new_size);
    std::copy(data, data + min_size, new_data);
    delete[] data;
    data = new_data;
    size = new_size;
}

// Добавление элемента
bool IntArray::append(int value) {
    if (value < -100 || value > 100)
        return false;
    resize(size + 1);
    data[size - 1] = value;
    return true;
}

// Операция сложения
IntArray IntArray::operator+(const IntArray& other) const {
    size_t max_size = std::max(size, other.size);
    IntArray result(max_size);
    for (size_t i = 0; i < max_size; ++i) {
        int a_val = (i < size) ? data[i] : 0;
        int b_val = (i < other.size) ? other.data[i] : 0;
        result.data[i] = a_val + b_val;
    }
    return result;
}

// Операция вычитания
IntArray IntArray::operator-(const IntArray& other) const {
    size_t max_size = std::max(size, other.size);
    IntArray result(max_size);
    for (size_t i = 0; i < max_size; ++i) {
        int a_val = (i < size) ? data[i] : 0;
        int b_val = (i < other.size) ? other.data[i] : 0;
        result.data[i] = a_val - b_val;
    }
    return result;
}

// Получение размера
size_t IntArray::getSize() const {
    return size;
}
