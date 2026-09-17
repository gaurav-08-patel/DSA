class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // best[i] = length of the SHORTEST target-sum subarray ending at or before index i
        vector<int> best(n, INT_MAX);
        int left = 0, sum = 0, ans = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            while (sum > target) {          // shrink window (works since all values > 0)
                sum -= arr[left];
                ++left;
            }
            best[right] = (right > 0) ? best[right - 1] : INT_MAX;

            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && best[left - 1] != INT_MAX) {
                    // combine current window with the best target-sum window strictly to its left
                    ans = min(ans, best[left - 1] + len);
                }
                best[right] = min(best[right], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};