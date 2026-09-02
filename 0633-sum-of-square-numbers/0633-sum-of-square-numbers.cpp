class Solution {
public:
    bool judgeSquareSum(int c) {
        // two pointer approach
        long a = 0, b = (long) sqrt(c);

        while(a <= b){
            long sum = a*a + b*b;
            if(sum == c ) return true; // found solution
            else if(sum < c) a++; // need bigger number
            else b--; // need smaller number
        }

        return false;
    }
};