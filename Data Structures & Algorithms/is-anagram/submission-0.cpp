class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> mpp1;
        map<char, int> mpp2;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        for(int i = 0; i < n; i++) {
            if (mpp1[s[i]] != mpp2[s[i]]) return false;
        }
        return true;
    }
};
