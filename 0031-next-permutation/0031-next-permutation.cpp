class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n =  nums.size();

        //for finding the first dip in graph(first number which is less that arr[i+1]) 
        for(int i =n-2 ; i >=0 ; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        //this means that it was the last permutation
        if(idx == -1){
            return reverse(nums.begin(),nums.end());
        }

        //now I need to swap value at idx with number just greater than itself
        for(int i = n-1 ; i>idx ; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i] , nums[idx]);
                break;
            }
        }

        //now reverse the remaining array to get right next permutation

        return reverse(nums.begin() + idx + 1 , nums.end());


    }
};