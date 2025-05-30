
#include <iostream>
#include <cmath>
using namespace std;

struct TPoint {
    double x, y;
};

struct TTriangle {
    TPoint A, B, C;
};

// Функція для обчислення довжини відрізка
double Leng(const TPoint& A, const TPoint& B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

// Площа трикутника за формулою Герона
double AreaHeron(const TPoint& A, const TPoint& B, const TPoint& C) {
    double a = Leng(B, C);
    double b = Leng(C, A);
    double c = Leng(A, B);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Param67: Відстань від точки P до прямої AB
double Dist(const TPoint& P, const TPoint& A, const TPoint& B) {
    double area = AreaHeron(P, A, B);
    double length = Leng(A, B);
    return (2 * area) / length;
}

int main() {
    // === Param67 ===
    TPoint A, B, C, P;
    cout << "--- Param67 ---" << endl;
    cout << "Введіть координати точки A: "; cin >> A.x >> A.y;
    cout << "Введіть координати точки B: "; cin >> B.x >> B.y;
    cout << "Введіть координати точки C: "; cin >> C.x >> C.y;
    cout << "Введіть координати точки P: "; cin >> P.x >> P.y;

    cout << "Відстань від P до AB: " << Dist(P, A, B) << endl;
    cout << "Відстань від P до AC: " << Dist(P, A, C) << endl;
    cout << "Відстань від P до BC: " << Dist(P, B, C) << endl;

    // === Begin10 ===
    cout << "\n--- Begin10 ---" << endl;
    double x, y;
    cout << "Введіть два ненульових числа: ";
    cin >> x >> y;
    cout << "Сума квадратів: " << pow(x,2) + pow(y,2) << endl;
    cout << "Різниця квадратів: " << pow(x,2) - pow(y,2) << endl;
    cout << "Добуток квадратів: " << pow(x,2) * pow(y,2) << endl;
    cout << "Частка квадратів: " << pow(x,2) / pow(y,2) << endl;

    // === Boolean7 ===
    cout << "\n--- Boolean7 ---" << endl;
    int A1, B1, C1;
    cout << "Введіть три цілі числа A, B, C: ";
    cin >> A1 >> B1 >> C1;
    bool result = (B1 > A1 && B1 < C1) || (B1 < A1 && B1 > C1);
    cout << "Число B знаходиться між A і C: " << boolalpha << result << endl;

    return 0;
}
