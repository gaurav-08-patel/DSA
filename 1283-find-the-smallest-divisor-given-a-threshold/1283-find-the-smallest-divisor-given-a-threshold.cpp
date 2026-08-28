class Solution {
public:
    int sumOfD(vector<int> nums, int k){
        int sum=0;

        for(int n : nums){
            sum += ceil( (double)n/ (double)k);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        // using binary search on answer to find minimum 
        int mx = INT_MIN;
        for(int n : nums){
            mx = max(mx,n);
        }

        int low = 1, high = mx;
        int ans=-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(sumOfD(nums,mid) <= threshold ){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }

        return ans; // can also return low instead of storing in ans
    }
};