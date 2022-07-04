class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        vector<int> candies(n,1);
        //edge case
        if(n==1) return 1;
        
        //left to right  compare (i,i-1)
        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1] && candies[i] <= candies[i-1])
            {
                candies[i] = candies[i-1]+1;
            }
        }
        
        //right to left  compare(i,i+1)
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1] && candies[i] <= candies[i+1])
            {
                candies[i] = candies[i+1] + 1;
            }
        }
        
        int totalcandies = 0;
        for(int i=0;i<n;i++)
        {
            totalcandies+=candies[i];
        }
        return totalcandies;
    }
};