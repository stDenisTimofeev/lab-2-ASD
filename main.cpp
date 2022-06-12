#include <iostream>
#include "generator.h"
#include "d_generator.h"
#include <fstream>
using namespace std;


// метод печатает что угодно, у чего есть возможность запускать цикл for (auto x: )
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
    input << "яблоко	4	20" << endl;;
    input << "арбуз 3	15" << endl;;
    input << "груша 5	30" << endl;;
    input << "абрикос	2	20" << endl;;
    input << "ананас	4	25" << endl;;
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