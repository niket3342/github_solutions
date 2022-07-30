class Solution {
public:
    bool help(int f[], int mf[])
    {
        for(int i=0; i<26;i++)
        {
            if(f[i]<mf[i])
                return false;
            
        }
        return true;
        
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int mf[26] = {0};
        for(string s:words2)
        {
            int f[26]={0};
            for(char ch:s)
                f[ch-'a'] += 1;
            for(int i=0;i<26;i++)
            {
                mf[i]=max(mf[i], f[i]);
            }
        }
        for(string s:words1)
        {
            int f[26]={0};
            for(char ch:s)
                f[ch-'a'] += 1;
            if (help(f,mf))
            {
                ans.push_back(s);
            }
        }
        return ans;
        
    }
};