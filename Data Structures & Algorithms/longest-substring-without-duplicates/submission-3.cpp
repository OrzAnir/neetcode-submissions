class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mpp;
        int n = s.length();
        int left = 0;
        int maxlen = 0, len = 0;
        for(int i = 0; i < n; i++) {
            if (mpp.find(s[i]) == mpp.end() || mpp[s[i]] < left) {
                mpp[s[i]] = i;
                len += 1;
                maxlen = max(maxlen, len);
            }
            else {
                left = mpp[s[i]] + 1;
                mpp[s[i]] = i;
                len = i - left + 1;
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};
