class Solution {
public:
    long long int helper(vector<int>& nums,int low, int high) 
    {
        int n = nums.size();
        int prev1 = nums[low];
        int prev2 = 0;
        for(int i=low+1;i<=high;i++)
        {
            int take = nums[i];
            if(i>1) take+=prev2;
            
            int notTake = 0+prev1;
            
            int curri = max(take, notTake);
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
        
    }
    
    long long int rob(vector<int>& nums) 
    {
        //vector<int> temp1, temp2;
        int n = nums.size();
        if(n==1) return nums[0];
        int m1=helper(nums,0,n-2);
        int m2=helper(nums,1,n-1);
        return max(m1, m2);
        
    }    
};