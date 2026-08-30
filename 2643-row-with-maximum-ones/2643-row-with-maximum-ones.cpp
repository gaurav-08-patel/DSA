class Solution {
public:
    int countOnes(vector<int> &nums){
       int count =0;

       for(int n : nums){
        if(n == 1) count++;
       }

       return count;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int idx = -1, cnt_max = INT_MIN;

        for(int i=0; i<mat.size(); i++){
            int cnt_ones = countOnes(mat[i]);

            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                idx = i;
            }
        } 

        return {idx , cnt_max};
    }
};