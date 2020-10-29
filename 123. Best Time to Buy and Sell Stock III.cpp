class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int daysCount = prices.size();
        if(daysCount <= 1)
        {
            return 0;
        }
        int k = 2;  // maximum number of transactions allowed
        int profit[k+1][daysCount];
        
        // There will be no profit if allowed transactions are 0 (k == 0)
        for(int day = 0;day<daysCount;day++)
        {
            profit[0][day] = 0;
        }
        
        // There will be no profit on day 0
        for(int trans = 0;trans <=k ;trans++)
        {
            profit[trans][0] = 0;
        }
        
        // Now computing if maximum k transactions are allowed
        // Logic is somewhere similar to 0/1 Knapsack
        for(int trans = 1;trans<=k;trans++)
        {
            int maxDifSoFar = INT_MIN;
            for(int cur_day = 1;cur_day<daysCount;cur_day++)
            {
                maxDifSoFar = max(maxDifSoFar,profit[trans-1][cur_day-1]-prices[cur_day-1]);
                profit[trans][cur_day] = max(profit[trans][cur_day-1],prices[cur_day]+maxDifSoFar);
            }
        }
        return profit[k][daysCount-1];
    }
};
