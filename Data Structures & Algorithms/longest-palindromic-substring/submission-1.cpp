class Solution {
public:
    string longestPalindrome(string s) {
        int resInd = 0;
        int resLen = 0;
        int maxlen = 1, maxInd = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            int len = 1;
            int left = i - 1, right = i + 1;
            while(left >= 0 && right < n) {
                if (s[left] != s[right]) break;
                len += 2;
                if (len > maxlen) {
                    maxlen = len;
                    maxInd = left;
                }
                left--; right++;
            }
            left = i; right = i + 1; len = 0;
            while(left >= 0 && right < n) {
                if (s[left] != s[right]) break;
                len += 2;
                if (len > maxlen) {
                    maxlen = len;
                    maxInd = left;
                }
                left--; right++;
            }
        }
        return s.substr(maxInd, maxlen);
    }
};
