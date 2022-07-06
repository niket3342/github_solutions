class Solution {
public:
    int fib(int n) {
        int prev1=1;
        int prev2 = 0;
        if (n==0 || n==1)
        return n;
    
    for (int i=1; i<n; i++) {
        int curr = prev1 + prev2;
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
            
        
    
};