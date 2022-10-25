/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            check(i, i, res, s);
            check(i, i+1, res, s); // even case
        }
        return res;
    }

    void check(int i, int j, int& res, string s) {
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            res++;
            i--;
            j++;
        }
    }
};
// @lc code=end

