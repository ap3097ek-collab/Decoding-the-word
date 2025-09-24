#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include "task.h"
#include "utils.h"

using namespace std;

int main() {
    system("chcp 1251>null");

    const string filename = "tasks.txt";
    const int penalty = 2;

    auto tasks = rtasks(filename);
    if (tasks.empty()) return 0; 

    
    random_device rd;
    mt19937 rng(rd());
    shuffle(tasks.begin(), tasks.end(), rng);

    int totalTime = 0;
    int solved = 0;

    cout << "=== Гра: Розшифруй слово ===\n";
    cout << "Команды: hint (+2 мин), skip, exit\n\n";

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "--- Слово " << (i + 1) << " из " << tasks.size() << " ---\n";
        string scrambled = scramble(tasks[i].word);
        cout << "Зашифроване слово: " << scrambled << "\n";

        time_t start = time(nullptr);
        bool hintUsed = false;

        while (true) {
            cout << "Ваш вариант: ";
            string input;
            getline(cin, input);
            if (input.empty()) continue;

            if (input == "exit") {
                cout << "\nВгадано: " << solved
                    << " слов, время: " << ieconds(totalTime) << endl;
                return 0;
            }
            if (input == "skip") {
                cout << "Пропущено слово: " << tasks[i].word << "\n\n";
                break;
            }
            if (input == "hint") {
                if (!hintUsed) {
                    cout << "Підказка: " << tasks[i].hint << endl;
                    hintUsed = true;
                }
                else {
                    cout << "Підказка вже була!\n";
                }
                continue;
            }

            string guess = input;
            string correct = tasks[i].word;

            if (guess == correct) {
                int elapsed = static_cast<int>(difftime(time(nullptr), start));
                if (hintUsed) elapsed += penalty * 60;
                totalTime += elapsed;
                solved++;
                cout << " Вірно! Час: " << ieconds(elapsed) << "\n\n";
                break;
            }
            else {
                cout << " Невірно.\n";
            }
        }
    }

    cout << "\n--- Підсумок ---\n";
    cout << "Вгадано: " << solved << " з " << tasks.size() << endl;
    cout << "Загальний час: " << ieconds(totalTime) << endl;
    return 0;
}