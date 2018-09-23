#include <iostream>
#include <cmath>

using namespace std;

void inputArray(double*, int);
double* search(double*, double, int);

int main(){
    setlocale(LC_ALL, "Russian");
    short int k;
        do {
            int n;
            double x;
            do {
                k = false;
                cout << "Введите число n: ";
                cin >> n;
                if (n > 100 || n < 1) {
                    k = true;
                    cout << "Повторите ввод\n";
                }
            }while (k);
            double* array = new double[n];
            inputArray(array, n);
            cout << "Введите число x (отрицательное число будет преобразовано в положительное по модулю): ";
            cin >> x;
            x = abs(x);
            double* nums = new double[1];
            if (n > 1) {
                nums = search(array, x, n);
                cout << "\nЧисла: " << nums[0] << " и " << nums[1] <<
                        "\nРазность: " << abs(nums[0] - nums[1]) << " | Число x : " << x;
            }
            else {
                nums[0] = array[0];
                cout << "\nЧисло: " << nums[0];
            }
            cout << "\nПовторить ввод (1/0): ";
            cin >> k;
        }while(k);
}

void inputArray(double* array, int n){
    cout << "Ввод " << n << " элементов массива: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];
}

double* search(double* array, double x, int n){
    double* nums = new double[2];
    nums[0] = 0;
    nums[1] = 0;
    double* differ = new double[1];
    bool flag = false;
    for (int i = 0; i < n -1; i++)
        for (int j = i+1; j < n; j++)
            if (!flag){
                flag = true;
                nums[0] = array[i];
                nums[1] = array[j];
                differ[0] = abs(nums[0] - nums[1]);
            }
            else{
                double t  = abs(array[i] - array[j]);
                if (abs(t-x) < abs(differ[0]-x)) {
                    differ[0] = t;
                    nums[0] = array[i];
                    nums[1] = array[j];
                }
            }
    return nums;
}
