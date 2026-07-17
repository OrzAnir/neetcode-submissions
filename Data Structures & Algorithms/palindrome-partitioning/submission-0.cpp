class Solution {
public:
    bool isPalindrome(string str) {
        int left = 0, right = str.size() - 1;
        while(left <= right) {
            if (str[left] != str[right]) return false;
            left++; right--;
        }
        return true;
    }
    void func(int index, string& s, vector<string>& ds, vector<vector<string>>& result) {
        if (index == s.size()) {
            result.push_back(ds);
            return;
        }
        for(int i = index; i < s.size(); i++) {
            string str = s.substr(index, i - index + 1);
            if (isPalindrome(str)) {
                ds.push_back(str);
                func(i + 1, s, ds, result);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> result;
        vector<string> ds;
        func(0, s, ds, result);
        return result;
    }
};
