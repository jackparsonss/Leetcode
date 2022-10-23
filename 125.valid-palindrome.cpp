/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(!isalpha(s[l]) && !isdigit(s[l])) {
                l++;
                continue;
            }
            if(!isalpha(s[r]) && !isdigit(s[r])) {
                r--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r])){
                return false; 
            }
            l++;
            r--;
        } 
        return true;
    }
};
// @lc code=end

