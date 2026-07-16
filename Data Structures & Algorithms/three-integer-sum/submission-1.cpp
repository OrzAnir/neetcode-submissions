class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // -4 -1 -1 0 1 2 
        int val = INT_MIN, n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++) {
            if (nums[i] == val) continue;
            val = nums[i];
            int target = -val;
            int left = i + 1, right = n - 1;
            while(left < right) {
                if (nums[left] + nums[right] == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (nums[left] + nums[right] < target) left++;
                else right--;
            }
        }
        return ans;
    }
};
