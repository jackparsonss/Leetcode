/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */
#include<string>
#include<unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, char> m2;

        for(int i = 0; i < s.size(); i++) {
            if(m.find(s[i]) == m.end()) {
                if(m2.find(t[i]) != m2.end()) {
                    return false;
                }
                m[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else {
                if(m[s[i]] != t[i] || m2[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

