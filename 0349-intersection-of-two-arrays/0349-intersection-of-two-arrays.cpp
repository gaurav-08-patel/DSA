class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> result;

        for(int n : nums2){
            if(set1.count(n)){
                result.insert(n);
            }
        }
        return vector<int>(result.begin(),result.end());
    }
};