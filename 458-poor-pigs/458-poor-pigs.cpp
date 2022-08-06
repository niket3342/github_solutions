class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int trial = minutesToTest/minutesToDie;
        int ans = ceil(log(buckets) / log(trial+1));
        return ans;
        
    }
};