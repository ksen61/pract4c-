#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>
using namespace std;

void reverse(string& word) {
    reverse(word.begin(), word.end());
    cout << "Перевернутое слово: " << word << endl;
}

void removeVowels(string& word) {
    word.erase(remove_if(word.begin(), word.end(), [](char c) {
        return string("аеёиоуэюяАЕЁИОУЭЮЯ").find(c) != string::npos;
        }), word.end());
    cout << "Слово без гласных: " << word << endl;
}

void removeConsonants(string& word) {
    word.erase(remove_if(word.begin(), word.end(), [](char c) {
        return string("йцкнгшщхзъфвпрлджчсмтбЙЦКНГШЩЗХЪФВПРЛДЖЧСМТЬБ").find(c) != string::npos;
        }), word.end());
    cout << "Слово без согласных: " << word << endl;
}

void shuffle(string& word) {
    random_device rd;
    mt19937 g(rd());
    shuffle(word.begin(), word.end(), g);
    cout << "Перемешанное слово: " << word << endl;
}

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    string word;
    int choice;

    while (true) {
        cout << "Введите слово: ";
        cin >> word;

        cout << "\nМеню:" << endl;
        cout << "1. Перевернуть слово" << endl;
        cout << "2. Вывести слово без гласных" << endl;
        cout << "3. Вывести слово без согласных" << endl;
        cout << "4. Перемешать буквы в слове" << endl;
        cout << "5. Выход" << endl;
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            reverse(word);
            break;
        case 2:
            removeVowels(word);
            break;
        case 3:
            removeConsonants(word);
            break;
        case 4:
            shuffle(word);
            break;
        case 5:
            cout << "До свидания!" << endl;
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}
