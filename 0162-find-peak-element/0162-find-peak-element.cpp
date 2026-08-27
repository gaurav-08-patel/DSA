class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // these if's are to avoid checking if Im on first or last index to avoid heap-overflow
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        //now we will start our BS from low=1, high=n-2
        int low = 1, high = n-2;

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] ){ //found peak
                return mid;
            }else if(nums[mid] > nums[mid-1]){ // peak is on the right side so eliminate left side
                low = mid + 1;
            }else if(nums[mid] < nums[mid - 1]){ // peak is on the left side so eliminate right side
                high = mid - 1;
            }else{ // mid is at lowest point so moving to either side will have one peak element 
                low = mid + 1;
            }

        }

        return -1;
    }
};