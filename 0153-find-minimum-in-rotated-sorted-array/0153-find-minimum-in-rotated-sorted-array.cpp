class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int low = 0, high = nums.size() -1;

        while(low <= high){
            int mid = (low + high)/2;
            //if sorted half is already sorted then low will always have mini value 
            // this if condition is just an optimization, not necessary to write this line
            if(nums[low] < nums[high]){
                mini  = min(mini , nums[low]);
                break;
            }

            if(nums[low] <= nums[mid]){
                mini = min(mini , nums[low] );
                low = mid + 1;
            }else{
                mini = min(mini , nums[mid]);
                high = mid - 1;
            }

        }

        return mini;
    }
};