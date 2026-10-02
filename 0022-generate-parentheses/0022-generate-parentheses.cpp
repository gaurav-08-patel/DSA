class Solution {
public:
    void backtrack(int open, int close, int n, string s, vector<string>& ans) {

        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add an opening bracket if available
        if (open < n) {
            backtrack(open + 1, close, n, s + '(', ans);
        }

        // Add a closing bracket only if it remains valid
        if (close < open) {
            backtrack(open, close + 1, n, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        backtrack(0, 0, n, "", ans);

        return ans;
    }
};