class Solution {
public:
    void func(int index, vector<int>& candidates, int target, vector<int>& ds, 
    vector<vector<int>>& result) {
        if (index == candidates.size()) {
            if (target == 0) result.push_back(ds);
            return;
        }
        if (target < 0) return;
        if (target == 0) {
            result.push_back(ds);
            return;
        }
        int prev = 0;
        for(int i = index; i < candidates.size(); i++) {
            if(candidates[i] == prev) continue;
            prev = candidates[i];
            ds.push_back(candidates[i]);
            func(i + 1, candidates, target - candidates[i], ds, result);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> ds;
        func(0, candidates, target, ds, result);
        return result;
    }
};
