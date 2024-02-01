class Solution {
public:
  int trap(vector<int> &height) {
    int ans = 0, curr = 0;
    stack<int> st; // contains index of height
    while (curr < height.size()) {
      while (!st.empty() && height[curr] > height[st.top()]) {
        int top = st.top();
        st.pop();
        if (st.empty())
          break;
        int distance = curr - st.top() - 1;
        int bounded_height = min(height[curr], height[st.top()]) - height[top];
        ans += distance * bounded_height;
      }
      st.push(curr);
      curr += 1;
    }
    return ans;
  }
};
