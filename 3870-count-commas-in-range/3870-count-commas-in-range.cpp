class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        long long start = 1;
        int commas = 0;

        while (true) {
            long long end = start * 1000 - 1;
            if (n < start) break;

            long long upper = min((long long)n, end);
            long long count = upper - start + 1;

            ans += count * commas;

            start *= 1000;
            commas++;
        }
        return (int)ans;
    }
};
