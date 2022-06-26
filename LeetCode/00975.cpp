clas Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size(), res = 1;
        vector<int> higher(n), lower(n);
        higher[n - 1] = lower[n - 1] = 1;
        map<int, int> map;
        map[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            // For each index i, only i+1 ~ A.size()-1 elements are in the map. Thus, both lower_bound, upper_bound finds an index after index i.
            auto hi = map.lower_bound(A[i]), lo = map.upper_bound(A[i]);
            if (hi != map.end()) higher[i] = lower[hi->second]; // lower_bound: an element whose value is larger than or equal to current value; thus arr[i] <= arr[j].
            if (lo != map.begin()) lower[i] = higher[(--lo)->second]; // upper bound: an element whose value is strictly larger than to current value but it is smallest possible. Thus previous index of upper bound has the smaller than or equal value to the current value.
            if (higher[i]) res++; // From the starting index i, we have to start with higher direction.
            map[A[i]] = i; // This maintains the smallest possible index with the same value.
        }
        return res;
    }
};

// Optimal structure: 우리가 만약 어떤 index 이후의 결과값들만 저장하고 있을 수
// 있다면, 그 결과값들을 토대로 이전 index의 값들을 추출 가능하다.
// 먼저 map<int, int> 로 하여금, {array value, array index}를 저장하고 있도록 만든다.
// array.size()-1에서는 움직일 필요가 없으니 higher, lower에 해당하는 결과값을
// 모두 1로 둔다.
// 그 다음 index를 1씩 줄여가면서 가능한지 확인한다.

