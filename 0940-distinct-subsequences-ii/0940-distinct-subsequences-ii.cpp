class Solution {
public:
//dont know how to solve , just copied
    int distinctSubseqII(string s) {
        const int MOD = 1'000'000'007;
        vector<long> endsIn(26, 0);
        
        for(char c : s) {
            long total = 0;
            for(long val : endsIn) total = (total + val) % MOD;
            endsIn[c - 'a'] = (total + 1) % MOD;
        }
        
        long result = 0;
        for(long val : endsIn) result = (result + val) % MOD;
        return (int)result;
    }
};
