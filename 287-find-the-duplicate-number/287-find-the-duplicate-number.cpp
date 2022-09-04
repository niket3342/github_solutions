class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //This approach use extra space so  not acceptable
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow  = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        fast = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
};