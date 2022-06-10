class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);//a vector of size 256 bcoz a string can have 256 diff characters ini to -1
        int left=0, right=0;
        int n=s.size();
        int len = 0;//initializing length of longest substring to 0
        while(right<n)//we will iterate until right index is smaller than last index
        {
            if(mpp[s[right]] != -1)//1st we check whether character at right index exist or not
            {
                left = max(mpp[s[right]] + 1,left);//we will update left only when ele at right is greater
            }
            mpp[s[right]] = right;
            len = max(len, right-left+1);//set the new len if it is greater thsn previoud
            right++;//inrement right;
        }
        return len;
        
    }
};