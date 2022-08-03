class Solution {
public:
//     int f(int ind, int prevInd,vector<int>& nums, int n,vector<vector<int>> &dp )
//     {
//         if (ind == n) return 0;
//         if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        
//         //not take
//         int len = 0+f(ind+1,prevInd,nums,n,dp);
//         //take 
//         if(prevInd == -1 || nums[ind] > nums[prevInd])
//             len = max(len,1+ f(ind+1,ind,nums,n,dp));
        
//         return dp[ind][prevInd+1] = len;
//     }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind =n-1;ind>=0;ind--)
        {
            for(int prevInd=ind-1;prevInd>= -1;prevInd--)
            {
                //not take
                int len = 0+dp[ind+1][prevInd+1];
                //take 
                if(prevInd == -1 || nums[ind] > nums[prevInd])
                    len = max(len,1+ dp[ind+1][ind+1]);

                dp[ind][prevInd+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};