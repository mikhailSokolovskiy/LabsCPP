//
// Created by Mikhail on 12.02.2025.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define N 5

using namespace std;

// Функции для операций с матрицей
void findMinMax(float matrix[N][N], float &min, float &max);

void findMinMaxTriangle(float matrix[N][N], bool lower, float &min, float &max);

void findMinMaxDiagonals(float matrix[N][N], bool mainDiagonal, float &min, float &max);

float calculateAverage(float matrix[N][N]);

float calculateTriangleAverage(float matrix[N][N], bool lower);

void calculateRowColSums(float matrix[N][N], float rowSums[N], float colSums[N]);

void findRowColExtremes(float matrix[N][N], float rowMin[N], float rowMax[N], float colMin[N], float colMax[N]);

void calculateRowColAverages(float matrix[N][N], float rowAvg[N], float colAvg[N]);

float findClosestToAverage(float matrix[N][N], float average);


int main() {
    float matrix[N][N];

    // Заполняем матрицу случайными числами
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100 / 10.0; // случайные числа от 0.0 до 9.9
        }
    }

    // Вывод матрицы
    cout << "Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8) << fixed << setprecision(2) << matrix[i][j];
        }
        cout << endl;
    }

    // Находим минимум и максимум всей матрицы
    float min, max;
    findMinMax(matrix, min, max);
    cout << "Min: " << min << ", Max: " << max << endl;

    // Мин и макс нижней треугольной части
    findMinMaxTriangle(matrix, true, min, max);
    cout << "Lower triangle - Min: " << min << ", Max: " << max << endl;

    // Мин и макс верхней треугольной части
    findMinMaxTriangle(matrix, false, min, max);
    cout << "Upper triangle - Min: " << min << ", Max: " << max << endl;

    // Мин и макс главной диагонали
    findMinMaxDiagonals(matrix, true, min, max);
    cout << "Main diagonal - Min: " << min << ", Max: " << max << endl;

    // Мин и макс второстепенной диагонали
    findMinMaxDiagonals(matrix, false, min, max);
    cout << "Secondary diagonal - Min: " << min << ", Max: " << max << endl;

    // Среднее арифметическое всей матрицы
    float avg = calculateAverage(matrix);
    cout << "Matrix average: " << avg << endl;

    // Среднее арифметическое нижней треугольной части
    cout << "Lower triangle average: " << calculateTriangleAverage(matrix, true) << endl;

    // Среднее арифметическое верхней треугольной части
    cout << "Upper triangle average: " << calculateTriangleAverage(matrix, false) << endl;

    // Суммы строк и столбцов
    float rowSums[N], colSums[N];
    calculateRowColSums(matrix, rowSums, colSums);
    cout << "Row sums: ";
    for (float sum: rowSums) cout << sum << " ";
    cout << endl;
    cout << "Column sums: ";
    for (float sum: colSums) cout << sum << " ";
    cout << endl;

    // Мин и макс строки и столбцы
    float rowMin[N], rowMax[N], colMin[N], colMax[N];
    findRowColExtremes(matrix, rowMin, rowMax, colMin, colMax);
    cout << "Row min values: ";
    for (float val: rowMin) cout << val << " ";
    cout << endl;

    cout << "Row max values: ";
    for (float val: rowMax) cout << val << " ";
    cout << endl;

    // Находим элемент, ближайший к среднему значению
    cout << "Closest to average: " << findClosestToAverage(matrix, avg) << endl;

    return 0;
}

// Находит минимум и максимум всей матрицы
void findMinMax(float matrix[N][N], float &min, float &max) {
    min = max = matrix[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < min) min = matrix[i][j];
            if (matrix[i][j] > max) max = matrix[i][j];
        }
}

// Находит мин и макс треугольной части (lower = true - нижняя, false - верхняя)
void findMinMaxTriangle(float matrix[N][N], bool lower, float &min, float &max) {
    min = max = matrix[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if ((lower && i >= j) || (!lower && i <= j)) {
                if (matrix[i][j] < min) min = matrix[i][j];
                if (matrix[i][j] > max) max = matrix[i][j];
            }
        }
}

// Мин и макс диагоналей (mainDiagonal = true - главная, false - второстепенная)
void findMinMaxDiagonals(float matrix[N][N], bool mainDiagonal, float &min, float &max) {
    min = max = matrix[0][0];
    for (int i = 0; i < N; i++) {
        float val = mainDiagonal ? matrix[i][i] : matrix[i][N - 1 - i];
        if (val < min) min = val;
        if (val > max) max = val;
    }
}

// Среднее арифметическое всей матрицы
float calculateAverage(float matrix[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += matrix[i][j];
    return sum / (N * N);
}

// Суммы строк и столбцов
void calculateRowColSums(float matrix[N][N], float rowSums[N], float colSums[N]) {
    for (int i = 0; i < N; i++) {
        rowSums[i] = colSums[i] = 0;
        for (int j = 0; j < N; j++) {
            rowSums[i] += matrix[i][j];
            colSums[j] += matrix[i][j];
        }
    }
}

// Находит элемент, ближайший к среднему
float findClosestToAverage(float matrix[N][N], float average) {
    float closest = matrix[0][0];
    float minDiff = fabs(matrix[0][0] - average);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (fabs(matrix[i][j] - average) < minDiff) {
                minDiff = fabs(matrix[i][j] - average);
                closest = matrix[i][j];
            }
    return closest;
}

// Среднее арифметическое нижней или верхней треугольной части
float calculateTriangleAverage(float matrix[N][N], bool lower) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((lower && i >= j) || (!lower && i <= j)) {
                sum += matrix[i][j];
                count++;
            }
        }
    }
    return count > 0 ? sum / count : 0;
}

// Мин и макс значений по строкам и столбцам
void findRowColExtremes(float matrix[N][N], float rowMin[N], float rowMax[N], float colMin[N], float colMax[N]) {
    for (int i = 0; i < N; i++) {
        rowMin[i] = rowMax[i] = matrix[i][0];
        colMin[i] = colMax[i] = matrix[0][i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < rowMin[i]) rowMin[i] = matrix[i][j];
            if (matrix[i][j] > rowMax[i]) rowMax[i] = matrix[i][j];
            if (matrix[i][j] < colMin[j]) colMin[j] = matrix[i][j];
            if (matrix[i][j] > colMax[j]) colMax[j] = matrix[i][j];
        }
    }
}
