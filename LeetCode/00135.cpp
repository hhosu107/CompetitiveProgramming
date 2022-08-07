class Solution {
public:
    int candy(vector<int>& ratings) {
        // Brute force: track any changes
        /*
        vector<int> candies(ratings.size(), 1);
        bool hasChanged = true;
        while(hasChanged) {
            hasChanged = false;
            for(int i=0; i<ratings.size(); i++) {
                // invariant crashed: 인접 cell rating보다 높은데 더 많은 candy를 받지 못하는 상황
                if (i != ratings.size() - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    hasChanged = true;
                }
                // 양 방향으로 만족 못 할 수 있음
                if (i != 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    hasChanged = true;
                }
            }
        }
        int sum = 0;
        for (int candy: candies)
            sum += candy;
        return sum;
        */
        // Left to right, right to left, increase by 1 with any crash of invariant.
        /*
         * In this approach, we make use of two 1-d arrays left2right and right2left. The left2right array is used to store the number of candies required by the current student taking care of the distribution relative to the left neighbors only. i.e. Assuming the distribution rule is: The student with a higher rating than their left neighbor should always get more candies than its left neighbor. Similarly, the right2left array is used to store the number of candies required by the current student taking care of the distribution relative to the right neighbors only. i.e. Assuming the distribution rule to be: The student with a higher rating than their right neighbor should always get more candies than their right neighbor. To do so, firstly we assign 1 candy to each student in both the left2right and right2left arrays. Then, we traverse the array from left-to-right and whenever the current element's ratings is larger than the left neighbor we update the current element's candies in the left2right array as left2right[i] = left2right[i-1] + 1, since the current element's candies are always less than or equal candies than its left neighbor before updating. After the forward traversal, we traverse the array from right-to-left and update right2left[i] as right2left[i] = right2left[i + 1] + 1, whenever the current i'th element has a higher ratings than the right i+1'th element.

Now, for the i'th student in the array, we need to give max(left2right[i], right2left[i]) to them, in order to satisfy both the left and the right neighbor relationship. Thus, at the end, we obtain the minimum number of candies required as:

\text{minimum\_candies}=\sum_{i=0}^{n-1} \text{max}(\text{left2right}[i], \text{right2left}[i]) \\ \text{where } n = \text{length of the ratings array.}minimum_candies=∑ i=0 to n−1 max(left2right[i],right2left[i])
where n=length of the ratings array.
*/
      /*
        int len = ratings.size();
        vector<int> leftToRightCandy(len, 1);
        vector<int> rightToLeftCandy(len, 1);
        for(int i=1; i<len; i++) {
            if (ratings[i] > ratings[i - 1])
                leftToRightCandy[i] = leftToRightCandy[i - 1] + 1;
        }
        for(int i=len - 2; i>=0; i--) {
            if (ratings[i] > ratings[i + 1])
                rightToLeftCandy[i] = rightToLeftCandy[i + 1] + 1;
        }
        int candies = 0;
        for(int i=0; i<len; i++)
            candies += max(leftToRightCandy[i], rightToLeftCandy[i]);
        return candies;
    }*/
    // One array solution.
    // We don not have to save right to left individually: just update leftToRightCandy.
        int len = ratings.size();
        vector<int> candies(len, 1);
        for (int i=1; i<len; i++) {
            if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        } // already candies[i - 1] < = candies[i] for every i
        int sum = candies[len - 1];
        for (int i=len - 2; i>=0; i--) {
            if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
            sum += candies[i];
        }
        return sum;

    }

};
/* Solution: do double sweeping. sweep for each direction!
 * Do not care about different directions.
 */
