//
// Created by Mikhail on 12.02.2025.
//

#include <iostream>
using namespace std;
// Объявляем функции обмена
void obmen(int, int);
void obmen2(int*, int*);
void obmen3(int&, int&);

int main() {
    int a = 2, b = 5;

    cout << "Before trade: a = " << a << ", b = " << b << endl;

    // Вызов obmen(int, int)
    obmen(a, b);
    cout << "After trade 1 (no change): a = " << a << ", b = " << b << endl;

    // Вызов obmen2(int*, int*)
    obmen2(&a, &b);
    cout << "After trade 2: a = " << a << ", b = " << b << endl;

    // Вызов obmen3(int&, int&)
    obmen3(a, b);
    cout << "After trade 3: a = " << a << ", b = " << b << endl;

    return 0;
}

// Вариант 1: Передача по значению (не меняет исходные переменные)
void obmen(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// Вариант 2: Передача указателей (меняет исходные переменные)
void obmen2(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Вариант 3: Передача по ссылке (меняет исходные переменные)
void obmen3(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}