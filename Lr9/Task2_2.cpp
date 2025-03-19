//
// Created by Mikhail on 19.03.2025.
//
#include <iostream>
#include <cstring>
using namespace std;

// Шаблон для нахождения большего из двух элементов
template <class T>
T getmax(T t1, T t2) {
    return (t1 > t2) ? t1 : t2;
}

// Специализация шаблона для строк
char* getmax(char* s1, char* s2) {
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}

template <class T>
T getmax(T t[], size_t size) {
    T retval = t[0];
    for (size_t i = 1; i < size; ++i) {
        if (t[i] > retval) {
            retval = t[i];
        }
    }
    return retval;
}

int main() {
    int i1 = 3, i2 = 12;
    char* s1 = "str1";
    char* s2 = "str2";

    cout << "max int = " << getmax(i1, i2) << endl;
    cout << "max str = " << getmax(s1, s2) << endl;

    return 0;
}
