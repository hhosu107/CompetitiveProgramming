#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* C. List of N acts to take care of during the day.
 * Each act happens during a specified interval.
 * Assign each activity to one of the parents,
 * neither of them is responsible for two acts that overlap.
 * ending at t && starting at t means non-overlapping.
 * Find any schedule that does not require the same person to cover overlapping, or say that it is impossible.
 */

typedef struct baby{
  int index = 0;
  int start = 0;
  int end = 0;
  char assignee;
}baby;

bool startCompare(baby a, baby b){
  if (a.start == b.start){
    return a.end < b.end;
  } else return a.start < b.start;
}
bool indexCompare(baby a, baby b){
  return a.index < b.index;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, N;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N;
    vector<baby> acts = vector<baby>(N);
    int start, end;
    for(int i=0; i<N; i++){
      cin >> start >> end;
      acts[i] = {.index=i, .start=start, .end=end};
    }
    sort(acts.begin(), acts.end(), startCompare);
    int c=0, j=0;
    bool impossible = false;
    for(int i=0; i<N; i++){
      if(acts[i].start >= c){
        acts[i].assignee = 'C';
        c = acts[i].end;
      } else if(acts[i].start >= j){
        acts[i].assignee = 'J';
        j = acts[i].end;
      } else {
        impossible = true;
        break;
      }
    }
    cout << "Case #" << t << ": ";
    if(impossible) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      sort(acts.begin(), acts.end(), indexCompare);
      for (int i=0; i<N; i++){
        cout << acts[i].assignee;
      }
      cout << endl;
    }
  }
  return 0;
}
