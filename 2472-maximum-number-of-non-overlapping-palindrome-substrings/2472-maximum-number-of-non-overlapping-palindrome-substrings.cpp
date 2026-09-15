class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0); // dp[i] = max count using prefix s[0..i-1]

        auto isPalin = [&](int l, int r) { // inclusive [l, r]
            while (l < r) {
                if (s[l] != s[r]) return false;
                ++l; --r;
            }
            return true;
        };

        for (int i = k; i <= n; ++i) {
            dp[i] = dp[i - 1]; // option: leave position i-1 unused
            for (int len : {k, k + 1}) {
                if (len > i) continue;
                int j = i - len; // substring s[j..i-1] has this length
                if (isPalin(j, i - 1)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};