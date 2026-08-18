class Solution {
public:
    bool isVowel(char c) {
        string vowels = "aeiouAEIOU";
        return vowels.find(c) != string::npos;
    }
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};