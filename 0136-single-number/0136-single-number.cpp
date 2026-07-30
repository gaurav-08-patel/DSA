class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorVal = 0;

        for(int i = 0; i < nums.size(); i++){
            xorVal ^= nums[i];
        }

        return xorVal;
    }
};