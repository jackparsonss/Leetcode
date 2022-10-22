/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return helper(matrix, target, 0, matrix[0].size()-1);
    }

    bool helper(vector<vector<int>> mat, int tar, int i, int j) {
        if(i >= mat.size() || j < 0) {
            return false;
        }
        if(mat[i][j] == tar) {
            return true;
        }

        if(mat[i][j] < tar) {
            return helper(mat, tar, i+1, j);
        }
        return helper(mat, tar, i, j-1);
    }

};
// @lc code=end

