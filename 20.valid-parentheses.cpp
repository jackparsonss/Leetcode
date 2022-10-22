/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include<string>
#include<stack>
#include<iostream>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        for(char c: s) {
            if(m.find(c) != m.end()){
                st.push(c);
                continue;
            }

            if(st.empty() || m[st.top()] != c) {
                return false;
            }

            st.pop();
        } 
        return st.empty();
    }
};
// @lc code=end

