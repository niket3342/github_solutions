class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //This approach use extra space so  not acceptable
        int n = nums.size(), ans;
        sort(nums.begin(), nums.end());
        vector<int> freq(n+1,0);
        for(int i=0;i <n;i++)
        {
            if(freq[nums[i]] == 0) freq[nums[i]] += 1;
            else ans = nums[i];
        }
        return ans;
    }
};