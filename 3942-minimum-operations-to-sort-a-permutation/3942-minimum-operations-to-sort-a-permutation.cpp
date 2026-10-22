class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int p = 0;  // index of 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) p = i;
        }

        bool asc = true, desc = true;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] != (nums[i] + 1) % n) asc = false;
            if (nums[i + 1] != (nums[i] - 1 + n) % n) desc = false;
        }

        int ans = INT_MAX;
        if (asc) {
            ans = min(ans, p);
            if (p > 0) ans = min(ans, n - p + 2);
        }
        if (desc) {
            ans = min(ans, n - p);                // reverse, then rotate
            ans = min(ans, (p + 1) % n + 1);      // rotate, then reverse
        }
        return ans == INT_MAX ? -1 : ans;
    }
};