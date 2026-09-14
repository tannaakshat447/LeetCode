class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n*n);
        vector<int> ans;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                v[grid[i][j]-1]++;
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i] == 2) ans.push_back(i+1);
        }
        for(int i=0;i<v.size();i++){
            if(v[i] == 0) ans.push_back(i+1);
        }

        return ans;
    }
};