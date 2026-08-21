class Solution {
public:
    string reverseWords(string s) {
        //*******BETTER appraoch************
        istringstream iss(s);
        string word;
        vector<string> arr;

        while(iss >> word) arr.push_back(word);

        string result;

        for(int i=arr.size()-1; i>=0; i--){
            result.append(arr[i]);
            result.append(" ");
        }
        result.pop_back();
        return result;
    }
};