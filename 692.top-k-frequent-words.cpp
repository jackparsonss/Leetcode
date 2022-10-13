/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

// @lc code=start
struct mypair {
    string word;
    int count;
    bool operator<(const mypair &rhs) const { 
        if(count == rhs.count) {
            return word > rhs.word;
        }
        return count < rhs.count; 
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<mypair> pq;
        unordered_map<string, int> m;
        for(string word: words) {
            m[word]++;
        }

        for(auto [key, value]: m) {
            pq.push({key, value});
        }

        vector<string> out;
        for (int i = 0; i < k; i++){
            out.push_back(pq.top().word);
            pq.pop();
        }
        return out;
    }
};
// @lc code=end

