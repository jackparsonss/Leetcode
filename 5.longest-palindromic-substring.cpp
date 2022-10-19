/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int out = 0, start = 0, n = s.size();

        for (int i = 0; i < n; i++){
            int len1 = check(s, i,i);
            int len2 = check(s, i, i+1);
            
            int len = max(len1, len2);
            
            if(len > out){
                out = len;
                start = i-(len-1)/2;
            }        
        }

        return s.substr(start, out);
    }

    int check(string s, int L, int R){
        while(L >= 0 and R < s.length() and s[L] == s[R]){
            L--;
            R++;
        }

        return R-L-1;
    }
};
// @lc code=end

