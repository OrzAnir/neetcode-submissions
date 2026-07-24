class Solution {
public:
    int bs(int val, vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if (arr[mid] >= val) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int k = ans.size();
            if (k == 0 || nums[i] > ans[k - 1]) ans.push_back(nums[i]);
            else ans[bs(nums[i], ans)] = nums[i];
        }
        return ans.size();
    }
};
