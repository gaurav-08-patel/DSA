class Solution {
public:
    static const int MAXK = 5;

    struct Node {
        int end[MAXK];
        int cnt[MAXK][MAXK];

        Node() {
            for (int i = 0; i < MAXK; i++) {
                end[i] = 0;
                for (int j = 0; j < MAXK; j++) {
                    cnt[i][j] = 0;
                }
            }
        }
    };

    int k;
    int n;
    int size;
    vector<Node> tree;

    Node makeLeaf(int v) {
        Node res;

        int vm = v % k;

        for (int m = 0; m < k; m++) {
            int e = (m * vm) % k;

            res.end[m] = e;
            res.cnt[m][e] = 1;
        }

        return res;
    }

    Node identity() {
        Node res;

        for (int m = 0; m < k; m++) {
            res.end[m] = m;
        }

        return res;
    }

    inline Node combine(const Node& L, const Node& R) {
        Node res;

        for (int m = 0; m < k; m++) {
            int mid = L.end[m];

            res.end[m] = R.end[mid];

            for (int x = 0; x < k; x++) {
                res.cnt[m][x] =
                    L.cnt[m][x] +
                    R.cnt[mid][x];
            }
        }

        return res;
    }

    void update(int pos, int value) {
        int p = size + pos;

        tree[p] = makeLeaf(value);

        p >>= 1;

        while (p > 0) {
            tree[p] = combine(tree[p << 1], tree[p << 1 | 1]);
            p >>= 1;
        }
    }

    Node querySuffix(int start) {
        Node leftResult = identity();
        Node rightResult = identity();

        int l = size + start;
        int r = size + n;

        while (l < r) {
            if (l & 1) {
                leftResult = combine(leftResult, tree[l]);
                l++;
            }

            if (r & 1) {
                --r;
                rightResult = combine(tree[r], rightResult);
            }

            l >>= 1;
            r >>= 1;
        }

        return combine(leftResult, rightResult);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k_,
        vector<vector<int>>& queries
    ) {
        k = k_;
        n = nums.size();

        // Next power of 2
        size = 1;
        while (size < n) {
            size <<= 1;
        }

        tree.resize(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            tree[size + i] = makeLeaf(nums[i]);
        }

        // Remaining leaves are identity
        Node id = identity();

        for (int i = n; i < size; i++) {
            tree[size + i] = id;
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
        }

        vector<int> result;
        result.reserve(queries.size());

        int startMultiplier = 1 % k;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Point update
            update(index, value);

            // Query [start, n - 1]
            Node res = querySuffix(start);

            result.push_back(res.cnt[startMultiplier][x]);
        }

        return result;
    }
};