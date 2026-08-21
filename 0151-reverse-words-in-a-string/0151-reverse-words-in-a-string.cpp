class Solution {
public:
    string reverseWords(string s) {
        //*******BETTER appraoch************
        // istringstream iss(s);
        // string word;
        // vector<string> arr;

        // while(iss >> word) arr.push_back(word);

        // string result;

        // for(int i=arr.size()-1; i>=0; i--){
        //     result.append(arr[i]);
        //     result.append(" ");
        // }
        // result.pop_back();
        // return result;

        //*******************OPTIMAL********************
        string ans;
        int i = s.size() - 1;

        while(i >= 0){
            while(i >= 0 && s[i] == ' ') i--;
            if(i == -1) break;

            int j=i;
            while(i >= 0 && s[i] != ' ') i--;

            if (!ans.empty()) ans.push_back(' ');
            ans.append(s.substr(i+1,j-i));
        } 

        return ans;
    }
};