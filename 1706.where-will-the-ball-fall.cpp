/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        vector<int> out;
        for (int k = 0; k < n; k++){
            int i = 0, j = k; 
            bool is_valid = true;
            while(i < m && j < n){
                if(grid[i][j] == 1){
                    if(j+1 >= n || grid[i][j+1] == -1) {
                        out.push_back(-1);
                        is_valid = false;
                        break;
                    } else {
                        i++;
                        j++;
                    }
                } else {
                    if(j-1 < 0 || grid[i][j-1] == 1) {
                        out.push_back(-1);
                        is_valid = false;
                        break;
                    } else {
                        i++;
                        j--;
                    }
                }
            }
            if(is_valid) {
                out.push_back(j);
            }
        }
        
        return out;
    }
};
// @lc code=end

