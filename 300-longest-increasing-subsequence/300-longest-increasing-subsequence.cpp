class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n,1);
        // int maxi=1;
        // for(int i=0;i<n;i++)
        // {
        //     for(int prev=0;prev<i;prev++)
        //     {
        //         if(nums[prev] <nums[i])
        //         {
        //             dp[i] = max(dp[i], 1+dp[prev]);
        //         }
        //     }
        //     maxi = max(maxi,dp[i]);
        // }
        // return maxi;
        
        
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            auto it = std:: lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};