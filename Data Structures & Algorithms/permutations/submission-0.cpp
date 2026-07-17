class Solution {
public:
    void func(int index, vector<int>& nums, vector<int>& ds, vector<int>& mpp, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (mpp[i] == -1) {
                ds.push_back(nums[i]);
                mpp[i] = 1;
                func(index + 1, nums, ds, mpp, result);
                ds.pop_back();
                mpp[i] = -1;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> mpp(n, -1);
        vector<int> ds;
        vector<vector<int>> result;
        func(0, nums, ds, mpp, result);
        return result;
    }
};
