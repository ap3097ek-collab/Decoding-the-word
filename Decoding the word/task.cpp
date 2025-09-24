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
            cerr << "�� ������� ������� ����: " << filename << endl;
            return tasks;
        }
        fout << "���|���� ���� � ���� � �������� �������� �����\n";
        fout << "�����|������, ��� �� ���� ����� � ���� � ���������\n";
        fout << "�������|�����, � ������ ��������� � ����� ����������\n";
        fout << "���|�� ��������� ���� ���� ���������� ���� ������\n";
        fout << "���|������ �����, �� ������������ ��������\n";
        fout.close();

        cout << "������ ���� " << filename
            << " � ��������� ����. ��������� ���� ��� ���.\n";
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