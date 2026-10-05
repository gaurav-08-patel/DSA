class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, depth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // Immediately preceded by '(' means this is a "()" pair
                if (s[i - 1] == '(') {
                    score += 1 << depth;
                }
            }
        }
        return score;
    }
};