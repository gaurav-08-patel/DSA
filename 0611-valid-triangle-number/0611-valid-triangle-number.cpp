class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //Binary search approach
        // two loops for a , and b then startlooking for c such that a + b > c
        int count=0;

        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int a = nums[i],b=nums[j],k=j;
                int low = j + 1, high = nums.size() - 1;

                while(low <= high){
                    int mid = (low+high)/2;

                    if(nums[mid] < a + b) {
                        k=mid;
                        low = mid + 1; //search for larger
                    }
                    else high = mid - 1;
                    
                }

                count += (k - j);
            }
        }

        return count;
    }
};