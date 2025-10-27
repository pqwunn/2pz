#include <iostream>
#include "IntArray.h"

int main() {
    // Создаем массив размером 5
    IntArray arr(5);
    // Заполняем массив
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr.set(i, static_cast<int>(i * 20 - 50)); // значения от -50 до 30
    }

    arr.print();

    // Проверка сеттера на выход за границы
    if (!arr.set(10, 50))
        std::cout << "Индекс за пределами массива\n";

    // Проверка геттера
    int val;
    if (arr.get(2, val))
        std::cout << "Элемент 2: " << val << std::endl;

    // Добавляем элемент
    if (arr.append(99))
        std::cout << "Добавлен элемент 99\n";

    arr.print();

    // Создаем копию
    IntArray copyArr = arr;
    copyArr.print();

    // Создаем второй массив
    IntArray arr2(3);
    arr2.set(0, 10);
    arr2.set(1, -20);
    arr2.set(2, 30);

    // Сложение массивов
    IntArray sumArr = arr + arr2;
    sumArr.print();

    // Вычитание
    IntArray diffArr = arr - arr2;
    diffArr.print();

    return 0;
}