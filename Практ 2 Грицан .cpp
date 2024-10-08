#include <iostream>
#include <cmath> // Подключение библиотеки математических функций
using namespace std;

int main() {
    // Задание Integer10. Дано трехзначное число.
    // Вывести сначала его последнюю цифру, а затем - среднюю цифру (десятки).
    cout << "Integer10. \n";
    int number;
    cout << "Введите трехзначное число: ";
    cin >> number;
    int last_digit = number % 10; // Последняя цифра
    int middle_digit = (number / 10) % 10; // Средняя цифра (десятки)
    cout << "Последняя цифра числа: " << last_digit << "\n";
    cout << "Средняя цифра числа: " << middle_digit << "\n" << endl;

    // Задание Boolean7. Проверить, находится ли число B между числами A и C.
    cout << "Boolean7. \n";
    int A, B, C;
    cout << "Введите три целых числа A, B, C: ";
    cin >> A >> B >> C;
    bool is_between = (B > A && B < C) || (B < A && B > C); // Проверка на вхождение
    cout << "Число B находится между числами A и C: " << boolalpha << is_between << "\n" << endl;

    // Задание Math17. Вычислить математическое выражение для y.
    cout << "Math17. \n";
    double x, y;
    cout << "Введите значение x: ";
    cin >> x;
    y = (pow(sin(2 * x), 2) * pow(2, (1 - 2 * x)) + (1.0 / 5) * log2(abs(x * x))) / 
        (tan(abs(x)) * sin(48 * M_PI / 180)); // Преобразование углов в радианы
    cout << "Значение функции y = " << y << endl;

    return 0;
}
