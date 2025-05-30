
#include <iostream>
#include <fstream>
using namespace std;

const int N = 100;

void get_mas(const string& filename, char arr[N], int &n) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Не удалось открыть файл для чтения!" << endl;
        return;
    }
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }
    fin.close();
}

void show_mas(const string& filename, const char arr[N], int n) {
    ofstream fout(filename, ios::app);
    fout << "Відсортований масив: ";
    for (int i = 0; i < n; ++i)
        fout << arr[i] << " ";
    fout << endl;
    fout.close();
}

void bubbleSort(char arr[N], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    char arr[N];
    int n;
    string inputFile = "array_in_19.txt";
    string outputFile = "array_out_19.txt";

    get_mas(inputFile, arr, n);
    bubbleSort(arr, n);
    show_mas(outputFile, arr, n);

    cout << "Сортування завершено. Дані записані у " << outputFile << endl;
    return 0;
}
