class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int i =0 , j= nums.size()-1;
        // vector<int> ans;
 
        // while(i < j){
        //     int pairSum = nums[i] + nums[j];
        //     if(pairSum > target) j--;
        //     else if( pairSum < target) i++;
        //     else {
        //         ans.push_back(i);
        //         ans.push_back(j);
        //     };
        // }
        // return ans;

        unordered_map<int,int> mpp;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int more = target - num;

            if(mpp.find(more) != mpp.end()){
                return  { mpp[more] , i };
            }

            mpp[num] = i;
        }
        return {-1,-1};
    }
    
};