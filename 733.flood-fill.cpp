/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

#include<vector>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));

       stack<pair<int, int>> s;
       s.push({sr, sc});
       while(!s.empty()) {
            int i = s.top().first;
            int j = s.top().second;
            s.pop();

            if(visited[i][j]) {
                continue;
            }

            // check bounds and equality
            if(i - 1 >= 0 && image[i-1][j] == image[i][j]) {
                s.push({i-1, j});
            }
            if(i + 1 < image.size() && image[i+1][j] == image[i][j]) {
                s.push({i+1, j});
            }
            if(j - 1 >= 0 && image[i][j-1] == image[i][j]) {
                s.push({i, j-1});
            }
            if(j + 1 < image[0].size() && image[i][j+1] == image[i][j]) {
                s.push({i, j+1});
            }

            visited[i][j] = true;
            image[i][j] = color;
       }

       return image;
    }
};
// @lc code=end

