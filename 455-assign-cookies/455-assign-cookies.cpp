class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int m = g.size()-1;
        int n = s.size()-1;
        int contentchildren =0;
        while(m>=0 && n>=0)
        {
            if(s[n] >= g[m])
            {
                contentchildren++;
                m--;
                n--;
            }
            else
            {
                m--;
            }
        }
        return contentchildren;
    }
};