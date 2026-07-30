class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        //for storing XOR of all numbers 
        int xorAll = 0;
        //for storing XOR of all elements in array
        int xorArr = 0;

        //instead of using two loops for XORing use one loop to improve Time complexity 
        for(int i = 0; i < n; i++){
            xorArr = xorArr ^ nums[i];
            xorAll = xorAll ^ (i+1);
        }

        return xorAll ^ xorArr;
    }
};