/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }

        vector<int> memo(n);
        memo[0] = 1;
        memo[1] = 2;
        for (int i = 2; i < n; i++){
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n-1];
    }
};
// @lc code=end

