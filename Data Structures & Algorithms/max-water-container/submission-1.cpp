class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n - 1, maxarea = INT_MIN;
        while(left <= right) {
            int area = (right - left) * min(heights[left], heights[right]);
            maxarea = max(maxarea, area);
            if (heights[left] < heights[right]) left++;
            else right--;
        }
        return maxarea;
    }
};
