class Solution {
public:
    
//     int f(int ind, vector<int>& arr, int k, vector<int> &dp)
//     {
//         int n = arr.size();
        
//         if(ind == n) return 0;
        
//         if(dp[ind] != -1) return dp[ind];
//         int maxi = INT_MIN;
//         int maxans = INT_MIN;
//         int len = 0;
        
//         for(int j= ind; j<min(n,ind+k);j++)
//         {
//             len++;
//             maxi = max(maxi, arr[j]);
//             int sum = maxi*len + f(j+1,arr,k,dp);
//             maxans= max(maxans, sum);
//         }
//         return dp[ind] = maxans;
//     }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int ind = n-1;ind>=0;ind--)
        {
            int maxi = INT_MIN;
            int maxans = INT_MIN;
            int len = 0;

            for(int j= ind; j<min(n,ind+k);j++)
            {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = maxi*len + dp[j+1];
                maxans= max(maxans, sum);
            }
            dp[ind] = maxans;
            
        }
        
        return dp[0];
        
    }
};