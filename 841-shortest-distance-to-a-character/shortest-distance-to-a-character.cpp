class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answer(s.size(), s.size());
        int n = s.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[j] == c){
                    answer[i] = min(answer[i], abs(i-j));
                }
            }
        }
        return answer;

    }
};