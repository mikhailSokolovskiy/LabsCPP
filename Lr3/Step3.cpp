//
// Created by Mikhail on 05.03.2025.
//3. Дополнить программу первого пункта функцией поиска в текстовом
//файле заданной подстроки. Искомую подстроку необходимо передавать
//в качестве параметра функции. Результаты работы сформировать в
//отдельном файле.
//

#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024  // Максимальная длина строки

// Функция поиска подстроки в файле
void searchInFile(const char *filename, const char *substring) {
    FILE *in = fopen(filename, "r");
    if (!in) {
        printf("File %s could not be opened\n", filename);
        return;
    }

    FILE *out = fopen("Lr3/result.txt", "w"); // Файл для результатов
    if (!out) {
        printf("Could not create result.txt\n");
        fclose(in);
        return;
    }

    char line[MAX_LINE];
    int lineNum = 0, found = 0;

    while (fgets(line, sizeof(line), in)) {
        lineNum++;
        if (strstr(line, substring)) { // Проверяем наличие подстроки
            found = 1;
            printf("Found in line %d: %s\n", lineNum, line); // Вывод в консоль
            fprintf(out, "Line %d: %s\n", lineNum, line); // Запись в файл
        }
    }

    if (!found) {
        printf("Substring not found in %s\n", filename);
        fprintf(out, "Substring not found in %s\n", filename);
    }

    fclose(in);
    fclose(out);
    printf("Results saved in result.txt\n");
}

int main() {
    char filename[50], substring[100];

    printf("Enter file name: ");
    scanf("%49s", filename);

    printf("Enter substring to search: ");
    scanf("%99s", substring);

    searchInFile(filename, substring);
}

