class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX, minEven = INT_MAX;
        for (int x : nums1) {
            if (x % 2 == 1) minOdd = min(minOdd, x);
            else minEven = min(minEven, x);
        }
        // Already uniform
        if (minOdd == INT_MAX || minEven == INT_MAX) return true;

        // Case 1: make all odd
        bool allOdd = true;
        for (int x : nums1) {
            if (x % 2 == 0) {
                if (x - minOdd < 1 || (x - minOdd) % 2 == 0) {
                    allOdd = false;
                    break;
                }
            }
        }

        // Case 2: make all even
        bool allEven = true;
        for (int x : nums1) {
            if (x % 2 == 1) {
                if (x - minEven < 1 || (x - minEven) % 2 == 1) {
                    allEven = false;
                    break;
                }
            }
        }

        return allOdd || allEven;
    }
};
