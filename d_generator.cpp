#include "D_Generator.h"
void D_BackPack::ReadInput(string dir)
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
    vector<obj> Res(N);
    for (int i = 0; i < N; i++) {
        input >> Res[i].name >> Res[i].number >> Res[i].cost;
        cout << Res[i].name << " " << Res[i].number << " " << Res[i].cost << endl;
    }
    Result = Res;
    cout << "\n=== END READINPUT ===" << endl;
}
void D_BackPack::Dinamic()
{
    vector<int> Q;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
            Q.push_back(0);
        Combinations.push_back(Q);
    }
    for (int k = 1; k <= N; k++)
    {
        for (int s = 1; s <= W; s++)
        {
            Combinations[k][s] = Combinations[k - 1][s];
            if (s >= Result[k - 1].number)
                Combinations[k][s] = max(Combinations[k][s], Combinations[k][s - Result[k - 1].number] + Result[k - 1].cost);//
        }
    }
}
void D_BackPack::find(int n, int w)
{
    if (Combinations[n][w] == 0)
        return;
    if (Combinations[n - 1][w] == Combinations[n][w])
        find(n - 1, w);
    else {
        MAX[0] += Result[n - 1].number;
        MAX[1] += Result[n - 1].cost;
        z += Result[n - 1].name + " ";
        find(n, w - Result[n - 1].number);//
    }
}
void D_BackPack::Print() 
{
    cout << "\n=== OUTPUT OF COMBINATIONS ===\n" << endl;
    for (int i = 0; i <= N; i++)
    {
        cout << "K = " << i << " : ";
        for (int j = 0; j <= W; j++)
        {
            cout << Combinations[i][j] << " ";
        }
        cout << endl;
    }
    find(N, W);
    cout << "\nThe best option: " << z << "   " << MAX[0] << " " << MAX[1] << " " << endl;
    cout << "\n=== COMBINATIONS ARE DISPLAYED ===\n" << endl;
}
vector<int> D_BackPack::Max()
{
    return MAX;
}