//
// Created by Mikhail on 19.03.2025.
//

#include "Stroka.cpp"

int main() {
    Stroka s1("qwerty"), s3, s4(s1), s5;

    std::cout << "Введите строку для s3: ";
    s3.vvod();

    std::cout << "Вы ввели: ";
    s3.vyvod();

    s3 = "asdfg";
    std::cout << "После присваивания: ";
    s3.vyvod();

    s5 = s1 + s3 + s4;
    std::cout << "Результат сцепления: ";
    s5.vyvod();

    std::cout << "Длина s5 = " << s5.dlina() << std::endl;

    if (s1 == s5) {
        std::cout << "Строки s1 и s5 равны" << std::endl;
    } else {
        std::cout << "Строки s1 и s5 НЕ равны" << std::endl;
    }

    if (s1 == s4) {
        std::cout << "Строки s1 и s4 равны" << std::endl;
    }

    return 0;
}