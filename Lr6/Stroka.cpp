//
// Created by Mikhail on 19.03.2025.
//

#include <cstring>
#include <iostream>

class Stroka {
private:
    char* str;  // Динамическая строка
    int length; // Длина строки

public:
    // Конструкторы
    Stroka();                          // Конструктор по умолчанию
    Stroka(const char*);               // Конструктор с параметром
    Stroka(const Stroka&);             // Конструктор копирования
    ~Stroka();                         // Деструктор

    // Операции
    Stroka& operator=(const Stroka&);  // Оператор присваивания (-)
    Stroka operator+(const Stroka&);   // Оператор сцепления (+)
    bool operator==(const Stroka&);    // Оператор сравнения (=)

    // Методы
    int dlina();      // Метод для определения длины
    void vvod();      // Метод для ввода строки
    void vyvod();     // Метод для вывода строки
};

// Конструктор по умолчанию
Stroka::Stroka() {
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

// Конструктор с параметром
Stroka::Stroka(const char* string) {
    length = std::strlen(string);
    str = new char[length + 1];
    std::strcpy(str, string);
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s) {
    length = s.length;
    str = new char[length + 1];
    std::strcpy(str, s.str);
}

// Деструктор
Stroka::~Stroka() {
    delete[] str;
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& s) {
    if (this == &s) return *this;

    delete[] str;
    length = s.length;
    str = new char[length + 1];
    std::strcpy(str, s.str);

    return *this;
}

// Оператор сцепления (конкатенация)
Stroka Stroka::operator+(const Stroka& s) {
    Stroka temp;
    temp.length = length + s.length;
    temp.str = new char[temp.length + 1];
    std::strcpy(temp.str, str);
    std::strcat(temp.str, s.str);
    return temp;
}

// Оператор сравнения
bool Stroka::operator==(const Stroka& s) {
    return std::strcmp(str, s.str) == 0;
}

// Метод определения длины
int Stroka::dlina() {
    return length;
}

// Метод ввода строки
void Stroka::vvod() {
    char buffer[256];
    std::cin.getline(buffer, 256);

    delete[] str;
    length = std::strlen(buffer);
    str = new char[length + 1];
    std::strcpy(str, buffer);
}

// Метод вывода строки
void Stroka::vyvod() {
    std::cout << str << std::endl;
}
