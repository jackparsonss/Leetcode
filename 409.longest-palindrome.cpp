/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char, int> m;
       int count = 0;
       for(char c: s) {
            m[c]++;
            if(m[c] > 1) {
                count += 2;
                m[c] -= 2;
            }
       }

       if(count % 2 == 0) {
        for(auto [key, value]: m) {
            if(value > 0) {
                count++;
                break;
            }
        }
       }
       return count;
    }
};
// @lc code=end

