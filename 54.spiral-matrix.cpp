/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> out;
       int rows = matrix.size(), cols = matrix[0].size();
       int left = 0, up = 0;
       int right = cols - 1, down = rows - 1;
       while(out.size() < rows * cols) {
            for (int i = left; i <= right; i++){
                out.push_back(matrix[up][i]);
            }
            for (int i = up+1; i <= down; i++){
                out.push_back(matrix[i][right]);
            }

            if(up != down) {
                for (int i = right-1; i > left-1; i--){
                    out.push_back(matrix[down][i]);
                }
            }

            if(left != right) {
                for (int i = down-1; i > up; i--){
                    out.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            up++;
            down--;
            
       } 

       return out;
    }
};
// @lc code=end

