//Can I assume all prices are positive?

// You're given a list of stock prices where prices[i] is the price of a stock
// on day i.
// You want to buy one day and sell on a later day to get the maximum profit.
// Return the maximum profit you can achieve. If you can't make a profit, return
// 0.

// /.................BRUTE FORCE...............
// Try every possible pair of days — buy on day i, sell on day j where j > i and so , profit = prices[j] - prices[i].
// and track the maximum profit.
// time Complexity: O(n^2) - check all pairs 
// Space Complexity: O(1) 

//.....................GREEDY APPRAOCH...............
// so, here i will intitalize minprice for very large number. Then i will initialize 
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

      // Start by setting min price to first day price 
      // this helps track lowest price i can buy so far. 
        int minPrice = prices[0];

    // start with 0 profit becuase i haven't made any transaction yet
        int maxProfit = 0;

      // loop through all days starting from second day 
        for (int i = 1; i < prices.size(); i++) {
            
            // if todays price is higher than min price it. means selling today could make a profit so i will check if this profit is greater than current maxProfit
            if (prices[i] > minPrice) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
            // i will always update minPrice if we find a smaller price so this will ensure that i am always buying at lowest price. 
           
            minPrice = min(minPrice, prices[i]);
        }

// after checking all days, maxprofit will hold the maximum profit.
        return maxProfit;
    }
};

//  greedy approach where TC ;- O(n) and sc := O(1).