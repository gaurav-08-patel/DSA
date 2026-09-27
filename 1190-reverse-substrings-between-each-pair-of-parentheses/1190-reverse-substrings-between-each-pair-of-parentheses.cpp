class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack;
        stack.push_back(""); // base level

        for (char c : s) {
            if (c == '(') {
                stack.push_back("");
            } else if (c == ')') {
                string inner = stack.back();
                stack.pop_back();
                reverse(inner.begin(), inner.end());
                stack.back() += inner;
            } else {
                stack.back() += c;
            }
        }

        return stack.back();
    }
};