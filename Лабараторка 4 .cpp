#include <iostream>
#include <cmath>
using namespace std;

// --- Задача 1: Вычисление площади прямоугольника ---
double RectS(double x1, double y1, double x2, double y2) {
    // Проверка диапазона
    if (x1 < -100 || x1 > 100 || y1 < -100 || y1 > 100 || 
        x2 < -100 || x2 > 100 || y2 < -100 || y2 > 100) {
        cout << "Ошибка: координаты должны быть в диапазоне [-100, 100]!\n";
        return -1;
    }
    // Вычисление площади
    double width = abs(x2 - x1);
    double height = abs(y2 - y1);
    return width * height;
}

// --- Задача 2: Проверка принадлежности числа интервалу ---
bool isBetween(int A, int B, int C) {
    // Проверка диапазона
    if (A < -100 || A > 100 || B < -100 || B > 100 || C < -100 || C > 100) {
        cout << "Ошибка: значения должны быть в диапазоне [-100, 100]!\n";
        return false;
    }
    // Проверка условия
    return A < B && B < C;
}

// --- Задача 3: Вывод цифр трехзначного числа ---
void extractDigits(int N) {
    // Проверка диапазона
    if (N < 100 || N > 999) {
        cout << "Ошибка: число должно быть трехзначным!\n";
        return;
    }
    // Извлечение цифр
    int lastDigit = N % 10;
    int middleDigit = (N / 10) % 10;
    cout << "Последняя цифра: " << lastDigit << endl;
    cout << "Средняя цифра: " << middleDigit << endl;
}

int main() {
    int choice;

    do {
        cout << "\nВыберите задачу для выполнения:\n";
        cout << "1. Задача 1: Вычислить площадь прямоугольника\n";
        cout << "2. Задача 2: Проверить, находится ли число в интервале\n";
        cout << "3. Задача 3: Вывести цифры трехзначного числа\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Введите координаты (x1, y1, x2, y2): ";
                double x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                double area = RectS(x1, y1, x2, y2);
                if (area != -1) {
                    cout << "Площадь: " << area << endl;
                }
                break;
            }
            case 2: {
                cout << "Введите числа A, B, C: ";
                int A, B, C;
                cin >> A >> B >> C;
                cout << "Результат: " << (isBetween(A, B, C) ? "true" : "false") << endl;
                break;
            }
            case 3: {
                cout << "Введите трехзначное число: ";
                int N;
                cin >> N;
                extractDigits(N);
                break;
            }
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Некорректный выбор, попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
