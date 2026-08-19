class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //*******************BETTER approach**************
        // set<vector<int>> st; // to store unique triplets

        // for(int i=0; i<nums.size(); i++){
        //     set<int> hashSet; // to store element between i and j
        //     for(int j=i+1; j<nums.size(); j++){
        //         int k = -(nums[i] + nums[j]);
        //         if(hashSet.find(k) != hashSet.end()){
        //             vector<int> temp = {  nums[i] , nums[j] , k  };
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         hashSet.insert(nums[j]);
        //     }
        // }

        // vector<vector<int>> ans(st.begin(),st.end());

        // return ans;




        //**************OPTIMAL approach**********************************
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(  i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size() - 1;

            while (j<k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    vector<int> temp = { nums[i] , nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            } 
        }
        return ans;
    }    
};