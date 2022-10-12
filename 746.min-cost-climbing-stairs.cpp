/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];

        if(n <= 2) {
            return min(first, second);
        }

        for (int i = 2; i < n; i++){
           int temp = cost[i] + min(first, second);
           first = second;
           second = temp;
        }

        return min(first, second);
    }
};
// @lc code=end

