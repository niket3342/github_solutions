class Solution {
public:
    int minPartitions(string n) {
        int maxele = 0;
        for(auto c:n)
        {
            maxele = max(maxele, c-'0');
        }
        return maxele;
        
    }
};