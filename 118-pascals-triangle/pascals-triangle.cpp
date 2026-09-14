class Solution {
public:
    long long comb(int n, int r) {
        long long res = 1;
        for(int i = 0; i < r; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i = 0; i < numRows; ++i) {
            vector<int> row;
            for(int j = 0; j <= i; ++j) {
                row.push_back(static_cast<int>(comb(i, j)));
            }
            v.push_back(row);
        }
        return v;
    }
};