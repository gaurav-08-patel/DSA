class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long S = 0;// sum of all numbers of 2d-array
        long long SN = n*n * ( n*n + 1 ) / 2;// sum of numbers from 1-n^2
        long long S2  = 0;// sum of squares of all numbers of 2d-array
        long long S2N = n*n ; // n*n * (n*n + 1) * (2*n*n + 1) / 6 , breaked into parts to control long long overflow
        S2N = S2N * (n*n + 1);
        S2N *= (2*n*n + 1);
        S2N /= 6;
        // sum of square of all numbers from 1-n^2

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                S += grid[i][j];
                S2 += grid[i][j] * grid[i][j];
            }
        }

        long long val1 = S - SN; // suppose this as x - y
        long long val2 = S2 - S2N;// suppose this as x2 - y2
        val2 = val2/val1; // then this will be x + y

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return { (int)x , (int)y };
    }
};