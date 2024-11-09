#include <iostream>     // Для cout, cin и endl
#include <cmath>        // Для pow и константы M_PI
#include <limits>       // Для numeric_limits

using namespace std;

// If 10 : Проверка числа и его преобразование
void task_if1() {
    int num;
    cout << "********** If 10 **********" << endl;
    cout << "Введите целое число: ";
    cin >> num;

    if (cin) { // Проверка на корректность ввода
        if (num > 0) {
            num = -num;
            cout << "После преобразования: " << num << endl;
        } else {
            cout << "Число не положительное!" << endl;
        }
    } else {
        cout << "Ошибка: введено не целое число!" << endl;
        cin.clear(); // Очистка потока ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Пропуск оставшихся символов
    }
}

// Геом обл 5 : Проверка попадания точки в окружность
void task_geom() {
    float x, y, a, b;
    cout << "********** Геом обл 5 **********" << endl;
    cout << "Введите координаты центра окружности (a, b): ";
    cin >> a >> b;

    if (!cin) {
        cout << "Ошибка: координаты центра окружности должны быть числами!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    float radius;
    cout << "Введите радиус окружности: ";
    cin >> radius;

    if (!cin || radius <= 0) {
        cout << "Ошибка: радиус должен быть положительным числом!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Введите координаты точки (x, y): ";
    cin >> x >> y;

    if (!cin) {
        cout << "Ошибка: координаты точки должны быть числами!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Проверка, находится ли точка в пределах окружности радиуса radius вокруг центра (a, b)
    float dist = pow(x - a, 2) + pow(y - b, 2); // Квадрат расстояния до центра
    if (dist <= pow(radius, 2)) {
        cout << "Точка находится внутри окружности!" << endl;
    } else {
        cout << "Точка находится вне окружности!" << endl;
    }
}

// Задача 3: Вычисление площади и периметра круга
void task_area_perimeter() {
    float radius;
    cout << "********** Задача 3 **********" << endl;
    cout << "Введите радиус круга: ";
    cin >> radius;

    if (!cin || radius <= 0) {
        cout << "Ошибка: радиус должен быть положительным числом!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    float area = M_PI * radius * radius; // Площадь круга
    float perimeter = 2 * M_PI * radius; // Периметр круга

    cout << "Площадь круга: " << area << endl;
    cout << "Периметр круга: " << perimeter << endl;
}

int main() {
    int menu;
    cout << "Введите номер задачи (1, 2 или 3): ";
    cin >> menu;

    switch (menu) {
    case 1:
        task_if1();
        break;
    case 2:
        task_geom();
        break;
    case 3:
        task_area_perimeter();
        break;
    default:
        cout << "Неверный номер задачи! Введите 1, 2 или 3." << endl;
        break;
    }

    return 0;
}
