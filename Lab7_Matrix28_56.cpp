
#include <iostream>
#include <iomanip>
using namespace std;

const int M = 20, N = 20;

void fillMatrix(int matr[M][N], int &m, int &n) {
    do {
        cout << "Введите количество строк и столбцов (чётные числа от 2 до 20):\n";
        cout << "m: "; cin >> m;
        cout << "n: "; cin >> n;
    } while (m < 2 || m > 20 || n < 2 || n > 20 || m % 2 != 0 || n % 2 != 0);

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matr[i][j];
}

void showMatrix(int matr[M][N], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << setw(4) << matr[i][j];
        cout << endl;
    }
}

int matrix28(int matr[M][N], int m, int n) {
    int minOfMax = matr[0][0];
    for (int j = 0; j < n; ++j) {
        int maxVal = matr[0][j];
        for (int i = 1; i < m; ++i)
            maxVal = max(maxVal, matr[i][j]);
        minOfMax = min(minOfMax, maxVal);
    }
    return minOfMax;
}

void matrix56(int matr[M][N], int m, int n) {
    for (int i = 0; i < m / 2; ++i)
        for (int j = 0; j < n / 2; ++j)
            swap(matr[i][j], matr[i + m / 2][j + n / 2]);
}

int main() {
    int matr[M][N], m, n;
    fillMatrix(matr, m, n);

    cout << "\nИсходная матрица:\n";
    showMatrix(matr, m, n);

    cout << "\nMatrix28: Минимум среди максимумов столбцов = " << matrix28(matr, m, n) << endl;

    matrix56(matr, m, n);
    cout << "\nMatrix56: Матрица после обмена главной верхней и побочной нижней четвертей:\n";
    showMatrix(matr, m, n);

    return 0;
}
