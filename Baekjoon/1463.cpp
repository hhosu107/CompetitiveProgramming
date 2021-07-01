#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct curr{
    int num_ops;
    int value;
    curr(int num_ops, int value): num_ops(num_ops), value(value) {}
};

int main(){
    int N;
    cin >> N;
    queue<curr> que = queue<curr>();
    que.push(curr(0, N));
    while(!que.empty()){
        curr top = que.front();
        if (top.value == 1) {
            cout << top.num_ops << endl;
            break;
        }
        que.pop();
        if (top.value % 3 == 0) que.push(curr(top.num_ops + 1, top.value / 3));
        if (top.value % 2 == 0) que.push(curr(top.num_ops + 1, top.value / 2));
        que.push(curr(top.num_ops + 1, top.value - 1));
    }
    return 0;
}