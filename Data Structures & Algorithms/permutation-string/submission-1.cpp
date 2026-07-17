class Solution {
public:
    int checkCounts(vector<int>& mpp1, vector<int>& mpp2) {
        int counts = 0;
        for(int i = 0; i < 26; i++) {
            if (mpp1[i] == mpp2[i]) counts += 1;
        }
        return counts;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> mpp1(26, 0);
        int n1 = s1.length(), n2 = s2.length();
        for(int i = 0; i < n1; i++) {
            mpp1[s1[i] - 'a']++;
        }
        vector<int> mpp2(26, 0);
        if (n1 > n2) return false;
        int l = 0, r = 0;
        for(; r < n1; r++) {
            mpp2[s2[r] - 'a']++;
        }
        r--;
        while(r < n2) {
            if (checkCounts(mpp1, mpp2) == 26) return true;
            if (r + 1 >= n2) break;
            mpp2[s2[l] - 'a']--;
            mpp2[s2[r + 1] - 'a']++;
            l += 1;
            r += 1;
        }
        return false;
    }
};
