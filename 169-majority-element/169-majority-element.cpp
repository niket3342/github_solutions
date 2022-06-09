class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(auto a:nums ) m[a]++;
        for(auto a:m)
        if(a.second > n/2) return a.first;
        return -1;
        
    }
};