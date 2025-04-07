class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;  // Start with the highest possible number
    int maxProfit = 0; 

        for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minPrice)
            minPrice = prices[i];  // Found a lower price → better day to buy
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;  // Found a better profit → update max 
    }
        return maxProfit;
    }
};