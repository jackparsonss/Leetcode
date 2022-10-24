/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++){
               if(board[i][j] == word[0]) {
                    if(helper(board, word, i, j, 0)) {
                        return true;
                    }
               }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& b, string w, int i, int j, int curr) {
        if (i < 0 || i >= b.size() || j < 0 || j >= b[i].size() || b[i][j] != w[curr]) {
            return false;
        }

        if (curr == w.size() - 1) {
            return true;
        }

        b[i][j] = '#';

        if(helper(b, w, i+1, j, curr+1) || helper(b, w, i-1, j, curr+1) || helper(b, w, i, j+1, curr+1) || helper(b, w, i, j-1, curr+1)) {
            return true;
        }
        b[i][j] = w[curr];
        return false;
    }
};
// @lc code=end

