#include <iostream>     // Для введення/виведення
#include <cmath>        // Для математичних обчислень
#include <limits>       // Для очищення буфера введення

using namespace std;

// Завдання 1: Робота з двома цілими числами
void task_if10() {
    int A, B; // Змінні для введення
    cout << "********** Завдання 1: If_10 **********" << endl;
    cout << "Введіть два цілих числа A і B: ";
    cin >> A >> B;

    // Перевірка коректності введення
    if (!cin) {
        cout << "Помилка: введіть цілі числа!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Логіка перевірки умов
    if (A != B) { // Якщо числа не рівні
        A = A + B;
        B = A;
    } else { // Якщо рівні
        A = 0;
        B = 0;
    }

    // Виведення результатів
    cout << "Нові значення: A = " << A << ", B = " << B << endl;
}

// Завдання 2: Перевірка попадання точки в кільце
void task_geom5() {
    float r1, r2, a, x, y; // Радіуси, координати, відстань
    cout << "********** Завдання 2: Geom_5 **********" << endl;

    // Введення параметрів для кільця
    cout << "Введіть радіус внутрішнього кола r1: ";
    cin >> r1;
    cout << "Введіть радіус зовнішнього кола r2: ";
    cin >> r2;
    cout << "Введіть відстань від центру a: ";
    cin >> a;

    // Перевірка коректності введених даних
    if (!cin || r1 <= 0 || r2 <= 0 || r1 > r2 || a < 0) {
        cout << "Помилка: некоректні дані!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Введення координат точки
    cout << "Введіть координати точки (x, y): ";
    cin >> x >> y;

    if (!cin) {
        cout << "Помилка: координати повинні бути числами!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Обчислення відстані до центра кола
    float dist = sqrt(pow(x - a, 2) + pow(y - a, 2));

    // Перевірка попадання точки в область кільця
    if (dist >= r1 && dist <= r2) {
        cout << "Точка знаходиться в області кільця!" << endl;
    } else {
        cout << "Точка знаходиться поза кільцем!" << endl;
    }

    // Обчислення площі кільця
    float area_inner = M_PI * r1 * r1; // Площа внутрішнього кола
    float area_outer = M_PI * r2 * r2; // Площа зовнішнього кола
    float total_area = area_outer - area_inner; // Площа кільця

    cout << "Площа зовнішнього кола: " << area_outer << endl;
    cout << "Площа внутрішнього кола: " << area_inner << endl;
    cout << "Загальна площа кільця: " << total_area << endl;
}

// Завдання 3: Площі і периметри двох кіл
void task_area_perimeter() {
    float r1, r2; // Радіуси двох кіл
    cout << "********** Завдання 3 **********" << endl;

    // Введення радіусів
    cout << "Введіть радіуси двох кіл r1 і r2: ";
    cin >> r1 >> r2;

    // Перевірка коректності даних
    if (!cin || r1 <= 0 || r2 <= 0) {
        cout << "Помилка: радіуси повинні бути додатними числами!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Обчислення площі і периметру для першого кола
    float area1 = M_PI * r1 * r1;
    float perimeter1 = 2 * M_PI * r1;

    // Обчислення площі і периметру для другого кола
    float area2 = M_PI * r2 * r2;
    float perimeter2 = 2 * M_PI * r2;

    // Виведення результатів
    cout << "Для першого кола: Площа = " << area1 << ", Периметр = " << perimeter1 << endl;
    cout << "Для другого кола: Площа = " << area2 << ", Периметр = " << perimeter2 << endl;
}

// Головна функція з меню вибору
int main() {
    int menu; // Номер завдання
    cout << "Виберіть номер завдання (1, 2, 3): ";
    cin >> menu;

    // Перехід між завданнями за номером
    switch (menu) {
    case 1:
        task_if10();  // Завдання 1
        break;
    case 2:
        task_geom5(); // Завдання 2
        break;
    case 3:
        task_area_perimeter(); // Завдання 3
        break;
    default:
        cout << "Невірний номер завдання! Введіть 1, 2 або 3." << endl;
        break;
    }

    return 0;
}
