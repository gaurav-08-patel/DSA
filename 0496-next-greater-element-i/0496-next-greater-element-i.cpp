class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        stack<int> st;

        //create map for all elemmt of nums2 having greater num 
        for(int n : nums2){
            //use while not if because there can be multiple element less than  n
            while(!st.empty() && st.top() < n){
                mpp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        //all remaining ele in stack will have no greater element 
        while(!st.empty()){
            mpp[st.top()] = -1;
            st.pop();
        }

        vector<int> result;

        for(int n  : nums1){
            result.push_back(mpp[n]);
        }

        return result;
    }
};