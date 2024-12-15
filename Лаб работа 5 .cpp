#include <iostream>
#include <cmath>
using namespace std;

// Задача 1: Проверка попадания точек в круги (5 вар)
bool isInCircle(double x, double y, double r, double a, double centerX, double centerY) {
    double dx = x - centerX;
    double dy = y - centerY;
    return (dx * dx + dy * dy <= r * r); // Проверка попадания точки в круг
}

void task1() {
    int n;
    double r1, r2, a, x, y;
    cout << "Введите радиус внутреннего круга r1: "; cin >> r1;
    cout << "Введите радиус внешнего круга r2: "; cin >> r2;
    cout << "Введите расстояние a от центра внешнего круга до центров внутренних: "; cin >> a;
    cout << "Введите количество точек: "; cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        cout << "Введите координаты x и y для точки " << i+1 << ": ";
        cin >> x >> y;

        // Проверка попадания в два малых круга
        if (isInCircle(x, y, r1, a, a, a) || isInCircle(x, y, r1, a, -a, -a)) {
            count++;
        }
    }
    cout << "Количество точек внутри малых кругов: " << count << endl;
}

// Задача 2: Произведение ряда (4 вар)
double factorial(int k) {
    double result = 1;
    for (int i = 1; i <= k; i++) result *= i;
    return result;
}

void task2() {
    int n;
    double x, product = 1.0;

    cout << "Введите значение x: "; cin >> x;
    cout << "Введите количество членов ряда n: "; cin >> n;

    for (int k = 2; k <= n; k += 2) { // Члены с шагом 2
        double term = (pow(1 - x, k + 1) + 1) / factorial(k - 1);
        product *= term;
    }

    cout << "Произведение ряда: " << product << endl;
}

// Задача 3: Сумма ряда с факториалом (36 вар)
void task3() {
    int n;
    double sum = 0.0;

    cout << "Введите количество членов ряда n: "; cin >> n;

    for (int i = 1; i <= n; i++) {
        double denominator = 1;
        for (int j = 7; j <= (5 * i + 2); j += 5) { // последовательные множители
            denominator *= j;
        }
        sum += factorial(i) / denominator;
    }

    cout << "Сумма ряда: " << sum << endl;
}

// Главное меню программы
int main() {
    int choice;

    do {
        cout << "\nВыберите задачу для выполнения:\n";
        cout << "1. Проверка точек на попадание в круги (5 вар)\n";
        cout << "2. Вычисление произведения ряда (4 вар)\n";
        cout << "3. Вычисление суммы ряда (36 вар)\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Выход из программы. До свидания!\n"; break;
            default: cout << "Ошибка: неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
