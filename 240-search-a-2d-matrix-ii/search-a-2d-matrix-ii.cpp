class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool hmm = false;
        int i = 0;
        int j = matrix[0].size() - 1;
        while(hmm == false){
            if(matrix[i][j]==target){
                hmm = true;
            }
            else if(matrix[i][j]<target) i++;
            else if(matrix[i][j]>target) j--;

            if(i >= matrix.size() || j < 0) break;
        }

        return hmm;
    }
};