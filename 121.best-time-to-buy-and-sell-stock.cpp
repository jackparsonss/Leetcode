/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m_price = INT_MAX, profit = 0;
        for(int price: prices) {
            if(price < m_price) {
                m_price = price;
            } else if(price - m_price > profit) {
                profit = price - m_price;
            }
        }
        return profit;
    }
};
// @lc code=end

