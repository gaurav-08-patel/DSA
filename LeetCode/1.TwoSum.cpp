#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i =0 , j= nums.size()-1;
        vector<int> ans;
 
        while(i < j){
            int pairSum = nums[i] + nums[j];
            if(pairSum > target) j--;
            else if( pairSum < target) i++;
            else {
                ans.push_back(i);
                ans.push_back(j);
            };
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9 ;
    Solution sol;
    cout << sol.twoSum(nums, target);

}