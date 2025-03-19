//
// Created by Mikhail on 19.03.2025.
//
#include <iostream>
#include <fstream>
#include <string>

void encrypt(std::string& text) {
    for (char& c : text) {
        c += 3;  // Простой сдвиг для шифрования
    }
}

void decrypt(std::string& text) {
    for (char& c : text) {
        c -= 3;  // Простой сдвиг для расшифровки
    }
}

int main() {
    std::string text;
    std::cout << "Enter text to encrypt: ";
    std::getline(std::cin, text);

    encrypt(text);  // Шифруем текст

    std::ofstream outFile("Lr8/encrypted.txt");
    outFile << text;  // Записываем зашифрованный текст в файл
    outFile.close();

    std::cout << "Encrypted text: " << text << std::endl;

    // Чтение зашифрованного текста из файла
    std::ifstream inFile("Lr8/encrypted.txt");
    std::getline(inFile, text);
    inFile.close();

    decrypt(text);  // Расшифровка текста

    std::cout << "Decrypted text: " << text << std::endl;

    return 0;
}
