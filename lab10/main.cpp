#include <iostream>

using namespace std;

unsigned long long int Fact(unsigned long long int arg){
    if (arg<=1)
        return arg;
    unsigned long long int out = arg*(arg-1); 
    arg = arg-2;
    if (arg>1)              
        out = out*Fact(arg);
    return out;
}

int main(){
    unsigned long long int arg;
    cout << "Введите число (предел - 65): ";
    cin >> arg;
    if (arg<=65)
        cout << Fact(arg) << endl; 
    else
        cout << "Места в переменной для вычисления не хватает." << endl;
    return 0;
}