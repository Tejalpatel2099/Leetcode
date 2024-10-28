class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();

        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n - 1; j++) {
        //         int profit = prices[j] - prices[i];

        //         if (profit > maxProfit) {
        //             maxProfit = profit;
        //         }
        //     }
        // }
        // return maxProfit;

        int temp[n];
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                temp[i] = prices[i];
            } else {
                if (prices[i] > temp[i + 1]) {
                    temp[i] = prices[i];
                } else {
                    temp[i] = temp[i + 1];
                }
            }
        }
        for (int i = 0; i < n; i++) {

            int Profit = temp[i] - prices[i];

            if (Profit > maxProfit) {
                maxProfit = Profit;
            }
        }
           return maxProfit;
    }
};