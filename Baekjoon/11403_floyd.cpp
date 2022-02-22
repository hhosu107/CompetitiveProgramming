#include<iostream>

using namespace std;

int a[100][100];

/* Floyd warshall: if there is a path from i to j in the graph, then it must
 * be found within n steps of forwarding. Thus update each weight[i][j] with
 * min(weight[i][k] + weight[k][j]) for all k in V.
 * For vth loop, a[i][j] finds the shortest path that can be constructed up to v
 * different edges.*/
int main () {
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> a[i][j];
    }
  }
  for (int k=0; k<n; k++) {
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(a[i][k] > 0 && a[k][j] > 0) { // It doesn't update a[j][i] to find a cycle. Also it doesn't find the shortest path.
          a[i][j] = 1;
        }
      }
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if (a[i][j]) {
        cout << "1 ";
      } else cout << "0 ";
    }
    cout << endl;
  }
  return 0;
}
