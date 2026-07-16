class Solution {
public:
    bool isAN(char c) {
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left <= right) {
            while(!isAN(s[left])) left++;
            while(!isAN(s[right])) right--;
            if (left > right) return true;
            if (toupper(s[left]) != toupper(s[right])) return false;
            left++; right--;
        }
        return true;
    }
};
