class Solution {
public:
    int minInsertions(string s) {
        int open = 0;  // unmatched '('
        int ans = 0;   // insertions
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // form a "))" pair
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;           // consume both
                } else {
                    ans++;         // insert a missing ')'
                }
                if (open > 0) {
                    open--;
                } else {
                    ans++;         // insert a missing '('
                }
            }
        }
        return ans + open * 2;
    }
};