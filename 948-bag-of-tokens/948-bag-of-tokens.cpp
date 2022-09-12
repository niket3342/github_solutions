class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r= tokens.size()-1;
        int score =0, maxscore = 0;
        while(l<=r)
        {
            if(tokens[l] <= power)
            {
                power -= tokens[l++];
                score++;
                maxscore = max(maxscore, score);
            }
            else if(score>0)
            {
                power += tokens[r--];
                score--;
            }
            else break;
        }
        return maxscore;
    }
};