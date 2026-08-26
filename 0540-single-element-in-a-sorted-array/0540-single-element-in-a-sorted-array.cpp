class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //concept is to use elimination technique of BS to reduce size of array and keep on checking if Im on unique element or not by checkg its before and after element

        int n = nums.size();
        // this if's are to eliminate the edge cases and to not write if conditions to check whether Im on first or last index before checking its before and after element to know whether it distinct or not 
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        //now we will start from 1 and n-1 index for low and high
        int low = 1, high = n-1;

        // (even , odd) // if on left side of unique element then repeated elements will have even-odd indices
        // (odd , even) // if on right side then odd-even
        // ex : [ 3 , 3 , 7 , 7 , 10 , 11 , 11 ] --> 3-> (0,1) : (even,odd) , 7-> (2,3) : (even,odd) , 11-> (5,6) : (odd,even)
        while(low <= high){
            int mid = (low + high)/2;
            //check if curr mid is unique or not
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            if( (mid % 2 == 1   && nums[mid] == nums[mid-1])  || (mid % 2 == 0 && nums[mid] == nums[mid + 1])  ){
                low = mid +1;
            }else {
                high = mid - 1;
            }

        }
        return -1;
    }
};