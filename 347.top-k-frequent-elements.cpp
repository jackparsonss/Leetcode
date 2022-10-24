/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// @lc code=start

struct node {
    int num, count;
    bool operator<(const node rhs) const {
        return count < rhs.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<node> freqs;
        unordered_map<int, int> m;
        for(int num: nums) {
            m[num]++;
        }

        for(auto [key, value]: m) {
            freqs.push({key, value});
        }

        vector<int> out;
        for (int i = 0; i < k; i++){
            out.push_back(freqs.top().num);
            freqs.pop();
        }

        return out;
    }
};
// @lc code=end

