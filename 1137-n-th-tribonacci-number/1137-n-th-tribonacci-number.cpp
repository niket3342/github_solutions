class Solution {
public:
int func(int ind, vector<int> &dp)
{
    // dp[0] = 0;
    //     dp[1] = 1;
    //     dp[2] = 1;
    
        if(ind==0) return 0;
        if(ind==1 || ind==2) return 1;
        if(dp[ind] != -1) return dp[ind];
        dp[ind] = func(ind-1,dp)+func(ind-2,dp)+func(ind-3,dp);
        return dp[ind];
}
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        
        
        
        return func(n,dp);
        
    }
};