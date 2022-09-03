class Solution {
    
    void dfs(int num, int n, int K, vector<int>& result){
        if(n==0) {
            result.push_back(num);
            return;
        }
        int last_digit = num%10;
        if(last_digit >= K) dfs(num*10 + last_digit -K, n-1, K, result);
        if(K > 0 && last_digit + K < 10) dfs(num*10 + last_digit +K, n-1, K, result);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        if(n==1) result.push_back(0);
        for(int d=1;d<10; ++d)
            dfs(d, n-1,k, result);
        
        return result;
    }
};