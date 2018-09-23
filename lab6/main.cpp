#include <iostream>
#include <libavutil/time.h>
#include <vector>

using namespace std;

void MassInput(vector<int> &arg){
    char menu;
    int s;
    cout << "Введите количество элементов: ";
    cin >> s;
    arg.resize(s);
    cout << "1. Случайное заполнение.\n";
    cout << "2. Ручное заполнение.\n";
    do {
        cin >> menu;
        switch (menu) {
            case '1': {
                srand(time(0)); 
                for (int i=0; i<arg.size(); i++) {
                    if ((rand()%2) == 1)
                        arg[i] = rand() % 101;    
                    else                              
                        arg[i] = -(rand() % 101);          
                }
                break;
            }
            case '2': {
                for (int i=0; i<arg.size(); i++)
                    cin >> arg[i];
                break;
            }
        }
    } while (menu != '1' && menu != '2');
    return;
}
void MassOutput(vector<int> &arg){
    if (arg.size()>0)
        for (int i=0; i<arg.size(); i++)
            cout << arg[i] << " ";
    else
        cout << "Массив не создан.\n";
    cout << endl;
    return;
}
int SumPositive(vector<int> &arg){
    int sum = 0;
    for (int i=0; i<arg.size(); i++)
        if (arg[i]>0)
            sum=sum+arg[i];
    return sum;
}
void AddAfterMax(vector<int> &arg){
    int addValue, maxID=0;
    cout << "Введите число для добавления: ";
    cin >> addValue;
    for (int i=1; i<arg.size(); i++)
        if (arg[maxID]<arg[i])
            maxID=i;
    arg.insert(arg.begin()+(maxID+1), addValue);
    return;
}

int main(){
    vector<int> dMass;
    char menu;
    do {
        cout << "1. Сгенерировать массив.\n";
        cout << "2. Показать массив.\n";
        cout << "3. Сумма положительных элементов.\n";
        cout << "4. Добавить элемент после максимального.\n";
        cout << "0. Выход.\n";
        cin >> menu;
        switch (menu) {
            case '1': {
                MassInput(dMass);
                break;
            }
            case '2': {
                MassOutput(dMass);
                break;
            }
            case '3': {
                cout << SumPositive(dMass) << endl;
                break;
            }
            case '4': {
                AddAfterMax(dMass);
                break;
            }
        }
    } while (menu != '0');

    return 0;
}