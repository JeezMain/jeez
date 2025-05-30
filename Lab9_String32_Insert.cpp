
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Власна функція вставки підрядка str у s на позицію pos
void insert_custom(char* s, size_t pos, const char* str) {
    char buffer[1000];
    size_t len_s = strlen(s);
    size_t len_str = strlen(str);
    if (pos > len_s) return;

    strncpy(buffer, s, pos);
    buffer[pos] = '\0';
    strcat(buffer, str);
    strcat(buffer, s + pos);
    strcpy(s, buffer);
}

// Кількість входжень s0 у s
int count_occurrences(const string& s, const string& s0) {
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find(s0, pos)) != string::npos) {
        ++count;
        pos += s0.length();
    }
    return count;
}

int main() {
    char s1[1000];
    string s_std;
    string s0;

    cout << "Введіть рядок S: ";
    cin.getline(s1, 1000);
    s_std = s1;

    cout << "Введіть рядок S0: ";
    getline(cin, s0);

    // Виклик власної функції insert
    insert_custom(s1, 3, s0.c_str());
    cout << "Власна insert: " << s1 << endl;

    // Виклик стандартної insert
    s_std.insert(3, s0);
    cout << "std::string insert: " << s_std << endl;

    // Завдання 2: підрахунок входжень
    cout << "Кількість входжень S0 в S: " << count_occurrences(s_std, s0) << endl;

    return 0;
}
