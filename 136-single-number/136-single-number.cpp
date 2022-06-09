class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto a:nums)m[a]++;//select numbers from nums and store them and increment the count corresponding to those numbers
        for(auto a:m) if (a.second !=2) return a.first;
        return -1;
        
    }
};