#include "utils.h"
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

string scramble(const string& word) {
    if (word.size() <= 1) return word;
    string shuffled = word;
    random_device rd;
    mt19937 rng(rd());
    for (int i = 0; i < 20; ++i) {
        shuffle(shuffled.begin(), shuffled.end(), rng);
        if (shuffled != word) break;
    }
    return shuffled;
}

string ieconds(int sec) {
    int m = sec / 60;
    int s = sec % 60;
    string res;
    if (m > 0) res += to_string(m) + "m ";
    res += to_string(s) + "s";
    return res;
}