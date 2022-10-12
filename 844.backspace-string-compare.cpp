/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
#include<string>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1; 
        stack<char> s2;

        for(char c: s) {
            if(c == '#' && !s1.empty()){
                s1.pop();
            } else {
                if(c != '#'){
                    s1.push(c);
                }
            }
        } 
        for(char c: t) {
            if(c == '#' && !s2.empty()){
                s2.pop();
            } else {
                if(c != '#') {
                    s2.push(c);
                }
            }
        } 

        return s1 == s2;
    }
};
// @lc code=end

