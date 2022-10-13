/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(128);
        int start = 0, largest = 0;

        for (int i = 0; i < s.size(); i++){
            largest = max(largest, ++arr[s[i]]);
            if(i - start + 1 - largest > k) {
                arr[s[start++]]--;
            }
        }
        

        return s.size() - start;
    }
};
// @lc code=end


