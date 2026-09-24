class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int digitSum = 0;
            while (val > 0) {
                digitSum += val % 10;
                val /= 10;
            }
            if (digitSum == i) {
                return i;
            }
        }
        return -1;
    }
};