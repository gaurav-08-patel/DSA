class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0, rightRem = 0;
        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            } else if (ch == ')') {
                if (leftRem > 0) leftRem--;
                else rightRem++;
            }
        }

        unordered_set<string> res;
        string cur;
        dfs(s, 0, 0, leftRem, rightRem, cur, res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(const string& s, int i, int open, int leftRem, int rightRem,
             string& cur, unordered_set<string>& res) {
        if (i == (int)s.size()) {
            if (open == 0 && leftRem == 0 && rightRem == 0) res.insert(cur);
            return;
        }

        char ch = s[i];

        if (ch == '(') {
            // Option 1: remove it
            if (leftRem > 0) {
                dfs(s, i + 1, open, leftRem - 1, rightRem, cur, res);
            }
            // Option 2: keep it
            cur.push_back(ch);
            dfs(s, i + 1, open + 1, leftRem, rightRem, cur, res);
            cur.pop_back();
        } else if (ch == ')') {
            // Option 1: remove it
            if (rightRem > 0) {
                dfs(s, i + 1, open, leftRem, rightRem - 1, cur, res);
            }
            // Option 2: keep it (only if there is a '(' to match)
            if (open > 0) {
                cur.push_back(ch);
                dfs(s, i + 1, open - 1, leftRem, rightRem, cur, res);
                cur.pop_back();
            }
        } else {
            // Letter: always keep
            cur.push_back(ch);
            dfs(s, i + 1, open, leftRem, rightRem, cur, res);
            cur.pop_back();
        }
    }
};