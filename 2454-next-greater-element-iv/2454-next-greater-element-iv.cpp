class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; //stores indices of el waiting for first greater
        using pii = pair<int,int>; // stores key-value pair  ( value , index )
        priority_queue<pii , vector<pii> , greater<pii>> pq; // stores el waiting for second largest 
        vector<int> ans(n,-1);

        for(int i=0; i < n ; i++){
            //resolve element waiting for second largest 
            while(!pq.empty() &&  pq.top().first < nums[i]){
                ans[pq.top().second] = nums[i];
                pq.pop();
            }

            // moving from stack to pq , (el waiting for first greater now waits for second greater )
            while(!st.empty() && nums[st.top()] < nums[i]){
                pq.push({nums[st.top()] , st.top()});
                st.pop();
            }

            // adding indices of element to stack to wait for first greater
            st.push(i);
        }

        return ans;
    }
};