class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int mx = 0;
        vector<long long> cnt(100002, 0);
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            mx = max(mx, d);
        }

        for (int v = mx; v >= 1 && k > 0; v--) {
            long long c = cnt[v];
            if (c == 0) continue;
            if (k >= c) {
                cnt[v - 1] += c;
                cnt[v] = 0;
                k -= c;
            } else {
                cnt[v - 1] += k;
                cnt[v] -= k;
                k = 0;
            }
        }

        long long ans = 0;
        for (int v = 1; v <= mx; v++) {
            ans += (long long)v * v * cnt[v];
        }
        return ans;
    }
};