class HitCounter {
public:
    queue<int> hits;
    int hit_size;
    int curr_timestamp;
    HitCounter() {
        hits = queue<int>();
        hit_size = 0;
        curr_timestamp = 0;
    }
    
    void hit(int timestamp) {
        while(!hits.empty() && hits.front() + 300 <= timestamp) {
            hits.pop();
            hit_size -= 1;
        }
        hits.push(timestamp);
        curr_timestamp = timestamp;
        hit_size += 1;
    }
    
    int getHits(int timestamp) {
        while(!hits.empty() && hits.front() + 300 <= timestamp) {
            hits.pop();
            hit_size -= 1;
        }
        curr_timestamp = timestamp;
        return hit_size;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
