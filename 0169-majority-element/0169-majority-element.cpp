class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;

        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto m : mpp){
            if(m.second > nums.size()/2){
                return m.first;
            }
        }
        return -1;
    }
};