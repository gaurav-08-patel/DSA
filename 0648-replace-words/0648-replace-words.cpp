class Solution {
public:
    //not optimized solution
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream iss(sentence);
        string word,result;

        while(iss >> word){
            string replacement = word;

            for(string root : dictionary){
                if(replacement.starts_with(root)){
                    replacement = root;
                }
            }

            if(!result.empty()) result += " ";
            result += replacement;

        }

        return result;
    }
};