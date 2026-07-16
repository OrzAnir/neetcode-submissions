class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> mpp;
        int n = s.size();
        for(int i = 0; i < n; i++) mpp[s[i]]++;
        for(int i = 0; i < n; i++) {
            mpp[t[i]]--;
            if (mpp[t[i]] < 0) return false;
        }
        for(auto it : mpp) {
            if (it.second != 0) return false;
        }
        return true;
    }
};
