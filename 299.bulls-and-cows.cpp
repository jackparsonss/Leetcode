/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        unordered_map<char, int> m1;
        for (int i = 0; i < secret.size(); i++){
            m1[secret[i]]++;
        }
        
        for (int i = 0; i < secret.size(); i++){
            if(m1[guess[i]] > 0){
                m1[guess[i]]--;
                cows++;
            }
            if(secret[i] == guess[i]) {
                bulls++;
            }
        }

        return to_string(bulls) + "A" + to_string(cows-bulls) + "B";
    }
};
// @lc code=end

