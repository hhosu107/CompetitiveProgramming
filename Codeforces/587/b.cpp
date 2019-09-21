#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
struct acan{
  int id;
  int weight;
  acan(int _id, int _weight):
    id(_id), weight(_weight)
  {
  }
  bool operator>(const acan &acanObj) const {
    return weight > acanObj.weight;
  }
};

int main() {
  int n;
  cin >> n;
  vector<acan> cans = vector<acan>(n, acan(0, 0));
  for(int i=0; i<n; i++){
    int w;
    scanf("%d", &w);
    cans[i] = acan(i+1, w);
  }
  sort(cans.begin(), cans.end(), greater<acan>());
  int sum = 0;
  for(int i=0; i<n; i++){
    sum += i * cans[i].weight + 1;
  }
  printf("%d\n", sum);
  for(int i=0; i<n; i++){
    printf("%d ", cans[i].id);
  }
  printf("\n");
  return 0;
}
