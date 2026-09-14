class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr[150];
        int brr[150];
        for(int i=0;i<150;i++){
            arr[i] = INT_MAX;
            brr[i] = INT_MAX;
        }
        bool flag = true;

        for(int i=0;i<s.size();i++){
            if(arr[int(s[i])] == INT_MAX){
                arr[int(s[i])] = s[i] - t[i];
            }
            else{
                if(arr[int(s[i])] != s[i] - t[i]) return false;
            }
        }

        for(int i=0;i<t.size();i++){
            if(brr[int(t[i])] == INT_MAX){
                brr[int(t[i])] = t[i] - s[i];
            }
            else{
                if(brr[int(t[i])] != t[i] - s[i]) return false;
            }
        }

        return true;
    }
};