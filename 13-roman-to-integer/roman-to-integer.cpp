class Solution {
public:
    int romanToInt(string s) {
        map<char, int> val;
        val.insert({'I', 1});
        val.insert({'V', 5});
        val.insert({'X', 10});
        val.insert({'L', 50});
        val.insert({'C', 100});
        val.insert({'D', 500});
        val.insert({'M', 1000});

        int n = s.size();
        int ans = val[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(val[s[i]]<val[s[i+1]]) ans-=val[s[i]];
            else ans+=val[s[i]];
        }

        return ans;
    }
};