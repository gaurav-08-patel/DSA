class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //Binary search approach
        // two loops for a , and b then startlooking for c using BS such that a + b > c
        int count=0;

        sort(nums.begin(),nums.end());

        //****************Sorting + BinarySearch**************
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         int a = nums[i],b=nums[j],k=j;
        //         int low = j + 1, high = nums.size() - 1;

        //         while(low <= high){
        //             int mid = (low+high)/2;

        //             if(nums[mid] < a + b) {
        //                 k=mid;
        //                 low = mid + 1; //search for larger
        //             }
        //             else high = mid - 1;
                    
        //         }

        //         count += (k - j);
        //     }
        // }
        int n = nums.size();
        if (n < 3) return 0;
        //Two Pointer + Sorting 

        for(int c = n - 1; c >= 2; c--){ // fix largest at last , since array is already sorted
            // now fix two pinters low and high before c
            int low = 0, high = c - 1;

            while(low < high){
                if(nums[low] + nums[high] > nums[c]){
                    count += (high - low); // all pairs between low-to-high are valid 
                    high--; // try with smaller second side
                }else low++; // need larger first side
            }
        }

        return count;
    }
};