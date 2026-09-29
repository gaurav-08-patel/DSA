class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false; // odd length can never balance

        int maxBalance = (m + n) / 2 + 1;

        // dp[i][j] = set of possible balances at (i,j)
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(maxBalance + 1, false))
        );

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int delta = (grid[i][j] == '(') ? 1 : -1;

                if (i == 0 && j == 0) {
                    if (delta == 1) {
                        dp[0][0][1] = true;
                    }
                    continue;
                }

                // gather balances from top and left
                for (int k = 0; k <= maxBalance; k++) {
                    bool fromTop = (i > 0) && dp[i-1][j][k];
                    bool fromLeft = (j > 0) && dp[i][j-1][k];

                    if (fromTop || fromLeft) {
                        int newBalance = k + delta;
                        if (newBalance >= 0 && newBalance <= maxBalance) {
                            dp[i][j][newBalance] = true;
                        }
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};