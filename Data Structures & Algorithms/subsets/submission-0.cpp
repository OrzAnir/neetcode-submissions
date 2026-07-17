class Solution {
public:
    void func(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        func(index + 1, nums, ds, result);
        ds.pop_back();
        func(index + 1, nums, ds, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        vector<int> ds;
        func(0, nums, ds, result);
        return result;
    }
};
