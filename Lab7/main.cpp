#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void grid(int);
double integralFunction(double);
double* integral(double, double, int, double&);
void outPut(double*, int, double);

int main(){
    setlocale(LC_ALL, "Russian");
    bool flag;
    double* array;
    double b;
    cout << "Высчитывание определённого интеграла \"Методом правых прямоугольников\"" << endl;
    cout << "Введите параметр: ";
    do{
        flag = false;
        cin >> b;
        if (b <= 0 ){
            flag = true;
            cout << "Повторите ввод: ";
        }
    }while(flag);
    int n;
    cout << "Введите точность: ";

    do{
        flag = false;
        cin >> n;
        if (n <= 0 ){
            flag = true;
            cout << "Повторите ввод: ";
        }
    }while(flag);
    double sum = 0;
    array = integral(0.0, b, n, sum);
    outPut(array, n, sum);
    return 0;
}

void grid(int k){
    for (int i = 0; i < k; i++)
        cout << "_";
    cout << endl;
}

double integralFunction(double x){
    return x * exp(-x);
}

double* integral(double a, double b, int n, double& sum){
    double* temp = new double[n];
    double h = (b - a) / n;
    double xi = a + h;
    sum = integralFunction(xi);
    temp[0] = sum;
    for (int i = 1; i < n; i++){
        temp[i] = integralFunction(xi + h);
        xi += h;
        sum += temp[i];
    }
    sum *= h;
    return temp;
}

void outPut(double* array, int n, double sum){
    string str[2] = {"Номер столбца", "Пром. значение интеграла"};
    int k = str[0].size() + str[1].size() + 7;
    grid(k);
    cout << "| " << str[0] << " | " << str[1] <<  " |" << endl;
    grid(k);
    for (int i = 0; i < n; i++){
        cout << "| " << setw(str[0].size()) << i + 1 << " | " << setw(str[1].size()) << array[i] << " |" << endl;
        grid(k);
    }
    cout << "\nПолученный результат: " << sum;
}
