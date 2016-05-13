/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <math.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice1 = MAX_VALUE;  // +infinity
        int minPrice2 = 32767;  // +infinity
        int maxProfit1 = 0;
        int maxProfit2 = 0;
        for(int price : prices){ 
            // assume we only have 0 money at first
            maxProfit2 = max(maxProfit2, price - minPrice2); 
            minPrice2  = min(minPrice2,  price - maxProfit1); // !!!important_line
            maxProfit1 = max(maxProfit1, price - minPrice1);
            minPrice1  = min(minPrice1,  price); 
        }
        return release2; /// since import_line, so release2 will always higher than release1.
    }
};