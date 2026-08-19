class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonString = strs[0];

        for (string s : strs) {
            while (!s.starts_with(commonString)) {
                if (!commonString.empty())
                    commonString.pop_back();
            }
        }

        return commonString;
    }
};