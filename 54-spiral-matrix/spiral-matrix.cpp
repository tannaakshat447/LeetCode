class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int minr = 0;
        int maxr = (n-1);
        int minc = 0;
        int maxc = (m-1);
        vector<int> sol;

        for(int i=1;i<=(n*m);){
            bool flag = false;
            for(int a=minc;a<=maxc && i<=(n*m); a++){              // rightwards
                sol.push_back(matrix[minr][a]);
                i++;
            }
            minr++;
            for(int b=(minr);b<=maxr && i<=(n*m);b++){              // downwards
                sol.push_back(matrix[b][maxc]);
                i++;
            }
            maxc--;
            for(int c=(maxc);c>=minc && i<=(n*m);c--){              // leftwards
                sol.push_back(matrix[maxr][c]);
                i++;
            }
            maxr--;
            for(int d=(maxr);d>=minr && i<=(n*m);d--){              // upwards
                sol.push_back(matrix[d][minc]);
                i++;
            }
            minc++;
        }

        return sol;
   }
};