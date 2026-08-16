class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //**************BETTER approach solution NOT optimal****************
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lastEl=INT_MIN, count=1, longest=0;

        for(int i=0; i<n; i++){
            if(nums[i] - 1 == lastEl ){
                count++;
                lastEl = nums[i];
            }else if(nums[i] != lastEl){
                count=1;
                lastEl = nums[i];
            }

            longest = max(longest, count);
        }

        return longest;
    }
};