#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

/**
    \brief Given a complete, undirected, weighted graph in the form of an adjacency matrix,
           returns the smallest tour that visits all nodes and starts and ends at the same
           node. This dynamic programming solution runs in O(n * 2^n).
    \return the minimum cost to complete the tour
*/
int tsp(const vector<vector<long long int>>& cities, int init, int pos, int visited, vector<vector<long long int>>& state)
{
    if(visited == ((1 << cities.size()) - 1))
        return cities[pos][init]; // return to starting city

    if(state[pos][visited] != INT_MAX)
        return state[pos][visited];

    for(int i = 0; i < cities.size(); ++i)
    {
        // can't visit ourselves unless we're ending & skip if already visited
        if(i == pos || (visited & (1 << i)))
            continue;

        long long int distance = cities[pos][i] + tsp(cities, init, i, visited | (1 << i), state);
        if(distance < state[pos][visited])
            state[pos][visited] = distance;
    }

    return state[pos][visited];
}

int main()
{
  vector<vector<long long int>> cities;
  int n;
  cin >> n;
  cities = vector<vector<long long int>>(n, vector<long long int>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> cities[i][j];
      if(cities[i][j] == 0) cities[i][j] = INT_MAX;
    }
  }

  vector<vector<long long int>> state(cities.size());
  for(auto& neighbors : state)
    neighbors = vector<long long int>((1 << cities.size()) - 1, INT_MAX);
  long long int length = INT_MAX;
  for(int i=0; i<n; i++){
    int visited = 1 << i;
    long long int cand = tsp(cities, i, i, visited, state);
    length = (length > cand ? cand : length);
  }
  cout << length << endl;

    return 0;
}
