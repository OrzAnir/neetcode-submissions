class Solution {
public:
    void func(int index, vector<string>& input, string& ds, vector<string>& result) {
        if (index == input.size()) {
            result.push_back(ds);
            return;
        }
        for(int i = 0; i < input[index].size(); i++) {
            ds.push_back(input[index][i]);
            func(index + 1, input, ds, result);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> input(n);
        vector<string> result;
        string ds;
        if (n == 0) return result;
        for(int i = 0; i < n; i++) {
            char c = digits[i];
            switch(c) {
                case '2': input[i] = "abc"; break;
                case '3': input[i] = "def"; break;
                case '4': input[i] = "ghi"; break;
                case '5': input[i] = "jkl"; break;
                case '6': input[i] = "mno"; break;
                case '7': input[i] = "pqrs"; break;
                case '8': input[i] = "tuv"; break;
                case '9': input[i] = "wxyz"; break;
            }
        }
        func(0, input, ds, result);
        return result;
    }
};
