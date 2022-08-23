#include <bits/stdc++.h>
using namespace std;

vector<int> ranking;
vector<string> grid;

int dfs(int cell, int m, int found_cycles)
{
    if (ranking[cell])
    {
        return ranking[cell];
    }
    ranking[cell] = found_cycles; // mark current cell as not reserved by existing cycle
    int next_cell = -1;
    switch (grid[cell / m][cell % m])
    {
    case 'L':
        next_cell = cell - 1;
        break;
    case 'R':
        next_cell = cell + 1;
        break;
    case 'U':
        next_cell = cell - m;
        break;
    case 'D':
        next_cell = cell + m;
        break;
    default:
        next_cell = cell;
    }
    // If the cell goes into existing cycle, ranking[cell] will be decreased
    // and become less than found_cycles.
    return ranking[cell] = dfs(next_cell, m, found_cycles);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    grid = vector<string>(n);
    for (string &g : grid)
    {
        cin >> g;
    }
    ranking = vector<int>(n * m, 0);
    int next_cycle_num = 1;
    for (int i = 0; i < n * m; i++)
    {
        int x = dfs(i, m, next_cycle_num); // tries to find a new cycle
        if (x == next_cycle_num)
        {
            next_cycle_num++;
        }
    }
    cout << next_cycle_num - 1 << endl;
    return 0;
}