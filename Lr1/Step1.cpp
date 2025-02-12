//
// Created by Mikhail on 12.02.2025.
//

#include <iostream>

// Объявляем функцию power до main
int power(int, int);

int main() {
    int i, k;
    for (i = 0; i < 10; i++) {
        k = power(2, i);
        std::cout << "2^" << i << " = " << k << std::endl;
    }
    return 0;
}

int power(int x, int n) {
    int p = 1;
    // Выполняем умножение n раз, чтобы вычислить x^n
    for (int i = 0; i < n; i++)
        p *= x;
    return p;
}
