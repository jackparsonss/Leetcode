/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

    void backtrack(vector<string> &ans, string curr, int open, int close, int max) {
        if(curr.size() == max * 2) {
            ans.push_back(curr);
            return;
        }

        if(open < max) {
            curr += "(";
            backtrack(ans, curr, open+1, close, max);
            curr.pop_back();
        }

        if(close < open) {
            curr += ")";
            backtrack(ans, curr, open, close+1, max);
            curr.pop_back();
        }
    }
};
// @lc code=end

