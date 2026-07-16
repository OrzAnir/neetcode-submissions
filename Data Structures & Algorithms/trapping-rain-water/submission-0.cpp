class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), rightmax = INT_MIN, leftmax = INT_MIN;
        vector<int> lmax(n, -1);
        vector<int> rmax(n, -1);
        for(int i = 0; i < n; i++) {
            if (height[i] > leftmax) leftmax = height[i];
            lmax[i] = leftmax;
        }
        for(int i = n - 1; i >= 0; i--) {
            if (height[i] > rightmax) rightmax = height[i];
            rmax[i] = rightmax;
        }
        int water = 0;
        for(int i = 0; i < n; i++) {
            int val = min(lmax[i], rmax[i]) - height[i];
            if (val >= 0) water += val;
        }
        return water;
    }
};
