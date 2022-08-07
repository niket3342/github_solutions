class Solution {
public:
    
    bool isPaindrome(int i, int j, string &t)
    {
        
        while(i<j)
        {
            if(t[i]!=t[j]) return false;
            i++;j--;
            
        }
        return true;
    }
    
    int f(int i, int n,string &s,vector<int> &dp )
    {
        if(i==n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int mincost = INT_MAX;
        
        for(int j= i;j<n;j++)
        {
            if(isPaindrome(i,j,s))
            {
                int cost = 1+ f(j+1,n,s,dp);
                mincost = min(mincost, cost);
            }
        }
        return dp[i] = mincost;
    }
    
    int minCut(string s) 
    {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};