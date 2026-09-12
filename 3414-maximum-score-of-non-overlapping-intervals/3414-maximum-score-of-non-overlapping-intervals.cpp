class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& input) {
        int n = input.size();
        // each entry: l, r, w, originalIndex
        vector<array<long long,4>> iv(n);
        for (int i = 0; i < n; ++i)
            iv[i] = { input[i][0], input[i][1], input[i][2], i };

        sort(iv.begin(), iv.end(), [](const array<long long,4>& a, const array<long long,4>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[1] != b[1]) return a[1] < b[1];
            if (a[2] != b[2]) return a[2] < b[2];
            return a[3] < b[3];
        });

        vector<long long> lefts(n);
        for (int i = 0; i < n; ++i) lefts[i] = iv[i][0];

        // W[i][q]   = best score using sorted intervals[i..n) with at most q picks
        // Sel[i][q] = sorted list of ORIGINAL indices achieving that score
        //             (lexicographically smallest among all optimal choices)
        vector<array<long long,5>> W(n + 1);
        vector<array<vector<int>,5>> Sel(n + 1);
        for (int q = 0; q <= 4; ++q) W[n][q] = 0; // Sel[n][*] stays empty

        for (int i = n - 1; i >= 0; --i) {
            W[i][0] = 0; // Sel[i][0] stays empty

            long long r = iv[i][1];
            long long w = iv[i][2];
            int origIdx = (int)iv[i][3];

            // first sorted index j > i with l[j] > r
            // (strict: sharing an endpoint counts as overlap)
            int lo = i + 1, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (lefts[mid] > r) hi = mid; else lo = mid + 1;
            }
            int j = lo;

            for (int q = 1; q <= 4; ++q) {
                long long skipW = W[i + 1][q];
                const vector<int>& skipSel = Sel[i + 1][q];

                long long pickW = w + W[j][q - 1];
                vector<int> pickSel = Sel[j][q - 1];
                pickSel.push_back(origIdx);
                sort(pickSel.begin(), pickSel.end());

                bool takePick = (pickW > skipW) ||
                                (pickW == skipW && pickSel < skipSel);

                if (takePick) {
                    W[i][q]   = pickW;
                    Sel[i][q] = move(pickSel);
                } else {
                    W[i][q]   = skipW;
                    Sel[i][q] = skipSel;
                }
            }
        }

        return Sel[0][4];
    }
};