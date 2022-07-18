class MedianFinder {
public:
    // Sol) Use maxheap/minheap. Maintain their size diff by at most 1.
    priority_queue<int, vector<int>, less<int>> lower_median;
    priority_queue<int, vector<int>, greater<int>> upper_median;
    int lower_median_size;
    int upper_median_size;
    MedianFinder() {
        lower_median = priority_queue<int, vector<int>, less<int>>();
        upper_median = priority_queue<int, vector<int>, greater<int>>();
        lower_median_size = 0;
        upper_median_size = 0;
    }
    
    void addNum(int num) {
        if (lower_median_size == 0) {
            lower_median.push(num);
            lower_median_size += 1;
            return;
        }
        if (num > lower_median.top()) {
            upper_median.push(num);
            upper_median_size += 1;
        } else {
            lower_median.push(num);
            lower_median_size += 1;
        }
        if (upper_median_size + 2 <= lower_median_size) {
            int lower_largest = lower_median.top();
            lower_median.pop();
            upper_median.push(lower_largest);
            lower_median_size--;
            upper_median_size++;
        } else if (lower_median_size + 2 <= upper_median_size) {
            int upper_smallest = upper_median.top();
            upper_median.pop();
            lower_median.push(upper_smallest);
            upper_median_size--;
            lower_median_size++;
        }
    }
    
    double findMedian() {
        if (lower_median_size > upper_median_size) return lower_median.top();
        if (upper_median_size > lower_median_size) return upper_median.top();
        int sum_medians = lower_median.top() + upper_median.top();
        return (double)sum_medians / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
