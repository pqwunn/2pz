#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>

class IntArray {
private:
    int* data;
    size_t size;

public:
    // Конструктор
    explicit IntArray(size_t size);

    // Копирующий конструктор
    IntArray(const IntArray& other);

    // Деструктор
    ~IntArray();

    // Метод вывода массива
    void print() const;

    // Сеттер с проверкой диапазона и границ
    bool set(size_t index, int value);

    // Геттер с проверкой границ
    bool get(size_t index, int& value) const;

    // Добавление элемента в конец
    bool append(int value);

    // Операция сложения массивов
    IntArray operator+(const IntArray& other) const;

    // Операция вычитания массивов
    IntArray operator-(const IntArray& other) const;

    // Получение размера
    size_t getSize() const;

    // Обмен данными для расширения массива
private:
    void resize(size_t new_size);
};

#endif // INTARRAY_H
