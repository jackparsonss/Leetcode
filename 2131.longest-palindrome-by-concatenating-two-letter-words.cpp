/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        int count = 0;
        int d_count = 0;
        for(string word: words) {
            if(word[0] == word[1]) {
               m[word]++;
               if(m[word] % 2 == 0) {
                    d_count--;
                    count += 4;
               } else {
                    d_count++;
               }
            }
            string temp = word;
            m[word]++;
            reverse(temp.begin(), temp.end());
            if(m.find(temp) != m.end() && m[word] <= m[temp]) {
                count += 4;
            }
        }
        if(d_count > 1) {
            count += 2;
        }
        return count;
    }
};
// @lc code=end

