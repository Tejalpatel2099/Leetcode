// Try every possible pair of days — buy on day i, sell on day j where j > i —
// and track the maximum profit.
// time Complexity: O(n^2)
// Space Complexity: O(1)

// You're given a list of stock prices where prices[i] is the price of a stock
// on day i.
// You want to buy one day and sell on a later day to get the maximum profit.
// Return the maximum profit you can achieve. If you can't make a profit, return
// 0.

// so, here i will intitalize minprice for very large number. Then i will
// maxProfit = 0; and i will check if current Price < minprice then i will
// update minprice and same for max profit Time Complexity: O(n) — We traverse
// the array once.
// Space Complexity: O(1) — We only use two variables, minPrice and maxProfit.

// Approach Summary: Greedy
// Why Greedy? Because we only care about the minimum price so far and the best
// profit we can get from today’s price — we don’t backtrack or consider all
// pairs. We try to buy at the lowest price seen so far, and sell at the current
// price if it gives the best profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the minimum price to a very large value (infinity)
        // This helps us track the lowest price seen so far
        int minPrice = prices[0];

        // Initialize maxProfit to 0
        // We assume no profit at the beginning
        int maxProfit = 0;

        // Traverse the price array from day 0 to the last day
        for (int i = 1; i < prices.size(); i++) {
            // If the current price is less than the minimum price we've seen
            // we update minPrice to this new lower value
            if (prices[i] > minPrice) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
            // Else, we check if selling on this day would give us more profit
            // than we've recorded so far. If yes, update maxProfit
            minPrice = min(minPrice, prices[i]);
        }

        // After checking all days, return the maximum profit found
        return maxProfit;
    }
};

//  greedy approach where TC ;- O(n) and sc := O(1).