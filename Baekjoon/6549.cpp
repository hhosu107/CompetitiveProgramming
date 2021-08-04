#include<iostream>
#include<stack>

using namespace std;

int main(){
  int n;
  while(1){
    cin >> n;
    if (n == 0) break;
    stack<int> heights = stack<int>(); //stack.top is the shortest one. when the larger one comes from the right, the shortest one leaves; and the sub area is stack.top * (i - stack.next_top - 1), since: between the location stack.top and stack.next_top, no one is longer than stack.top'th bar.
    vector<int> bars = vector<int>(n);
    for(int i=0; i<n; i++)
      cin >> bars[i];
    long long area = 0;
    for(int i=0; i<n; i++){
      while(!heights.empty() && bars[heights.top()] > bars[i]){
        long long height = bars[heights.top()];
        heights.pop();
        long long width = i;
        if (!heights.empty()) width = i - heights.top() - 1;
        if (width * height > area) area = width * height;
      }
      heights.push(i);
    }
    while(!heights.empty()){ // Here, only h'1> h'2> ...> h'k exist. From h'k, we want to extend it to the left/right side until it is blocked, but since all others that are right side of the h'k are already larger than h'k, we can extend to right infinitely, whereas the left side is blocked by h'k-1 which is located at loc(h'k-1). Thus the area is h'k * (n - loc(h'k-1) - 1).
      long long height = bars[heights.top()];
      heights.pop();
      long long width = n;
      if (!heights.empty()) width = n - heights.top() - 1;
      if (width * height > area) area = width * height;
    }
    cout << area << '\n';
  }
  return 0;
}
