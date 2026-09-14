class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex + 1);
        v[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            v[i] = (long long)v[i - 1] * (rowIndex - i + 1) / i;
        }
        return v;
    }
};