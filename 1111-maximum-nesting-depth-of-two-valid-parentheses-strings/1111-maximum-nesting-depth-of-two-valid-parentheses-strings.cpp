class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer(seq.size());
        int depth = 0;

        for (int i = 0; i < (int)seq.size(); i++) {
            if (seq[i] == '(') {
                depth++;
                answer[i] = depth % 2; // assign based on new depth parity
            } else {
                answer[i] = depth % 2; // assign based on current depth parity
                depth--;
            }
        }

        return answer;
    }
};