class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string w;

        while(iss >> w);

        return w.size();
    }
};