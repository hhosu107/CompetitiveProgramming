#include<bits/stdc++.h>
using namespace std;

int post_index;

int search(vector<int> &inorder, int n, int data) {
  int i = 0;
  for(i = 0; i < n; i++) {
    if(inorder[i] == data)
      return i;
  }
  return i;
}

void preorder(vector<int> &inorder, vector<int> &postorder, int l, int r, vector<int> &preorder_ans, int n) {
  // Treat postorder as the reversed preorder (Just flip the tree vertically),
  // and find inorder in the reversed way (first find on the right and then find
  // on the left).
  // Then we save preorder in the reversed way.
  if (l > r) return;
  int val = postorder[post_index];
  int inorder_index = search(inorder, n, postorder[post_index]);
  post_index--;
  preorder(inorder, postorder, inorder_index + 1, r, preorder_ans, n);
  preorder(inorder, postorder, l, inorder_index - 1, preorder_ans, n);
  preorder_ans.push_back(val);
}

int main () {
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vector<int> inorder(n);
  vector<int> postorder(n);
  for(auto &i: inorder) cin >> i;
  for(auto &i: postorder) cin >> i;
  vector<int> preorder_ans;
  post_index = n - 1;
  preorder(inorder, postorder, 0, n - 1, preorder_ans, n);
  for(int i=n-1; i>=0; i--)
    cout << preorder_ans[i] << ' ';
  cout << '\n';
  return 0;
}
