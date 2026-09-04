class Solution {
public:
    int findMin(vector<int> &nums , int idx){
        int mini = nums[idx];

        for(int i=idx; i<nums.size(); i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }
 
    int firstStableIndex(vector<int>& nums, int k) {
        int mx = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            mx = max(mx,nums[i]);
            int mini = findMin(nums,i);

            int instability = mx - mini;

            if(instability <= k) return i;

        }
        return -1;
    }
};