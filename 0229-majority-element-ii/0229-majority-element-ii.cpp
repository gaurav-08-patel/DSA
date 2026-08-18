class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int mini = (int)(nums.size()/3) + 1;

        for(int n : nums){
            mpp[n]++;

            if(mpp[n] == mini){
                ans.push_back(n);
            }

            if(ans.size() == 2) break;
        }

        return ans;
    }
};