class Solution {
public:
    
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        // if(n == 0) return -1;
        vector<int> suffixMin(n);

        suffixMin[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }   

        int mx = nums[0];
        for(int i=0; i<n; i++){
            mx = max(mx,nums[i]);

            int instability = mx - suffixMin[i];

            if(instability <= k) return i;
        }
        return -1;
    }
};