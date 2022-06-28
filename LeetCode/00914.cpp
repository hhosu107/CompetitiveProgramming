class Solution {
public:
    int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> card_count;
        for(int d: deck)
            card_count[d] += 1;
        int one_card_pill = 0;
        for (auto it=card_count.begin(); it!=card_count.end(); it++) {
            if (one_card_pill == 0) one_card_pill = it->second;
            else one_card_pill = gcd(one_card_pill, it->second);
        }
        return (one_card_pill >= 2);
    }
};
