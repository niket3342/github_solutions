class Solution {
public:
    bool isPowerOfFour(int num) {
        
        //here we check if the num is a power of 2 as any no. which is power of 4 must be a power of 2
        //by (num & (num - 1)) == 0
        //and we check if he num, is dividivle by 3 and gives remainder 0
        
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
        
    }
};