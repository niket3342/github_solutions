class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(auto a : nums)
            m[a]++;
        
        for(auto b : m)
            if(b.second > n/2) return b.first;
        
        return -1;
        
    }
};