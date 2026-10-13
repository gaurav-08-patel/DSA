class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; i++) {
            sq[i] = (long long)nums[i] * nums[i];
        }
        sort(sq.begin(), sq.end());

        int minus = n / 2;  // number of subtracted slots
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < minus) ans -= sq[i];
            else ans += sq[i];
        }
        return ans;
    }
};