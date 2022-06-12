#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct obj {
    int number;
    int cost;
    string name;
};
class D_BackPack {
    int MaxN = 0;
    int MaxW = 0;
public:
    int N = 0, W = 0;
    vector<int> MAX{ MaxN,MaxW };
    string z;
    vector<obj> Result;
    vector<vector<int>> Combinations;
    D_BackPack() {}
    void ReadInput(string);
    void Dinamic();
    void find(int,int);
    void Print();
    vector<int> Max();
};