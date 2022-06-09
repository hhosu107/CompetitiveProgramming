class MovingAverage {
public:
    queue<int> values;
    int curr_sum;
    int nums;
    int size;
    MovingAverage(int size) {
        values = queue<int>();
        curr_sum = 0;
        this->size = size;
        nums = 0;
    }
    
    double next(int val) {
        this->nums += 1;
        if (this->nums > this->size) {
            int front = values.front();
            values.pop();
            this->curr_sum -= front;
            this->nums -= 1;
        }
        values.push(val);
        this->curr_sum += val;
        return (double)this->curr_sum / (double)this->nums;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
