class Solution {
public:
    void func(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& result) {
        result.push_back(ds);
        if (index == nums.size()) return;
        int prev = -21;
        for(int i = index; i < nums.size(); i++) {
            if (nums[i] == prev) continue;
            prev = nums[i];
            ds.push_back(nums[i]);
            func(i + 1, nums, ds, result);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ds;
        func(0, nums, ds, result);
        return result;
    }
};
