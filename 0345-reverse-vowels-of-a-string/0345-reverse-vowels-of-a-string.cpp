class Solution {
public:
    bool isVowel(char c) {
        static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                                   'A', 'E', 'I', 'O', 'U'};
        return vowels.count(c);
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