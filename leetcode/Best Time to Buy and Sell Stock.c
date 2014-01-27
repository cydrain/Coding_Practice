/*
 * Best Time to Buy and Sell Stock
 *
 * Say you have an array for which the ith element is the price
 * of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction
 * (ie, buy one and sell one share of the stock), design an
 * algorithm to find the maximum profit.
 *
 */

    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2) return 0;
        int minval = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minval = min(minval, prices[i]);
            profit = max(profit, prices[i] - minval);
        }
        return profit;
    }
