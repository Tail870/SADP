#include <iostream>

using namespace std;

void inputArray(double**, int, int);
void shift(double**, int, int, int);
void printArray(double**, int, int);

int main(){
    setlocale(LC_ALL, "Russian");
    short int flag;
    do {
        int n, m, k;
        do {
            flag = false;
            cout << "Введите число n: ";
            cin >> n;
            if (n > 100 || n < 2) {
                flag = true;
                cout << "Повторите ввод\n";
            }
        }while (flag);
        do {
            flag = false;
            cout << "Введите число m: ";
            cin >> m;
            if (m > 50 || m < 2) {
                flag = true;
                cout << "Повторите ввод\n";
            }
        }while (flag);
        double** array = new double*[n];
        for (int i = 0 ; i < n; i++)
            array[i] = new double[m];
        inputArray(array, n, m);
        do {
            flag = false;
            cout << "Введите число сдвигов k: ";
            cin >> k;
            if (k < 1) {
                flag = true;
                cout << "Повторите ввод\n";
            }
        }while (flag);
        k %= m;
        cout << "Фактическое число сдвигов: " << k << " \n" << endl;
        printArray(array, n, m);
        shift(array, k, n, m);
        printArray(array, n, m);
        cout << "\nПовторить ввод (1/0): ";
        cin >> flag;
    }while(flag);
}


void inputArray(double** array, int n, int m){
    cout << "Ввод " << m << " столбцов и " << n << " строк массива (Ввод элементво по столбцам): ";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> array[j][i];
}

void shift(double** array, int k, int n, int m){
    for (int y = 0; y < k; y++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m-1; j++){
                double t = array[i][j];
                array[i][j] = array[i][j+1];
                array[i][j+1] = t;
            }
}

void printArray(double** array, int n, int m){
    cout << "Массив (Вывод элементов по строкам)";
        for (int i = 0; i < n; i++) {
            cout << endl;
            for (int j = 0; j < m; j++)
                cout << array[i][j] << " ";
        }
        cout << endl;
}
