#include <iostream>
#include <vector>
using namespace std;

bool CharIsDivider(char &arg){ //Разделители: .,;-:'"?!()
    string dividers = " .,;-:\'\"?!()"; //Size == 12
    for (int i=0; i<12; i++)
        if (arg == dividers[i])
            return false;
    return true;
}
void WordDetector(string &text, vector<string> &words){
    int j = 0;
    bool flag = true;
    for (int i=0; i<text.size(); i++) {
        if (CharIsDivider(text[i])) {
            words[j] = words[j]+text[i];
            flag=false;
        }
        else {
            if (flag==false) {
                j++;
                words.resize(j+1);
            }
            flag=true;
        }
    }
    return;
}
void UniqueWords(vector <string> &words){
    int i=0;
    if (words.size()>1)
        do {
            int j=1;
            bool flag = true;
            do { 
                if (words[i]==words[j]) {
                    words.erase(words.begin()+j);
                    flag = false;
                } else 
                    j++;
            } while (j<words.size()-1);
                if (flag==false) {
                    words.erase(words.begin()+i);
                    flag = true;
                } else
                    i++;
        } while (i!=words.size()-1);
    return;
}
    
int main(){
    string text;
    vector <string> words (1);
    cout << "Введите ваш текст: ";
    getline(cin, text);
    WordDetector(text, words);        
    cout << "Уникальные слова:\n";
    UniqueWords(words);
    for (int i=0; i<words.size(); i++)
            cout << words[i]+" "; 
    cout << endl;      
    return 0;
}