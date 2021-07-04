#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](auto &i1,auto &i2) -> bool {return i1[0] - i1[1] < i2[0] - i2[1];});
        int sum=0;
        for(int i=0;i<costs.size()/2;i++){
            sum += costs[i][0] + costs[costs.size()-1-i][1];
        }
        return sum;
    }
};

// sort(container.begin(), container.end()) works with < operator, which makes smallest element goes first.
// sort(container.rbegin(), container.rend()) makes the descending order.

struct triplet {
    vector<int> x = vector<int>(0, 3);
    
    triplet(vector<int> y = vector<int>(3, 0)): x(y) {}
    
    void operator=(const triplet& a) {
        x[0] = a.x[0];
        x[1] = a.x[1];
        x[2] = a.x[2];
    }
    
    bool operator<(const triplet& a) const { // Needed for sort
        if(x[0] == a.x[0] && x[1] == a.x[1]) {
            return x[2] < a.x[2];
        } else if (x[0] == a.x[0]) {
            return x[1] < a.x[1];
        } return x[0] < a.x[0];
    }
    
    bool operator==(const triplet& a) const {
        return (x[0] == a.x[0] && x[1] == a.x[1] && x[2] == a.x[2]);
    }
};
