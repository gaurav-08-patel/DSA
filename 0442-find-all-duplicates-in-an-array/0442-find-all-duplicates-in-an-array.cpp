class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mpp;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] >= 2) ans.push_back(nums[i]);
        }

        return ans;
    }
};