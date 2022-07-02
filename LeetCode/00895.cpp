class FreqStack {
public:
    map<int, int> elmt_freq;
    map<int, stack<int>> elmt_level;
    int max_level;
    FreqStack() {
        elmt_freq = map<int, int>();
        elmt_level = map<int, stack<int>>();
        max_level = 0;
    }
    
    void push(int val) {
        if (elmt_freq.count(val) == 0) {
            elmt_freq[val] = 0;
        }
        elmt_freq[val] += 1;
        if (elmt_level.count(elmt_freq[val]) == 0 || elmt_level[elmt_freq[val]].empty()) {
            elmt_level[elmt_freq[val]] = stack<int>();
            if (max_level < elmt_freq[val]) max_level = elmt_freq[val];
        }
        elmt_level[elmt_freq[val]].push(val);
    }
    
    int pop() {
        // To maintain elmt_level size in O(1) time, when the pop occurs, if that level's element gets zero, delete that key from the map.
        int target_num = elmt_level[max_level].top();
        elmt_level[max_level].pop();
        if (elmt_level[max_level].size() == 0) max_level--;
        elmt_freq[target_num] -= 1;
        return target_num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 
 */

//var FreqStack = function() {
//    this.doubleStack = []; // 어떤 숫자가 몇 번째에 나왔는지
    /** ex)
    * [, [1, 2, 5], [2, 1], [1]] => 1은 3번 2는 2번 5는 1번 나옴
    **/
//  	this.inFloor = []; // 각 element의 빈도 
  	/** ex)
    * [, 3, 2, , , 1] => 1은 3번 2는 2번 5는 1번 나옴
    **/
//};

//FreqStack.prototype.push = function(val) {
//  if(!this.inFloor[val]) this.inFloor[val] = 0;
//  this.inFloor[val]++;
//  if(!this.doubleStack[this.inFloor[val]]) this.doubleStack[this.inFloor[val]] = []
//  this.doubleStack[this.inFloor[val]].push(val)
//};

//FreqStack.prototype.pop = function() {
//  const maxFrequency = this.doubleStack.length-1;
//  const targetNum = this.doubleStack[maxFrequency].pop();
//  this.inFloor[targetNum]--;
//  if(this.doubleStack[maxFrequency].length === 0) this.doubleStack.pop();
//  return targetNum;
//};
