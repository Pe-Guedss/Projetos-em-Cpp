#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(){
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    int vogais_cont[] = {0, 0, 0, 0, 0};
    string word;
    
    cin >> word;
    for (int i = 0; i < word.size(); i++){
        for (int j = 0; j < 5; j++){
            if (word[i] == vogais[j])
                vogais_cont[j]++;
        }
    }
    for (int i = 0; i < 5; i++){
        if (vogais_cont[i] > 0)
            cout << vogais[i] << " " << vogais_cont[i] << endl;
    }
}