/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        unordered_map<char, int> m;
        int ans = INT_MIN, left = 0, right = 0;
        while(right < s.size()) {
            m[s[right]]++;
            int temp = right - left + 1;
            if(m.size() == temp) {
                ans = max(ans, temp);
            } else if(m.size() < temp) {
                while(m.size() < right - left + 1) {
                    m[s[left]]--;
                    if(m[s[left]] == 0) {
                        m.erase(s[left]);
                    }
                    left++;
                }
            }
            right++;
        }
        return ans;
    }
};
// @lc code=end

