class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        vector<int> v = {0,1};
        int ans;
        for(int i = 2;i<=n;i++){
            v.push_back(v[i-1] + v[i-2]);
            ans = v[i];
        }
        return ans;
    }
};