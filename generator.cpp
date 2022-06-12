#include "Generator.h"
void BackPack::ReadInput(string dir)
{
    ifstream input(dir);
    cout << "=== START READINPUT ===\n" << endl;
    if (input.is_open())
        cout << "Input file is open" << endl;
    else {
        cout << "Input file is not open" << endl;
        exit(0);
    }
    input >> N >> W;
    cout << "N = " << N << "\n" << "W = " << W << endl;
    vector<object> Res(N);
    for (int i = 0; i < N; i++) {
        input >> Res[i].name >> Res[i].number >> Res[i].cost;
        cout << Res[i].name << " " << Res[i].number << " " << Res[i].cost << endl;
    }
    Result = Res;
    cout << "\n=== END READINPUT ===" << endl;
}
bool BackPack::Algorithm(object combo, int index, bool print)
{
    if (index == N)
    {
            Combinations.push_back(combo);
            if (print == true && combo.name!="")
                cout << combo.name << " " << combo.number << " " << combo.cost << endl;
            return false;
    }
    if (combo.number + Result[index].number <= W) {
        object tmp;
        tmp = combo;
        tmp.name += " " + Result[index].name;
        tmp.number += Result[index].number;
        tmp.cost += Result[index].cost;
        Algorithm(tmp, index + 1, print);
    }
    Algorithm(combo, index + 1, print);
}
void BackPack::GoRecursive()
{
    cout << "\n=== OUTPUT OF COMBINATIONS ===\n" << endl;
    object combo;
    combo.name = "";
    combo.number = 0;
    combo.cost = 0;
    Algorithm(combo);
    maxcombo.name = "";
    maxcombo.number = 10;
    maxcombo.cost = 0;
    for (auto i : Combinations)
        if (i.cost >= maxcombo.cost)
        {
            maxcombo.name = i.name;
            maxcombo.number = i.number;
            maxcombo.cost = i.cost;
        }
    cout << "\nThe best option: " << maxcombo.name << " " << maxcombo.number << " " << maxcombo.cost << "\n" << endl;
    cout << "=== COMBINATIONS ARE DISPLAYED ===" << endl;
}
object BackPack::ReturnMax()
{
    return maxcombo;
}