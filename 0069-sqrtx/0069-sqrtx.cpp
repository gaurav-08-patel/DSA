class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        int low  = 0, high = x;

        while(low <= high){
            int mid = (low+high)/2;
            if((long long)mid*mid <= x){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }
};