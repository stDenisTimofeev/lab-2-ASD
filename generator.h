#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct object {
    int number;
    int cost;
    string name;
};
class BackPack {
public:
    int N = 0, W = 0;
    object maxcombo;
    vector<object> Result;
    vector<object> Combinations;
    BackPack() {}
    void ReadInput(string);
    bool Algorithm(object combo, int index = 0, bool prinfFlag = true);
    void GoRecursive();
    object ReturnMax();
};