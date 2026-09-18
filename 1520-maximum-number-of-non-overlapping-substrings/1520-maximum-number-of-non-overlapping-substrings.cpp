class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals; // (start, end)

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] != i) continue; // only start at a char's first occurrence

            int start = i, end = last[c];
            bool valid = true;

            int k = i;
            while (k <= end) {
                int ck = s[k] - 'a';
                if (first[ck] < start) {
                    valid = false;
                    break;
                }
                if (last[ck] > end) {
                    end = last[ck];
                }
                k++;
            }

            if (valid) {
                intervals.push_back({start, end});
            }
        }

        // Sort by end index (earliest finish time greedy)
        sort(intervals.begin(), intervals.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.second < b.second;
             });

        vector<string> res;
        int prevEnd = -1;

        for (auto& [start, end] : intervals) {
            if (start > prevEnd) {
                res.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }

        return res;
    }
};