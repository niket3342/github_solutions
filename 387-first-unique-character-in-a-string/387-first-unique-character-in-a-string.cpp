class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int, int>> m; //pair if of count and index of that char
        
        int idx = s.size();
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]].first++;  //increment the count of the character
            m[s[i]].second = i;  //set index of that char
            
        }
        for(const auto &[c,p]:m)
        {
            if(p.first == 1)//if count ==1
            {
                idx= min(idx,p.second); //set idx to index of that element
            }
        }
        return idx == s.size() ? -1 : idx; //if there is no such character then return -1
        
    }
};