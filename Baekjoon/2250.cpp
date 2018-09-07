/* P 2250: height and width of the tree
 * 1. 이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
 * 2. 한 열에는 한 노드만 존재한다.
 * 3. 임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
 * 4. 노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.
 * Then print the height which is the widest level.
 * Sol) See the invariance: Note that, if a node has only one children, placing that children at the leftmost/rightmost column as it can makes the width smallest.
 * Idea: For each node, record how much the children exist left/right of them. For the left child, its right nodes are the count of the distance between its parent; for the right child, its left nodes are the count of the distance between its parent. Recording will be done by dfs.
 * How we can measure the distance between non-direct siblings? Go up to the tree and accumulate the above pattern.
 * Or, maybe I want to find the leftmost/rightmost nodes for each level, not by full-search. -> Cannot. Since following the leftmost might not cover all level.
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[10001]; // contains parent
int link[10001][2]; // contains left/right index of the node
int childs[10001][3]; // 0th: height, 1st: # of left childs, 2nd: # of right childs
int distIdx[10001]; // containing distance from the center
int widthIdx[10001][2]; // 0th: contains leftmost distance from the root of the level, 1th: contains rightmost distance from the root of the level

void settle(int n){
  if(parent[n] != -1){
    childs[n][0] = childs[parent[n]][0] + 1;
  }
  if(link[n][0] != -1){
    settle(link[n][0]);
    childs[n][1] = childs[link[n][0]][1] + childs[link[n][0]][2] + 1;
  }
  if(link[n][1] != -1){
    settle(link[n][1]);
    childs[n][2] = childs[link[n][1]][1] + childs[link[n][1]][2] + 1;
  }
  return;
}

void distance(int node, int direction, int isLeft){
  // level = childs[node][0], direction = left child (1) of the parent or right child (2) of the parent,
  // isleft = 1 if finding leftmost, 2 if finding rightmost
  if(node == -1) return; // Just filter the non-existing case by this.
  distIdx[node] = 0;
  // Insert the absolute distance from the root.
  if(direction != 0){
    // distance between the direct parent is defined by the other side of childs.
    distIdx[node] = (childs[node][3 - direction] + 1) * (direction == isLeft ? 1 : -1) + distIdx[parent[node]];
  }
  // Update the maximum absolute distance from the root.
  if(isLeft != 0){
    if(widthIdx[childs[node][0]][isLeft-1] < distIdx[node]){
      widthIdx[childs[node][0]][isLeft-1] = distIdx[node];
    }
  }
  // Go left with initial direction = 1, isLeft = 1 and right with direction = 2, isLeft = 2 if it is the root
  if(isLeft == 0){
    distance(link[node][0], 1, 1);
    distance(link[node][1], 2, 2);
  }
  else{
    distance(link[node][0], 1, isLeft);
    distance(link[node][1], 2, isLeft);
  }
}
int main(){
  int N, index;
  cin >> N;
  for(int i=1; i<=N; i++)
    parent[i] = -1;
  for(int i=1; i<=N; i++){
    scanf("%d", &index);
    scanf("%d %d", &link[index][0], &link[index][1]);
    if(link[index][0] != -1){
      parent[link[index][0]] = index;
    }
    if(link[index][1] != -1){
      parent[link[index][1]] = index;
    }
  }
  // Then only one element is not a child of others.
  // Actually there is more efficient algorithm: pick any pivot and find the oldest ancestor, which is O(log N) in average, but it doesn't affect on the speed of all.
  int root = 0;
  for(int i=1; i<=N; i++){
    if(parent[i] == -1){
      root = i;
      break;
    }
  }
  childs[root][0] = 1;
  settle(root);
  distance(root, 0, 0);
  int rep = 0, width = 0;
  for(int i=1; i<=10000; i++){
    if(width < widthIdx[i][0] + widthIdx[i][1] + 1){
      width = widthIdx[i][0] + widthIdx[i][1] + 1;
      rep = i;
    }
  }
  printf("%d %d\n", rep, width);
  return 0;
}
