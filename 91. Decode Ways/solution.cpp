class Solution {
public:

    // int recur(string s,int i,int* dp)
    // {
    //     if(i==s.size()) return 1;
    //     if(i>s.size() || s[i]=='0') return 0;

    //     if(dp[i]!=-1) return dp[i];
    //     if(s[i]=='1') return dp[i] = recur(s,i+2,dp)+recur(s,i+1,dp);
    //     if(s[i]=='2')
    //     {
    //         if(i+1<s.size() && s[i+1]<='6') return dp[i] = recur(s,i+2,dp)+recur(s,i+1,dp);
    //         else return dp[i] = recur(s,i+1,dp);
    //     }

    //     return dp[i] = recur(s,i+1,dp);
    // }
    int numDecodings(string s) {
        
        int n = s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n]=1;

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0') dp[i] = 0;
            else{ dp[i] += dp[i+1];

            if(i+1<n && s.substr(i,2)<="26") dp[i] += dp[i+2];}
        }
        return dp[0];
    }
};