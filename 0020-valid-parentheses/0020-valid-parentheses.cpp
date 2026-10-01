class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) return false;     // odd length can never be balanced

        string stack;                       // string as a stack: fast, contiguous
        stack.reserve(s.size() / 2);

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push_back(ch);
            } else {
                if (stack.empty()) return false;
                char top = stack.back();
                stack.pop_back();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) return false;
            }
        }

        return stack.empty();               // leftover openers => invalid
    }
};