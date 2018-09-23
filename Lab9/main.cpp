#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void setN(int&);
void setM(int&);
template <typename T>
void inPut(T**, int, int);
template <typename T>
void sort(T**, int, int);
template <typename T>
void outPut(T**, int, int);

int main(){
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);
    int** arrayI;
    float** arrayF;
    char** arrayC;
    int n, m;
    setN(n);
    setM(m);
    int com;
    cout << "Какой тип данных для ввода вы хотите использовать: 0 - целое число | 1 - вещественное число | 2 - символьный тип: ";
    cin >> com;
    switch(com){
    case 0:
        arrayI = new int*[n];
        for (int i = 0; i < n; i++)
            arrayI[i] = new int[m];
        inPut(arrayI, n, m);
        outPut(arrayI, n, m);
        sort(arrayI, n, m);
        outPut(arrayI, n, m);
        break;
    case 1:
        arrayF = new float*[n];
        for (int i = 0; i < n; i++)
            arrayF[i] = new float[m];
        inPut(arrayF, n, m);
        outPut(arrayF, n, m);
        sort(arrayF, n, m);
        outPut(arrayF, n, m);
        break;
    case 2:
        arrayC = new char*[n];
        for (int i = 0; i < n; i++)
            arrayC[i] = new char[m];
        inPut(arrayC, n, m);
        outPut(arrayC, n, m);
        sort(arrayC, n, m);
        outPut(arrayC, n, m);
    }
    return 0;
}

void setN(int& n){
    bool flag;
    cout << "Введите количество строк матрицы: ";
    do{
        flag = false;
        cin >> n;
        if (n < 1 || n > 100){
            flag = true;
            cout << "Повторите ввод: ";
        }
    }while(flag);
}

void setM(int& m){
    bool flag;
    cout << "Введите количество строк матрицы: ";
    do{
        flag = false;
        cin >> m;
        if (m < 1 || m > 50){
            flag = true;
            cout << "Повторите ввод: ";
        }
    }while(flag);
}

template <typename T>
void inPut(T** array, int n, int m){
    cout << "Введите " << n << " строк(-и, -у) и " << m << " столбцов(-ец, -ца) (Ввод по строкам)" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> array[i][j];
}

template <typename T>
void sort(T** array, int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-1; j++)
            for (int k = 0; k < m-1-j; k++)
                if (array[i][k] > array[i][k+1])
                    swap(array[i][k], array[i][k+1]);
}

template <typename T>
void outPut(T** array, int n, int m){
    cout << "Матрица (Вывод по строкам)" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}
