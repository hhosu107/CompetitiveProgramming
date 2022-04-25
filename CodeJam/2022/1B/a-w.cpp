#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

// A. Reversort (C. Reversort Engineering is identical to this except for the last paragraph.)
// Reversort: Sort a distinct integers in increasing order, based on the 'reverse' operation.
// Each application of this operation reverses the order of some contiguous part of the list.
// Reversort(L):
//     for i := 1 to length(L) - 1:
//         j := position with the minimum value in L between i and and length(L)
//         reserve(L[i..j])
// After i-1 iterations, positions 1~i-1 of the list contain the i-1 smallest elements of L, in increasing order.
// During the i-th iteration, the process reverses the sublist going from the i-th position to the current position to the current position of the i-th minimum element.
// ex) [4, 2, 1, 3] -(i=1, j=3)> [1, 2, 4, 3] -(i=2, j=2)> [1, 2, 4, 3] -(i=3, j=4)> [1, 2, 3, 4]
// Most expensive part: Reverse operation.
// Measure for the cost of each iteration = length(L[i..j]) == j - i + 1.
// Compute the cost of executing Reversort.
// T <= 100, N <= 100, 1<=L_i<=N, L_i != L_j.

int ceilIndex(vector<int> &arr, int l, int r, int x) {
  if (l > r)
    return -1;
  int mid = l + (r - l) / 2;
  if (arr[mid] == x) {
    if (mid + 1 <= r && arr[mid + 1] == x) {
      return ceilIndex(arr, mid + 1, r, x);
    }
    return mid;
  }
  if (x < arr[mid])
    return ceilIndex(arr, l, mid - 1, x);
  return ceilIndex(arr, mid + 1, r, x);
}

int get_longest_bitonic_subsequence_len(vector<int> &arr, int n) {
  if (n == 0) return 0;
  vector<int> increasing_part(n, 0);
  vector<int> increasing_part_len(n, 0);
  vector<int> decreasing_part(n, 0);
  vector<int> decreasing_part_len(n, 0);

  int next_inc = 1;
  increasing_part[0] = arr[0];
  increasing_part_len[0] = 0;
  for(int i=1; i<n; i++) {
    if (arr[i] < increasing_part[0]) { // smallest
      increasing_part[0] = arr[i]; // start from current element
      increasing_part_len[i] = 0;
    } else if (arr[i] > increasing_part[next_inc - 1]) { // current largest
      increasing_part[next_inc++] = arr[i];
      increasing_part_len[i] = next_inc - 1;
    } else { // current element has to find the position to insert
      int pos = ceilIndex(increasing_part, -1, next_inc - 1, arr[i]);
      increasing_part[pos] = arr[i];
      increasing_part_len[i] = ceilIndex(increasing_part, -1, next_inc - 1, arr[i]);
    }
  }

  next_inc = 1;
  vector<int> rev_arr = arr;
  reverse(rev_arr.begin(), rev_arr.end());
  decreasing_part[0] = rev_arr[0];
  decreasing_part_len[0] = 0;
  for(int i=1; i<n; i++) {
    if (rev_arr[i] < decreasing_part[0]) {
      decreasing_part[0] = rev_arr[i];
      decreasing_part_len[i] = 0;
    } else if (rev_arr[i] > decreasing_part[next_inc - 1]) {
      decreasing_part[next_inc++] = rev_arr[i];
      decreasing_part_len[i] = next_inc - 1;
    } else {
      int pos = ceilIndex(decreasing_part, -1, next_inc - 1, rev_arr[i]);
      decreasing_part[pos] = rev_arr[i];
      decreasing_part_len[i] = ceilIndex(decreasing_part, -1, next_inc - 1, rev_arr[i]);
    }
  }
  reverse(decreasing_part_len.begin(), decreasing_part_len.end());
  int max_len = 0;
  for(int i=0; i<n; i++) {
    max_len = max(max_len, increasing_part_len[i] + decreasing_part_len[i] + 1);
  }
  return max_len;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T, N;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> N;
    vector<int> arr(N, 0);
    for(auto &a: arr)
      cin >> a;
    cout << "Case #" << t << ": ";
    int max_len = get_longest_bitonic_subsequence_len(arr, N);
    cout << max_len << '\n';
  }
  return 0;
}
