class Solution {
public:
    int firstBound(vector<int>& nums, int target, bool isFirst){
        int left = 0 , right = nums.size() - 1 , ans = -1;

        while(left <= right){
            int mid = ( left + right ) / 2;

            if(nums[mid] == target){
                ans = mid;
                if(isFirst){
                    right = mid - 1; // keep searching left
                }else{
                    left = mid + 1; // keep searching right 
                }

            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid -1;
            }

        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
    //     if(nums.empty()) return {-1,-1};
    //     int i=0,j=nums.size() - 1;

    //    while(i < nums.size() && nums[i] != target) i++;
    //    while( j >= 0 && nums[j] != target ) j--;

    //    if(nums[i] == target && nums[j] == target){
    //     return {i,j};
    //    }else{
    //     return {-1,-1};
    //    }

    //*********************OPTIMAL solution****************
        int first = firstBound(nums,target,true);
        if(first == -1 ) return {-1,-1};
        int second = firstBound(nums,target,false);

        return {first , second};
    }
};