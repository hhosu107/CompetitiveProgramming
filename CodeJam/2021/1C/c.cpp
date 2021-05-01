#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

// C. Double or NOTing
// Starting non-neg int S, ending non-neg int E, with given binary representation.
// Transform S into E with the smallest number of operations.
// Double: add 0 at the end of the binary representation.
// NOT: flip 1 to 0/0 to 1 and drop the leading zeros.
// Ex) S = 10001_2, E = 111_2.
// 10001 -NOT> 01110(= 1110) -*2> 11100 -*2> 111000 -NOT> 000111(= 111)
// Small: S, E length <= 8 / Long: S, E length <= 100.
// First digit of S, E can be 0 only if the length of S, E are 1, 1, respectively.
// Sol) What should be the most efficient reverse of NOT operation?
// ex) To Generate X0..01..1(starting with 1), we have to reverse 1..1(!X)1..10..0, which can be generated from 1...1(!X)1...1 and k times of doubling operation.
// The problem is, we have to find the shortest path. We cannot get through strings like 111...000 or 111...1 artificially.
// Lemma: If the current string ends with 1, must we have to take "reverse NOT"?
// Lemma: If the current string ends with 0, Must we have to take "Double" until it gets identical with S or there are no trailing 0?
// 100001 -> 11110 -> 1111000 -> 111.
// Sol) We have to construct the former side of E first, and extend.
// 10001: We can obtain 1 at the end of the 10001. -> 1110 -> we can obtain 00 at the end of the 1110 -> reverse.
// i.e., Match the longest postfix of S and prefix of E. Pretending them, operate to get the rest part of E.
// 10001 / 111: 1 matches. To generate the rest, reverse, double twice, and reverse.
// What about 101000? -> 10111 -> 1000 -> 111.
// Lemma: To obtain X from 111...000...0X, we have to reverse X twice.
// Lemma 2: If a string is YX01..1, How can we obtain X?

int rev(vector<int> &a, int start, int end) {
  reverse(a.begin() + start, a.begin() + (end+1));
  return end - start + 1;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, N, C;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> N >> C;
    vector<int> a = vector<int>(N);
    for(int i=0; i<N; i++)
      a[i] = i + 1;
    bool flag = false;
    cout << "Case #" << t << ": ";
    do{
      vector<int> b = vector<int>(a.begin(), a.end());
      int score = 0;
      for(int i=0; i<N-1; i++){
        int index;
        int max = 999999999;
        for(int j=i; j<N; j++){
          if (b[j] < max){
            max = b[j];
            index = j;
          }
        }
        score += rev(b, i, index);
      }
      if (score == C) {
        for(int x : a){
          cout << x << " ";
        }
        cout << endl;
        flag = true;
        break;
      }
    }while(next_permutation(a.begin(), a.end()));
    if (!flag){
      cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}
