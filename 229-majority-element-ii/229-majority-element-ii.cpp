class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> res;
        for(auto a : nums)
            m[a]++;
        for(auto b: m)
            if(b.second > n/3) res.push_back(b.first);
        return res;
        
    }
};