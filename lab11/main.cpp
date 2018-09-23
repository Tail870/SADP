#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma pack (push, 1)
struct bus{
    int number = 0;
    char endTown[25] = "";
    char time[25] = "";
    int cost = 0;
};
#pragma pack (pop)

bool compare_by_number(const bus& a, const bus& b) {
    return a.number > b.number;
}

bus InData(string arg){
    bus bus;
    int i,j;
    string temp = "";
        for (i=0; i<arg.size(); i++) {
            if (arg[i]!=' ')
                temp = temp+arg[i];
            else
                break;
        }
        bus.number = stoi(temp);
        temp="";
        for (j=i+1; j<arg.size(); j++) {
            if (arg[j]!=' ')
                temp = temp+arg[j];
            else
                break;       
        }
        for (int i=0; i<temp.size(); i++)
            bus.endTown[i]=temp[i];
        temp="";
        for (i=j+1; i<arg.size(); i++) {
            if (arg[i]!=' ')
                temp = temp+arg[i];
            else
                break;
        }
        for (int i=0; i<temp.size(); i++)
            bus.time[i]=temp[i];
        temp="";
        for (j=i+1; j<arg.size(); j++) {
            if (arg[j]!=' ')
                temp = temp+arg[j];
            else
                break;
        }
        bus.cost = stoi(temp);
    return bus;
}

void FileRead(vector <bus> &bus){
    ifstream file("./data.txt");
    string line;
    while (!file.eof()) {
        getline(file, line);
        bus.push_back(InData(line));
    }
    file.close();
    cout << "Прочитано.\n";
    return;
}

string Search(vector<bus> &bus, int &search){
	int i = -1;
	int low = 0, high = bus.size(), mid;
	while (low < high) {
		mid = (low + high)/2;
		if (search == bus[mid].number) {
            i = mid;
			break;
		} else {
			if (search <= bus[mid].number) {
				high = mid;
	    	} else {
				low = mid + 1;
				}
			}
		}
        if (i<0)
        return "Не найдено...";
	return "Найден маршрут №"+to_string(bus[i].number)+
                 ":\nГород: "+bus[i].endTown+
                  "; Время: "+bus[i].time+
              "; Стоимость: "+to_string(bus[i].cost);
}

void BinWrite(vector<bus> &bus){
    ofstream file("./data.bin", ios::binary|ios::out);
    for (int i=0; i<bus.size(); i++)
        file.write((char*)&bus[i], sizeof(bus[i]));
    file.close();
    cout << "Записано.\n";
    return;
}

void BinRead(vector<bus> &bus){
    ifstream file("./data.bin", ios::binary|ios::in);
    struct bus temp;
    while (file.read((char*)&temp, sizeof(temp)))
        bus.push_back(temp);
    file.close();
    cout << "Прочитано.\n";
    return;
}

int main(){
    vector <bus> bus;
    char menu;
    cout << "1. Ввод данных из текстового файла.\n";
    cout << "2. Сортировка.\n";
    cout << "3. Вывод на экран.\n";
    cout << "4. Поиск.\n";
    cout << "5. Запись в двоичный файл.\n";
    cout << "6. Чтение из двоичного файла.\n";
    cout << "0. Выход.\n";
    do {
        cin >> menu;
        switch (menu) {
            case '1':{
                FileRead(bus);
                break;
            }
            case '2':{
                sort(bus.rbegin(), bus.rend(), compare_by_number);
                cout << "Отсортированно.\n";
                break;
            }
            case '3':{
                for (int i=0; i<bus.size(); i++) {
                    cout <<"Маршрут: "    << bus[i].number 
                         <<"; Город: "    << bus[i].endTown 
                         <<"; Время: "    << bus[i].time 
                         <<"; Стоимость: "<< bus[i].cost << endl;
                }
                break;
            }
            case '4':{
                sort(bus.rbegin(), bus.rend(), compare_by_number);
                cout << "Что ищем? Введите номер маршрута: ";
                int search;
                cin >> search;
                cout << (Search(bus, search)) << endl;
                break;
            }
            case '5':{
                BinWrite(bus);           
                break;
            }
            case '6':{
                BinRead(bus);
                break;
            }
        }
    } while (menu!= '0' );
    return 0;
}