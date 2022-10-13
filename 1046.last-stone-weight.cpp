/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone: stones) {
            pq.push(stone);
        } 

        while(pq.size() > 1) {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            pq.push(max(s2,s1) - min(s2,s1));
        }
        return pq.top();
    }
};
// @lc code=end

