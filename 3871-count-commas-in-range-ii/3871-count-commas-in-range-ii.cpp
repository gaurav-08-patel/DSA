#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1;
        int commas = 0;

        while (true) {
            // Prevent overflow before multiplying
            if (start > LLONG_MAX / 1000) break;

            long long end = start * 1000 - 1;
            if (n < start) break;

            long long upper = min(n, end);
            long long count = upper - start + 1;

            ans += count * commas;

            start *= 1000;
            commas++;
        }
        return ans;
    }
};
