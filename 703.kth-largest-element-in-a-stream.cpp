/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */
#include<queue>
#include<vector>

using namespace std;

// @lc code=start
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_elem;
public:
    KthLargest(int k, vector<int>& nums) {
        k_elem = k;
        for(int num: nums) {
            pq.push(num);
            if(pq.size()>k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k_elem) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

