/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include<vector>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(visited[i][j] || grid[i][j] == '0'){
                    continue;
                }

                stack<pair<int, int>> s;
                s.push({i,j});
                islands++;
                while(!s.empty()) {
                    int k = s.top().first;
                    int l = s.top().second;
                    visited[k][l] = true;
                    s.pop();

                    if(k-1 >= 0 && !visited[k-1][l] && grid[k-1][l] != '0') {
                        s.push({k-1,l});
                    }
                    if(k+1 < m && !visited[k+1][l] && grid[k+1][l] != '0') {
                        s.push({k+1,l});
                    }
                    if(l-1 >= 0 && !visited[k][l-1] && grid[k][l-1] != '0') {
                        s.push({k,l-1});
                    }
                    if(l+1 < n && !visited[k][l+1] && grid[k][l+1] != '0') {
                        s.push({k,l+1});
                    }
                }
            }
       }
       return islands;
    }
};
// @lc code=end

