class Solution {
    bool dfs(vector<int> &sidesLength,const vector<int> &matchsticks, int index, const int target) {
        if (index == matchsticks.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matchsticks[index] > target) // first
                continue;
            int j = i;
            while (--j >= 0) // third
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matchsticks[index];
            if (dfs(sidesLength, matchsticks, index + 1, target))
                return true;
            sidesLength[i] -= matchsticks[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int sum = 0;
        for (const int val: matchsticks ) {
            sum += val;
        }
        if (sum % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(), [](const int &l, const int &r){return l > r;}); // second
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, matchsticks, 0, sum / 4);
    }
};