class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //imagine 2D-array as 1D-array
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n*m - 1;

        while(low <= high){
            int mid = (low + high)/2;
            //convert 1d index to 2d index
            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target){
                return true;
            }
            if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};