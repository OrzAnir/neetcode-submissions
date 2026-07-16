class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), lmax = 0, rmax = 0;
        int left = 0, right = n - 1;
        int water = 0;
        while(left <= right) {
            if (lmax <= rmax) {
                int val = lmax - height[left];
                if (val > 0) water += val;
                lmax = max(lmax, height[left]);
                left++;
            }
            else {
                int val = rmax - height[right];
                if (val > 0) water += val;
                rmax = max(rmax, height[right]);
                right--;
            }
        }
        return water;
    }
};
