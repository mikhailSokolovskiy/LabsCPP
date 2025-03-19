//
// Created by Mikhail on 19.03.2025.
//
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("Lr8/example.txt");

    // Проверим состояние потока
    if (!outFile.good()) {
        std::cerr << "File stream is not good." << std::endl;
        return 1;
    }

    outFile << "This is a test text." << std::endl;

    // Изменим состояние потока на ошибочное для демонстрации
    outFile.setstate(std::ios::failbit);
    if (outFile.fail()) {
        std::cerr << "Stream is in fail state." << std::endl;
    }

    // Очистим ошибки и продолжим работу
    outFile.clear();
    outFile << "More text after clearing the error state." << std::endl;

    outFile.close();

    return 0;
}
