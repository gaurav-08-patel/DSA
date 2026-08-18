class Solution {
public:
    // int getPoint(char c) {
    //     if (c >= 48 && c <= 57) {
    //         return 3;
    //     } else if (c >= 97 && c <= 122) {
    //         return 1;
    //     } else if (c >= 65 && c <= 90) {
    //         return 2;
    //     } else {
    //         return 5;
    //     }
    // }

    int passwordStrength(string password) {

        //****************************not optimal**************
        // set<char> s(password.begin(), password.end());
        // int strength=0;

        // for (auto el : s) {
        //     strength = strength + getPoint(el);
        // }

        // *************************OPTIMAL solution*************************

        vector<bool> seen(128, false);
        int strength = 0;

        for (char c : password) {
            if(!seen[c]){
                seen[c] = true;
                if(isdigit(c)) strength += 3;
                else if(islower(c)) strength += 1;
                else if(isupper(c)) strength += 2;
                else strength += 5;
            }
        }
        return strength;
    }
};