class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posIdx=0, negIdx=1;
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[posIdx] = nums[i];
                posIdx+=2;
            }else if(nums[i] < 0){
                ans[negIdx] = nums[i];
                negIdx+=2;
            }
        }

        return ans;
    }
};