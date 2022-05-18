#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
ll case_count[8000001];
/* Idea: https://www.geeksforgeeks.org/subset-sum-problem-osum-space/ 의
 * 아이디어를 참고.
 * 1. input의 각 정수가 최소 -100000, 최대 100000이고, 정수가 최대 40개 들어오므로,
 * 0 <= 정수들의 합 + 4000000 <= 8000000이다.
 * 그러므로 합의 갯수를 저장하는 8000001짜리 배열을 생성한다.
 * 2. 새로운 정수 c가 들어올 때 마다 다음을 수행한다:
 * 2.1. c < 0: 각각의 j에 대해, count[c + j]를 count[j]씩 증가시킨다. 이 때 j를
 * -c부터 8000000까지 증가시키며 적용한다. 실제로는 c + j가 4000000만큼 왜곡되어
 *  있는 값이므로 -4000000 - c부터 4000000까지의 case를 적용하는 것이다.
 * 2.2. c >= 0: 각 j에 대해, count[c + j]를 count[j]씩 증가시킨다. 이 때 j를
 * 8000000-c부터 0까지 감소시키며 적용한다. 실제로는 c + j가 4000000만큼
 * 왜곡되어 있는 값이므로 4000000 - c부터 -4000000까지의 case를 적용하는 것이다.
 * 2.3. 2.1 혹은 2.2를 거친 "다음", count[c + 4000000]을 1 증가시킨다. 2.1,
 * 2.2에서 하는 것은 현재 받은 c 이외의 다른 정수가 부분합에 관여했을 경우,
 * 새로운 정수 c가 들어왔을 때의 변화량을 적용하는 것이고, 2.3에서 하는 것은 c가
 * 부분합에 처음 관여할 때의 변화량을 적용하는 것이다.
 * 2.1과 2.2에서 서로 다른 방향으로 loop를 돌렸는데, 이렇게 해야 이전 step의
 * 변화량을 현재 step에 적용할 수 있다. 그렇게 하지 않으면 현재 step의 변화량이
 * 섞여들어갈 수 있다.
 * 3. count[target + 4000000]을 출력한다.
 */
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, target;
  cin >> n >> target;
  ll cur;
  for(int i=0; i<n; i++) {
    cin >> cur;
    if (cur<0) {
      for(int j=-cur; j<=8000000; j++)
        case_count[cur+j] += case_count[j];
    } else {
      for(int j=8000000-cur; j>=0; j--)
        case_count[cur+j] += case_count[j];
    }
    case_count[cur + 4000000]++;
  }
  cout << case_count[target + 4000000] << '\n';
  return 0;
}

