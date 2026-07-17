class Solution {
public:
    void func(int index, vector<int>& nums, int target, vector<int>& ds, vector<vector<int>>& result) {
        if (index == nums.size()) {
            if (target == 0) result.push_back(ds);
            return;
        }
        if (target == 0) {
            result.push_back(ds);
            return;
        }
        if (target >= nums[index]) {
            ds.push_back(nums[index]);
            func(index, nums, target - nums[index], ds, result);
            ds.pop_back();
        }
        func(index + 1, nums, target, ds, result);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        func(0, nums, target, ds, result);
        return result;
    }
};
