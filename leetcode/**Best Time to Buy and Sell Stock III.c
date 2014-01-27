/*
 * Best Time to Buy and Sell Stock III
 *
 * Say you have an array for which the ith element is the price of
 * a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete
 * at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie,
 * you must sell the stock before you buy again).
 *
 */

    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if (n < 2) return 0;
        
        vector<int> history(n, 0);
        vector<int> future(n, 0);
        int low, high;
        int profit = 0;
        int i;
        
        low = prices[0];
        for (i = 1; i < n; i++) {
            low = min(low, prices[i]);
            history[i] = max(history[i-1], prices[i]-low);
        }
        
        high = prices[n-1];
        for (i = n-2; i >= 0; i--) {
            high = max(high, prices[i]);
            future[i] = max(future[i+1], high-prices[i]);
            
            profit = max(profit, history[i]+future[i]);
        }
        
        return profit;
    }
