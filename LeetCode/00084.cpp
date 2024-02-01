class Solution {
public:
  int largestRectangleArea(vector<int> &dp) {
    stack<int> s;
    s.push(-1);
    int maxarea = 0;
    for (int i = 0; i < dp.size(); i++) {
      while (s.top() != -1 && dp[s.top()] >= dp[i]) {
        int curr_height = dp[s.top()];
        s.pop();
        int curr_width = i - s.top() - 1;
        maxarea = max(maxarea, curr_height * curr_width);
      }
      s.push(i);
    }
    while (s.top() != -1) {
      int curr_height = dp[s.top()];
      s.pop();
      int curr_width = dp.size() - s.top() - 1;
      maxarea = max(maxarea, curr_height * curr_width);
    }
    return maxarea;
  }
};

// Idea: Stack에 왼쪽부터 height가 오름차순이 되도록 index를 집어넣는다. (-1
// index에서는 높이가 0)
// 각 index마다 stack top이 현재 histogram 높이보다 높거나 같다면, stack top
// 높이를 기록해두고, stack에서 pop하고, 다음 stack top의 바로 다음 index부터
// 현재 index의 직전 index까지 width를 늘려서 rectangular 넓이를 계산한다. Q) 왜
// 이게 성립하는가?
//
//
//     --
//       --
//   --
//  -      -
//--
// (현재 stack에는 1, 2, 4, 8이 들어있다.)
// 1. index 9가 들어오면, stack top의 높이가 4이고 내 높이가 2이므로, stack
// top의 높이를 가지고 왼쪽으로 벌려서 얻을 수 있는 최대 넓이는 ((i - 1) -
// (stack_top + 1) + 1) * prev_stack_top_height = 4 * 4 = 16이다.
// 그 다음 stack top (index 4)의 높이가 3이고 내 높이가 2이므로, ((9 - 1) - (2 +
// 1) + 1) * 3 = 18이다.
// 마지막으로 stack top의 높이가 2이고 내 높이가 2이므로, ((9 - 1) - (1 + 1) +
// 1) * 2 = 14이다.
// 따라서 index 9의 직전에서 왼쪽으로 벌려서 얻을 수 있는 최대 넓이는 18이다.
// stack top의 높이가 curr index의 높이보다 크거나 같으므로, rectangular의
// 오른쪽 끝은 stack top이 되고, 왼쪽 끝은 prev stack top의 다음 index가 된다.
// stack 안에서 인접한 index끼리는, top에 가까운 쪽 index에서 출발하여 다음
// top에서 먼 쪽 index로 들어갈 때, 이 사이의 index의 높이는 항상 top에 가까운
// 쪽 index 높이보다 크거나 같다는 것이 만족된다.
