class Solution {
public:
    int findMaxIndex(vector<vector<int>> mat , int n , int col){
        int idx = -1;
        int mx=INT_MIN;

        for(int row = 0; row < n; row++){
            if(mx < mat[row][col]){
                mx = mat[row][col];
                idx = row;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low =0, high = m -1;

        while(low <= high){
            int mid = (low + high)/2;

            int row = findMaxIndex(mat,n,mid);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1 ;// to safely check whether Im on first element 
            int right = mid + 1 < m ? mat[row][mid + 1] : -1 ;// to safely check whether Im on last element 

            if(mat[row][mid] > left && mat[row][mid] > right) return {row,mid};
            else if(mat[row][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        
        return {-1,-1};
    }
};