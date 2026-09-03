class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //brute force is done using unordered_set for all rows , cols and subgrid 
        // eg : vector<unordered_set<int>> row(9), cols(9) , boxes(9);

        // BETTER solution uses array 
        bool rows[9][9] = {false} , cols[9][9] = {false}, boxes[9][9] = {false};

        for(int i=0; i < 9; i++){
            for(int j=0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1'; // converts number to their index , eg : 5 -> 4
                int boxIndex = (i/3) * 3 + (j/3);

                if(rows[i][num] || cols[j][num] || boxes[boxIndex][num]) return false;
                rows[i][num]=cols[j][num]=boxes[boxIndex][num] = true;
            }
        }
        return true;
    }
};