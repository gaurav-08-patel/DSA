class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        rowIndex++;

        for(int col=1; col<rowIndex; col++){
            ans = ans * (rowIndex - col);
            ans = ans / col;
            ansRow.push_back((int)ans);
        }

        return ansRow;
    }
};