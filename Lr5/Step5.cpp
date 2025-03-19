//
// Created by Mikhail on 05.03.2025.
//5. Написать программу-шифратор файлов. Она читает из файла и пишет в
//другой файл закодированные символы.
//Схема шифровки: с = с^key[i], где с - символ, считанный из файла;
//key - ключ шифрования, строка, которая передается как параметр
//командной строки. Программа используется символы из key циклически,
//пока не будет считан весь ввод.
//Для
//проверки правильности программы зашифровать
//зашифрованный файл еще раз с тем же ключом. Должен получиться файл -
//ТОЧНАЯ копия исходного файла.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

auto encryptFile(const std::string &inputFile, const std::string &outputFile, const std::string &key) -> void {
    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary);

    if (!in || !out) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    char ch;
    size_t keyLen = key.length();
    size_t keyIndex = 0;

    while (in.get(ch)) {
        ch ^= key[keyIndex];  // Шифруем символ по формуле c' = c ^ key[i]
        out.put(ch);

        keyIndex = (keyIndex + 1) % keyLen;  // Переходим к следующему символу ключа (циклично)
    }

    in.close();
    out.close();
}

int main() {
    std::string inputFile = "Lr3/test.txt";    // Указываем имя входного файла
    std::string outputFile = "Lr3/encrypted2.txt"; // Указываем имя выходного файла
    std::string key = "mykey";               // Указываем ключ шифрования

    encryptFile(inputFile, outputFile, key);

    // Для проверки — шифруем зашифрованный файл снова
    std::string decryptedFile = "Lr3/decrypted_encrypted2.txt";
    encryptFile(outputFile, decryptedFile, key);

    std::cout << "File encrypted and decrypted successfully!" << std::endl;
    return 0;
}


