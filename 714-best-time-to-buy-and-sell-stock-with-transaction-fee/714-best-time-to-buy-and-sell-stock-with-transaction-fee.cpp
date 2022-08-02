class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy, aheadNotBuy, curBuy,curNotBuy;
        aheadBuy = aheadNotBuy = 0;
        
        for(int ind =n-1;ind>=0;ind--)
        {
            //sell 
            curNotBuy = max(prices[ind] - fee+ aheadBuy, 0+aheadNotBuy);
            
            //buy
            curBuy = max(-prices[ind] + aheadNotBuy, 0+ aheadBuy);
            
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};