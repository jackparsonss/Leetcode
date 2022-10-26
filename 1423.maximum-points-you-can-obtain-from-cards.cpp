/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0, right = cardPoints.size()-k-1; 
        int curr = 0;
        int best = INT_MIN;

        // create initial window;
        for(int i = right+1; i < cardPoints.size(); i++) {
            curr += cardPoints[i];
        }

        while(right < cardPoints.size()-1) {
            best = max(best, curr);
            curr += cardPoints[left];
            curr -= cardPoints[right+1];
            right++;
            left++;
        }

        return max(best, curr);
    }
};
// @lc code=end

