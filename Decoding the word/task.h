#pragma once
#include <string>
#include <vector>

using namespace std;

struct Task {
    string word;
    string hint;
};

vector<Task> rtasks(const string& filename);