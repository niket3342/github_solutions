class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else
        {
        int fibsum = 0;
        fibsum = fib(n-1)+fib(n-2);
        return fibsum;
        }
            
        
    }
};