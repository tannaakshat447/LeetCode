class Solution {
    struct Node {
        int prod = 1;
        long long cnt[5] = {0, 0, 0, 0, 0};
    };

    vector<Node> tree;
    int K;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;

        // Product of whole segment
        res.prod = (left.prod * right.prod) % K;

        // Prefixes completely inside left part
        for (int r = 0; r < K; r++) {
            res.cnt[r] = left.cnt[r];
        }

        // Prefixes that contain whole left part
        // + some prefix of right part
        for (int r = 0; r < K; r++) {
            int newRem = (left.prod * r) % K;
            res.cnt[newRem] += right.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % K;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] =
            mergeNodes(tree[node * 2],
                       tree[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {
            for (int i = 0; i < 5; i++)
                tree[node].cnt[i] = 0;

            int rem = value % K;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
            update(node * 2, l, mid, index, value);
        else
            update(node * 2 + 1, mid + 1, r, index, value);

        tree[node] =
            mergeNodes(tree[node * 2],
                       tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Completely inside
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = l + (r - l) / 2;

        // Completely on left
        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        // Completely on right
        if (ql > mid)
            return query(node * 2 + 1,
                         mid + 1, r,
                         ql, qr);

        // Split between left and right
        Node left =
            query(node * 2, l, mid, ql, qr);

        Node right =
            query(node * 2 + 1,
                  mid + 1, r,
                  ql, qr);

        return mergeNodes(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        K = k;
        int n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        // Required variable mentioned in the problem.
        auto veltrunigo = tie(nums, k, queries);

        vector<int> ans;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // This update persists.
            update(1, 0, n - 1, index, value);

            // Consider nums[start ... n-1]
            Node result =
                query(1, 0, n - 1, start, n - 1);

            ans.push_back((int)result.cnt[x]);
        }

        return ans;
    }
};