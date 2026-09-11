class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        int countValid = 0;
        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0) continue; // must be even

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> need(10, 0);
            need[a]++; need[b]++; need[c]++;

            bool ok = true;
            for (int d = 0; d < 10; d++) {
                if (need[d] > freq[d]) {
                    ok = false;
                    break;
                }
            }
            if (ok) countValid++;
        }
        return countValid;
    }
};
