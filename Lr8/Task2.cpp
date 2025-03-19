//
// Created by Mikhail on 19.03.2025.
//
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("Lr8/example.txt");  // Открытие файла для записи
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    outFile << "Hello, file!" << std::endl;
    outFile.close();  // Закрытие файла

    std::ifstream inFile("example.txt");  // Открытие файла для чтения
    if (!inFile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();  // Закрытие файла
    return 0;
}

