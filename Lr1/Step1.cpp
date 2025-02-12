//
// Created by Mikhail on 12.02.2025.
//

#include <iostream>

// Объявляем функцию power до main
int power(int, int);

int main() {
    int base, exponent;

    // Запрашиваем у пользователя основание и показатель степени
    std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter exponent (non-negative integer): ";
    std::cin >> exponent;

    // Вычисляем степень и выводим результат
    std::cout << base << "^" << exponent << " = " << power(base, exponent) << std::endl;

    return 0;
}

int power(int x, int n) {
    int p = 1;
    // Выполняем умножение n раз, чтобы вычислить x^n
    for (int i = 0; i < n; i++)
        p *= x;
    return p;
}
