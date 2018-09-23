#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

double check();

int main(){
    setlocale(LC_ALL, "Russian");
    short int k;
        do {
            double *input = new double[2];
            double *point = new double[2];
            cout << "Введите радуис окружности: ";
            input[0] = check();
            cout << "Введите сторону квадрата: ";
            input[1] = check();
            cout << "Введите координату X: ";
            cin >> point[0];
            cout << "Введите координату Y: ";
            cin >> point[1];
            double temp[] = {point[0] * point[0] + point[1] * point[1], input[1] / 2};
            if (temp[0] > input[0] * input[0] && abs(point[0]) <= temp[1] && abs(point[1]) <= temp[1])
                cout << "Точка с координатами (" << point[0] << ";" << point[1] << ") входит в указанную область";
            else
                cout << "Точка с координатами (" << point[0] << ";" << point[1] << ") не входит в указанную область";
            cout << "\nПовторить ввод (1/0): ";
            cin >> k;
        }while(k);
}

double check(){
    double str;
    bool flag;
    do{
        flag = false;
        cin >> str;
        if (str <= 0){
            flag = true;
            cout << "Повторите ввод: ";
        }
    }while(flag);
    return str;
}
