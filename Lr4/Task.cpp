//
// Created by Mikhail on 19.03.2025.
//
#include <iostream>
#include <cstring>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[20];

    // Определение длины строки
    std::cout << "Длина str1: " << strlen(str1) << std::endl;

    // Копирование строк
    strcpy_s(str3, str1);
    std::cout << "Скопированная строка: " << str3 << std::endl;

    // Конкатенация строк
    strcat_s(str3, str2);
    std::cout << "Результат конкатенации: " << str3 << std::endl;

    // Сравнение строк
    int result = strcmp(str1, str2);
    if (result < 0) {
        std::cout << "str1 меньше str2" << std::endl;
    }
    else if (result > 0) {
        std::cout << "str1 больше str2" << std::endl;
    }
    else {
        std::cout << "str1 равно str2" << std::endl;
    }

    return 0;
}

#include <iostream>

// Функция определения длины строки (способ 1)
int myStrlen1(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Функция копирования строки
void myStrcpy(char* dest, const char* src) {
    while ((*dest++ = *src++) != '\0');
}

// Функция сравнения строк
int myStrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// Функция конкатенации строк
void myStrcat(char* dest, const char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++) != '\0');
}

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[20];

    // Использование функций
    std::cout << "Длина str1: " << myStrlen1(str1) << std::endl;

    myStrcpy(str3, str1);
    std::cout << "Скопированная строка: " << str3 << std::endl;

    myStrcat(str3, str2);
    std::cout << "Результат конкатенации: " << str3 << std::endl;

    int result = myStrcmp(str1, str2);
    if (result < 0) {
        std::cout << "str1 меньше str2" << std::endl;
    }
    else if (result > 0) {
        std::cout << "str1 больше str2" << std::endl;
    }
    else {
        std::cout << "str1 равно str2" << std::endl;
    }

    return 0;
}


#include <iostream>
#include <cstdlib> // Для использования malloc и free

int main() {
    char* str1 = (char*)malloc(100);
    char* str2 = (char*)malloc(100);

    strcpy(str1, "Hello");
    strcpy(str2, "World");

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    free(str1);
    free(str2);

    return 0;
}


#include <iostream>
#include <cstdlib> // Для использования calloc и free

int main() {
    char* str1 = (char*)calloc(100, sizeof(char));
    char* str2 = (char*)calloc(100, sizeof(char));

    strcpy(str1, "Hello");
    strcpy(str2, "World");

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    free(str1);
    free(str2);

    return 0;
}



#include <iostream>
#include <cstring>

int main() {
    const char* strings[] = { "Hello", "World", "C++", "Programming" };
    int count = sizeof(strings) / sizeof(strings[0]);

    for (int i = 0; i < count; i++) {
        std::cout << "Длина строки " << i << ": " << strlen(strings[i]) << std::endl;
    }

    return 0;
}