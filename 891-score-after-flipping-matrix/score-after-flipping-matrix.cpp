class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Step 1: Ensure first column is all 1s
        for(int i=0; i<rows; i++){
            if(grid[i][0] == 0){
                for(int j=0; j<cols; j++) grid[i][j] ^= 1; // flip row
            }
        }

        // Step 2: For each column, maximize number of 1s
        for(int j=1; j<cols; j++){
            int count1 = 0;
            for(int i=0; i<rows; i++){
                if(grid[i][j] == 1) count1++;
            }
            int count0 = rows - count1;
            if(count0 > count1){ // flip column
                for(int i=0; i<rows; i++) grid[i][j] ^= 1;
            }
        }

        // Step 3: Calculate final score
        int ans = 0;
        for(int i=0; i<rows; i++){
            int val = 0;
            for(int j=0; j<cols; j++){
                val = val*2 + grid[i][j];
            }
            ans += val;
        }

        return ans;
    }
};