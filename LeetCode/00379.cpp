class PhoneDirectory {
public:
    int max_numbers;
    int pq_size;
    priority_queue<int, vector<int>, greater<int>> remaining_slots;
    vector<bool> available;
    PhoneDirectory(int maxNumbers) {
        max_numbers = maxNumbers;
        available = vector<bool>(max_numbers, true);
        for(int i=0; i<max_numbers; i++)
            remaining_slots.push(i);
        pq_size = max_numbers;
    }
    
    int get() {
        if (pq_size == 0) {
            return -1;
        }
        int top = remaining_slots.top();
        remaining_slots.pop();
        available[top] = false;
        pq_size -= 1;
        return top;
    }
    
    bool check(int number) {
        return available[number];
    }
    
    void release(int number) {
        if (available[number]) return;
        available[number] = true;
        remaining_slots.push(number);
        pq_size += 1;
    }
};
