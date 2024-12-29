#include <iostream>
#include <cmath>
#include <limits> // Для обробки введення

using namespace std;

// --- Завдання 1: Перевірка попадання точок в кола ---
bool isInCircle(double x, double y, double r, double centerX, double centerY) {
    // Обчислюємо відстань від точки до центра
    double dx = x - centerX;
    double dy = y - centerY;
    return (dx * dx + dy * dy <= r * r); // Перевірка умови належності до кола
}

void task1() {
    int n;              // Кількість точок
    double r1, r2, a;   // Радіуси та відстань між колами
    double x, y;        // Координати точок

    cout << "Завдання 1: Перевірка точок у заданих колах" << endl;
    cout << "Введіть радіус внутрішнього кола r1: "; cin >> r1;
    cout << "Введіть радіус зовнішнього кола r2: "; cin >> r2;
    cout << "Введіть відстань a до центра: "; cin >> a;
    cout << "Введіть кількість точок: "; cin >> n;

    int count = 0; // Лічильник точок, що потрапили в коло

    for (int i = 0; i < n; i++) {
        cout << "Введіть координати x і y для точки " << i + 1 << ": ";
        cin >> x >> y;

        // Перевірка для двох внутрішніх кіл
        if (isInCircle(x, y, r1, a, a) || isInCircle(x, y, r1, -a, -a)) {
            count++;
        }
    }

    cout << "Кількість точок у внутрішніх колах: " << count << endl;
}

// --- Завдання 2: Обчислення добутку ряду ---
double factorial(int k) {
    double result = 1;
    for (int i = 1; i <= k; i++) result *= i;
    return result; // Обчислення факторіалу
}

void task2() {
    int n;         // Кількість членів ряду
    double x;      // Параметр ряду
    double product = 1.0; // Початкове значення добутку

    cout << "Завдання 2: Обчислення добутку ряду" << endl;
    cout << "Введіть значення x: "; cin >> x;
    cout << "Введіть кількість членів ряду n: "; cin >> n;

    for (int k = 2; k <= n; k += 2) { // Обчислення для парних індексів
        double term = (pow(1 - x, k + 1) + 1) / factorial(k - 1);
        product *= term; // Додаємо поточний член до добутку
    }

    cout << "Добуток ряду: " << product << endl;
}

// --- Завдання 3: Обчислення суми ряду ---
void task3() {
    int n;          // Кількість членів ряду
    double sum = 0.0; // Початкове значення суми

    cout << "Завдання 3: Обчислення суми ряду" << endl;
    cout << "Введіть кількість членів ряду n: "; cin >> n;

    for (int i = 1; i <= n; i++) {
        double denominator = 1;

        // Обчислення знаменника
        for (int j = 7; j <= (5 * i + 2); j += 5) {
            denominator *= j;
        }

        // Додавання до суми
        sum += factorial(i) / denominator;
    }

    cout << "Сума ряду: " << sum << endl;
}

// --- Головне меню ---
int main() {
    int choice; // Вибір пункту меню

    do {
        // Виведення меню для вибору завдання
        cout << "\nМеню завдань:\n";
        cout << "1. Перевірка точок у колах (Завдання 1)\n";
        cout << "2. Обчислення добутку ряду (Завдання 2)\n";
        cout << "3. Обчислення суми ряду (Завдання 3)\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1(); // Виконання першого завдання
                break;
            case 2:
                task2(); // Виконання другого завдання
                break;
            case 3:
                task3(); // Виконання третього завдання
                break;
            case 0:
                cout << "Вихід з програми.\n"; // Вихід із програми
                break;
            default:
                cout << "Помилка: Невірний вибір. Спробуйте знову.\n";
        }
    } while (choice != 0); // Повторення меню, поки не вибрано вихід

    return 0; // Завершення роботи програми
}
