class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mpp;
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            map<char, int> mp;
            for(int j = 0; j < strs[i].size(); j++) mp[strs[i][j]]++;
            mpp[mp].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto it : mpp) result.push_back(it.second);
        return result;
    }
};
