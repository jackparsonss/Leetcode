/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, amount+1);
        memo[0] = 0;

        for(int i = 1; i <= amount; i++) {
            for(int c: coins) {
                if(i - c >= 0) {
                    memo[i] = min(memo[i], 1 + memo[i-c]);
                }
            }
        }
        if(memo[amount] == amount+1) {
            return -1;
        }
        return memo[amount];
    }
};
// @lc code=end

