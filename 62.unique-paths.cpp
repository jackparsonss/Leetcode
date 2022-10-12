/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n));
        memo[0][0] = 0;

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                memo[i][j] = memo[i-1][j] + memo[i][j-1] + 1;
            }
        }
        return memo[m-1][n-1]+1;
    }
};
// @lc code=end

