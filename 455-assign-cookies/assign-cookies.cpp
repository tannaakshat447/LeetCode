class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // index for greed factors (children)
        int j = 0; // index for cookie sizes
        int cnt = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++;
                j++;
                cnt++;
            } else {
                j++; // Advance to a larger cookie if current cookie is too small
            }
        }
        return cnt;
    }
};