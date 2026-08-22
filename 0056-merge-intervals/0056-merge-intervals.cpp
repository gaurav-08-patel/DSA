class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //****************BRUTE/BETTER solution******************
        // int n = intervals.size();
        // vector<vector<int>> ans;
        // sort(intervals.begin(),intervals.end());

        // for(int i=0; i<n; i++){
        //     int first = intervals[i][0];
        //     int end = intervals[i][1];
            
        //     if(!ans.empty() && ans.back()[1] >= end) continue; // move to next if already in interval

        //     for(int j=i+1; j<n; j++){
        //         if(intervals[j][0] <= end){
        //             end = max(end,intervals[j][1]);
        //         }else break;
        //     }
        //     ans.push_back({first,end});
        // }
        
        // return ans;



        //************OPTIMAl approach***************
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        for(int i=0; i<n; i++){
            int first = intervals[i][0];
            int end = intervals[i][1];

            if(ans.empty() || ans.back()[1] < first){ // add new interval if curr inteval and one in interval doesnt overlap
                ans.push_back({first,end});
            }else{
                ans.back()[1] = max(end,ans.back()[1]); // otherwise keep updating its end with curr intervals end but with max
            }

        }

        return ans;
    }
};