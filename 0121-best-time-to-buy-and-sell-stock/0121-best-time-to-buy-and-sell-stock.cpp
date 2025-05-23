// You're given a list of stock prices where prices[i] is the price of a stock
// on day i.
// You want to buy one day and sell on a later day to get the maximum profit.
// Return the maximum profit you can achieve. If you can't make a profit, return
// 0.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};