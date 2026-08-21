class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            int curr_height = min(height[left], height[right]);
            int width = right - left;
            max_area = max(max_area, width * curr_height);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};