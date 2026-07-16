class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int n = s.length();
        int left = 0;
        int maxlen = 0, len = 0;
        for(int i = 0; i < n; i++) {
            if (st.find(s[i]) == st.end()) {
                len += 1;
                maxlen = max(maxlen, len);
                st.insert(s[i]);
            }
            else {
                while(left < i && s[left] != s[i]) {
                    st.erase(s[left++]);
                    len--;
                }
                left++;
            }
        }
        return maxlen;
    }
};
