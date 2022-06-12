#include <iostream>
#include "generator.h"
#include "d_generator.h"
#include <fstream>
using namespace std;


// ����� �������� ��� ������, � ���� ���� ����������� ��������� ���� for (auto x: )
//template <class T>
//void Print(T someList) {
//   for (auto &x: someList) cout<<" "<<x;
//   cout<<endl;
//}

int main() {
    setlocale(LC_ALL, "Russian");
    ofstream input;
    input.open("input.txt");
    input << "5" << endl;
    input << "10" << endl;;
    input << "������	4	20" << endl;;
    input << "����� 3	15" << endl;;
    input << "����� 5	30" << endl;;
    input << "�������	2	20" << endl;;
    input << "������	4	25" << endl;;
    BackPack a;
    a.ReadInput("input.txt");
    a.GoRecursive();
    cout << "\nDINAMIC\n" << endl;
    D_BackPack d;
    d.ReadInput("input.txt");
    d.Dinamic();
    d.Print();
    return 0;
}