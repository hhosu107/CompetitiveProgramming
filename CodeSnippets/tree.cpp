/* Binary search tree node
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename V>
class TreeNode {
  private:
    int sz;
  public:
    V val;
    TreeNode *l, *r, *parent;
    TreeNode(V v) {
      val = v;
      sz = 1;
    }
    void insert_in_order(V d) {
      if (d <= val) {
        if (l == nullptr) {
          set_left_child(new TreeNode(d));
        } else {
          l->insert_in_order(d);
        }
      } else {
        if (r == nullptr) {
          set_right_child(new TreeNode(d));
        } else {
          r->insert_in_order(d);
        }
      }
      sz += 1;
    }
    int size() {
      return this->sz;
    }
    TreeNode* find(V d) {
      if (d == val) {
        return this;
      } else if (d <= val) {
        return l != nullptr ? l->find(d) : nullptr;
      } else if (d > val) {
        return r != nullptr ? r->find(d) : nullptr;
      }
      return nullptr;
    }
    void set_left_child(TreeNode *node) {
      this->l = node;
      if (node != nullptr) {
        node->parent = this;
      }
    }
    void set_right_child(TreeNode *node) {
      this->r = node;
      if (node != nullptr) {
        node->parent = this;
      }
    }
};

int main () {
  TreeNode<int> *root = new TreeNode<int>(10);
  root->insert_in_order(5);
  root->insert_in_order(15);
  root->insert_in_order(12);
  root->insert_in_order(7);
  TreeNode<int> *root_find = root->find(7);
  if (root_find != nullptr) {
    cout << root_find->val << endl;
  }
  return 0;
}
