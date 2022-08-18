class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int, int> m;
        for(int x:arr) ++m[x];
        vector<int> freq;
        for(auto[_, f]: m) freq.push_back(f);
        sort(freq.begin(), freq.end());
        
        int ans = 0, removed = 0, half = arr.size()/2, i = freq.size()-1;
        while(removed<half)
        {
            ans+=1;
            removed += freq[i--];
        }
        
        
        return ans;
        
        //APPROACH
        // *Using HashMap to count the frequency of each numbers.
        // *Get array of the frequency, let name it frequencies.
        // *Sort frequencies in increasing order.
        // *We prioritize removing the numbers with the largest frequency first, until we've eliminated at              least half of the arr.
        // *Return the number of numbers removed.
        
        
        
    }
};