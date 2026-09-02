class Solution {
public:
    //confusing problem , didnt get it 
    int reachNumber(int target) {
        target = abs(target); // symmetry
        long long sum = 0;
        int steps = 0;
        
        while (sum < target || (sum - target) % 2 != 0) {
            steps++;
            sum += steps;
        }
        
        return steps;
    }
};
