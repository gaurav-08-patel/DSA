class Solution {
public:
    int getPoint(char c) {
        if (c >= 48 && c <= 57) {
            return 3;
        } else if (c >= 97 && c <= 122) {
            return 1;
        } else if (c >= 65 && c <= 90) {
            return 2;
        } else {
            return 5;
        }
    }

    int passwordStrength(string password) {
        set<char> s(password.begin(), password.end());
        int strength=0;

        for (auto el : s) {
            strength = strength + getPoint(el);
        }

        return strength;
    }
};