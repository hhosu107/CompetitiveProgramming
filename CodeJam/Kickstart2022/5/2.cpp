#include <bits/stdc++.h>
using namespace std;

/* 2. N students. Prepare with peer helps.
Each student will pick a mentor among other students.
Each student will have exactly one mentor.
A person can be multiple people's mentor.
Student j can be a mentor of student i only if R_j <= 2 * R_i.
Each student wants to have the strongest possible mentor.
For each student, figure out highest possible rating of a mentor they cna pick.
1) print highest possible mentor's rating or print -1.
Sol) Use 'upper_bound' of 2 * rating for each student.
 */

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int N;
    cin >> N;
    vector<int> R(N);
    multiset<int> ratings;
    for (int i = 0; i < N; i++)
    {
      cin >> R[i];
      ratings.insert(R[i]);
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < N; i++)
    {
      auto it = ratings.upper_bound(2 * R[i]);
      it--;
      if (*it == R[i]) {
          if (it == ratings.begin()) {
              cout << "-1 ";
              continue;
          }
          it--;
      }
      cout << *it << " ";
    }
    cout << "\n";
  }
  return 0;
}
