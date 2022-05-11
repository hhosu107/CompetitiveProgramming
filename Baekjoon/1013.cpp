#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class fsm_node {
public:
  int id;
  int next_0;
  int next_1;
  bool successful;
  fsm_node() : id(0), next_0(0), next_1(0), successful(false) {}
  fsm_node(int id, int next_0, int next_1, bool successful) : id(id), next_0(next_0), next_1(next_1), successful(successful) {}
  int next(char bit) {
    if (bit == '0') {
      return next_0;
    } else return next_1;
  }
  void operator=(fsm_node& other) {
    id = other.id;
    next_0 = other.next_0;
    next_1 = other.next_1;
    successful = other.successful;
  }
};

/* FSM:
 * (100+1+ | 01)+.
 * We will start from empty string.
 * Empty string: state 0. next_0 = 1, next_1 = 2.
 * 1: state 1. next_0: fail state, next_1: 4 (this state is the success state).
 * 2: state 2. next_0: 3, next_1: fail state.
 * 3: state 3. next_0: 5, next_1: fail state.
 * 5: state 5. next_0: 5, next_1: 6 (this state is the success state).
 * 4: state 4 (success state). next_0: 1. next_1: 2.
 * 6: state 6 (success state). next_0: 1. next_1: 7.
 * 7: state 7 (success state). next_0: 8. next_1: 7.
 * 8: state 8. next_0: 5, next_1: 4.
 * 9: state 9 (fail state). next_0: 9, next_1: 9.
 */
int main () {
  vector<fsm_node> fsm = vector<fsm_node>();
  fsm.push_back(fsm_node(0, 1, 2, false));
  fsm.push_back(fsm_node(1, 9, 4, false));
  fsm.push_back(fsm_node(2, 3, 9, false));
  fsm.push_back(fsm_node(3, 5, 9, false));
  fsm.push_back(fsm_node(4, 1, 2, true));
  fsm.push_back(fsm_node(5, 5, 6, false));
  fsm.push_back(fsm_node(6, 1, 7, true));
  fsm.push_back(fsm_node(7, 8, 7, true));
  fsm.push_back(fsm_node(8, 5, 4, false));
  fsm.push_back(fsm_node(9, 9, 9, false));
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    int state = 0;
    for(int j=0; j<s.size(); j++) {
      state = fsm[state].next(s[j]);
    }
    cout << (fsm[state].successful ? "YES" : "NO") << endl;
  }
  return 0;
}
