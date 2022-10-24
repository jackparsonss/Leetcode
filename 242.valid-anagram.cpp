/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) 
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

