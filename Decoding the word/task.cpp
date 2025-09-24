#include "task.h"
#include <fstream>
#include <iostream>

using namespace std;

vector<Task> rtasks(const string& filename) {
    vector<Task> tasks;
    ifstream fin(filename);

    if (!fin) {
        system("chcp 1251>null");

        ofstream fout(filename);
        if (!fout) {
            cerr << "Не удалось создать файл: " << filename << endl;
            return tasks;
        }
        fout << "дощ|Воно падає з неба і допомагає рослинам рости\n";
        fout << "пінгвін|Пташка, яка не може літати і живе в Антарктиді\n";
        fout << "ромашка|Квітка, з жовтою серединою і білими пелюстками\n";
        fout << "їжа|За допомогою чого люди поповнюють свою енергію\n";
        fout << "мед|Золота рідина, що виробляється бджолами\n";
        fout.close();

        cout << "Создан файл " << filename
            << " с примерами слов. Запустите игру ещё раз.\n";
        return tasks;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        size_t pos = line.find('|');
        if (pos == string::npos) continue;
        Task t;
        t.word = line.substr(0, pos);
        t.hint = line.substr(pos + 1);
        tasks.push_back(t);
    }
    return tasks;
}