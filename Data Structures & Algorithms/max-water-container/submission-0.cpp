class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = INT_MIN;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int area = (j - i) * min(heights[i], heights[j]);
                maxarea = max(maxarea, area);
            }
        }
        return maxarea;
    }
};
