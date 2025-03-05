//
// Created by Mikhail on 05.03.2025.
//2. Дополнить программу предыдущего пункта функцией подсчета «пустых»
//и «непустых» символов в текстовом файле. Под «пустыми» символами
//понимаются символы, не отображающиеся на экране: управляющие
//символы, пробел, звуковой сигнал и т. д.
//

#include <stdio.h>
#include <ctype.h>  // Для isprint()

int main() {
    char name[50];
    printf("Enter file name: ");
    scanf("%49s", name);

    FILE *in = fopen(name, "r");
    if (!in) return printf("File %s could not be opened\n", name), 1;

    int ch, emptyCount = 0, nonEmptyCount = 0;

    while ((ch = getc(in)) != EOF) {
        putchar(ch);
        if (isprint(ch))  // Если символ печатаемый
            nonEmptyCount++;
        else  // Иначе считаем как "пустой" символ
            emptyCount++;
    }

    fclose(in);
    printf("\nEmpty characters: %d\nNon-empty characters: %d\n", emptyCount, nonEmptyCount);
}


