class Solution {
public:
    long long reverseDegree(string s) {
        long long sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int reverseAlphaPos = 26 - (s[i] - 'a'); // 'a'=26, 'b'=25, ..., 'z'=1
            sum += (long long)reverseAlphaPos * (i + 1); // 1-indexed position
        }
        return sum;
    }
};