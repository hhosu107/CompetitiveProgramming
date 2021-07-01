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