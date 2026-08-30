class Solution {
public:
    // this splits array into subarray with its summation = sum
    int splitToSubArray(vector<int> &nums, int sum){
        int subarray =1,arraySum = 0; 

        for(int i=0; i<nums.size(); i++){
            if(arraySum + nums[i] <= sum){
                arraySum += nums[i];
            }else{
                subarray++;
                arraySum = nums[i];
            }
        }

        return subarray;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end()); // returns max_ele from nums
        int high = accumulate(nums.begin(), nums.end() , 0); // this returns summation of nums

        while(low <= high){
            int mid = (low + high)/2;
            int subarray = splitToSubArray(nums,mid);

            if(subarray <= k){
                high = mid - 1;
            }else low = mid + 1;

        }
        
        return low;
    }
};