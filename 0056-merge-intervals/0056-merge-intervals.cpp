class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        for(int i=0; i<n; i++){
            int first = intervals[i][0];
            int end = intervals[i][1];
            
            if(!ans.empty() && ans.back()[1] >= end) continue;

            for(int j=i+1; j<n; j++){
                if(intervals[j][0] <= end){
                    end = max(end,intervals[j][1]);
                }else break;
            }
            ans.push_back({first,end});
        }
        
        return ans;
    }
};