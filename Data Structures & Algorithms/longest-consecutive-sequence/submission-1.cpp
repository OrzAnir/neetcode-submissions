class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> st;
        for(int x : nums) st.insert(x);
        int maxlen = 1;
        for (auto it : st) {
            if (st.find(it - 1) != st.end()) continue;
            int x = it, len = 1;
            while(st.find(x + 1) != st.end()) {
                len += 1;
                x += 1;
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};
