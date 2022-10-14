/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcs = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            lcs = longestCommonSubstr(lcs, strs[i]);
        }        
        return lcs;
    }

    string longestCommonSubstr(string s1, string s2) {
        int i = 0;
        while(i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
            i++;
        }
        if(s1.size() > s2.size()) {
            return s1.substr(0, i);
        } 
        return s2.substr(0, i);
    }
};
// @lc code=end

