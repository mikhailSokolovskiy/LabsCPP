//
// Created by Mikhail on 05.03.2025.
//6. Дополнить программу п. 5 возможностью вводить имя файла и ключ из
//командной строки.
//Отчет по лабораторной работе 5 должен включать:
//•блок-схемы алгоритмов всех функций;
//тексты программ с подробными комментариями;
//•выводы по проделанным экспериментам;
//ответы на вопросы.
//

#include <iostream>
#include <fstream>
#include <string>

void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    if (!in.is_open()) {
        std::cerr << "Error opening input file: " << inputFile << std::endl;
        return;
    }
    if (!out.is_open()) {
        std::cerr << "Error opening output file: " << outputFile << std::endl;
        return;
    }

    char ch;
    size_t keyLen = key.length();
    size_t keyIndex = 0;

    std::cout << "Starting encryption..." << std::endl;

    while (in.get(ch)) {
        ch ^= key[keyIndex];  // Шифруем символ по формуле c' = c ^ key[i]
        out.put(ch);

        keyIndex = (keyIndex + 1) % keyLen;  // Переходим к следующему символу ключа (циклично)
    }

    std::cout << "Encryption completed!" << std::endl;

    in.close();
    out.close();
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <inputFile> <outputFile> <key>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];    // Имя входного файла
    std::string outputFile = argv[2];   // Имя выходного файла
    std::string key = argv[3];          // Ключ шифрования

    std::cout << "Input file: " << inputFile << std::endl;
    std::cout << "Output file: " << outputFile << std::endl;
    std::cout << "Encryption key: " << key << std::endl;

    encryptFile(inputFile, outputFile, key);

    // Для проверки — шифруем зашифрованный файл снова
    std::string decryptedFile = "Lr3/decrypted_encrypted2.txt";
    std::cout << "Decrypting the encrypted file..." << std::endl;
    encryptFile(outputFile, decryptedFile, key);

    std::cout << "File encrypted and decrypted successfully!" << std::endl;
    return 0;
}

