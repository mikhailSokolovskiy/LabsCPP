//
// Created by Mikhail on 05.03.2025.
//4. Написать программу, которая обрабатывает текстовый файл следующимобразом.
//В исходном тексте номера страниц проставлены в первой строке
//страницы. Требуется перенести эти номера в последнюю строку страницы и
//убрать знаки переноса. Например, номер страницы: - 34 - Необходимо получить 34.
//Признаком перехода на следующую страницу является
//управляющий символ "\f.
//

#include <cstdio>
#include <cstring>
#include <cctype>

#define MAX_LINE 1024

void processFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r"), *out = fopen(outputFile, "w");
    if (!in || !out) return;

    char line[MAX_LINE], pageNumber[10] = "";
    int firstLine = 1;

    while (fgets(line, sizeof(line), in)) {
        // Убираем символ '\f' (форматный перевод страницы)
        char *formFeed = strchr(line, '\f');
        if (formFeed) *formFeed = '\0';  // Обрезаем строку на символе \f

        // Если это первая строка страницы, ищем номер
        if (firstLine) {
            firstLine = 0;
            char *start = strchr(line, '-');
            char *end = strrchr(line, '-');
            if (start && end && start != end) {
                start++; // Пропускаем первый '-'
                while (start < end && isspace(*start)) start++; // Пропускаем пробелы
                strncpy(pageNumber, start, end - start); // Копируем номер страницы
                pageNumber[end - start] = '\0'; // Завершаем строку
                continue; // Пропускаем запись строки с номером страницы
            }
        } else {
            fputs(line, out); // Записываем обычные строки в выходной файл
        }
    }

    // Добавляем номер страницы в конец, если он был найден
    if (*pageNumber) {
        fseek(out, -1, SEEK_END);  // Ставим указатель на конец файла
        fprintf(out, "%s", pageNumber); // Записываем номер страницы в конец
    }

    fclose(in);
    fclose(out);
}

int main() {
    char inputFile[50];
    printf("Enter input file name: ");
    scanf("%49s", inputFile);
    processFile(inputFile, "Lr3/output.txt");
}






