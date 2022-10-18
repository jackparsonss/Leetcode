/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int count = 0;
        for(char task: tasks) {
            m[task]++;
            count = max(count, m[task]);
        }
        int ans = (count-1) * (n+1);
        for(auto [key, value]: m) {
            if(value == count) {
                ans++;
            }
        }

        return max((int)tasks.size(), ans);
    }
};
// @lc code=end

