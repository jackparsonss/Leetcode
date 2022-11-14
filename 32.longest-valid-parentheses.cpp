/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        unordered_map<char, char> m = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        int count = 0;
        int curr = 0;
        for(char c: s) {
            if(m.find(c) != m.end()){
                st.push(c);
                continue;
            }

            if(st.empty() || m[st.top()] != c) {
                curr = 0;
                continue;
            }

            curr += 2;
            count = max(count, curr);
            st.pop();
        } 
        return count;
    }
};
// @lc code=end

