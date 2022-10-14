/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> seen;
        while(true){
            string s = to_string(n);
            int newn = 0;
            for(char c: s) {
                newn += (c - '0') * (c - '0');
            }
            n = newn;
            if(n == 1){
                return true;
            }

            if(seen[n]) {
                return false;
            }

            seen[n] = true;
        }
    }
};
// @lc code=end

