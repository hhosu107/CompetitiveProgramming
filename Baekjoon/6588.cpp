#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> primes;
int main(){
  ios::sync_with_stdio(false);
  primes = vector<int>();
  primes.push_back(2);
  for(int i=3; i<1000000; i+=2){
    bool flag = false;
    for(int j=0; j<primes.size() && primes[j] * primes[j] <= i && flag == false; j++){
      if(i % primes[j] == 0) flag = true;
    }
    if(!flag) primes.push_back(i);
  }
  // for(int p : primes)
  //   cout << p << ' ';
  int key;
  scanf("%d", &key);
  while(key != 0){
    int up = upper_bound(primes.begin(), primes.end(), key) - primes.begin();
    int down = 0;
    while(primes[down] + primes[up] != key){
      if(primes[down] + primes[up] > key) up--;
      else down++;
    }
    printf("%d = %d + %d\n", key, primes[down], primes[up]);
    /* vector<int>::iterator it = primes.begin();
    vector<int>::reverse_iterator rit = primes.rbegin();
    while(*it + *rit != key){
      if((*it + *rit) > key) rit++;
      else it++;
    }
    printf("%d = %d + %d\n", key, *it, *rit); */
    scanf("%d", &key);
  }
  return 0;
}
