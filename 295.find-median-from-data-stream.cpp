/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
#include<queue>
using namespace std;

/*
s: 10, 11
g: 12, 13
*/
// @lc code=start
class MedianFinder {
private:
    priority_queue<int> spq; // max-heap
    priority_queue<int, vector<int>, greater<int>> gpq; // min-heap
public:
    // O(log(n))
    void addNum(int num) {
        if(spq.size() == 0) {
            spq.push(num);
            return;
        } 

        if(gpq.size() == 0) {
            if(num < spq.top()) {
                gpq.push(spq.top());
                spq.pop();
                spq.push(num);
                return;
            } 
            gpq.push(num);
            return;
        }

        if(num < spq.top()) {
            if(spq.size() <= gpq.size()){
                spq.push(num);
                return;
            }
            // move max of left into right
            gpq.push(spq.top());
            spq.pop();
            spq.push(num);
            return; 
        } 

        // num >= max of the left 
        if(gpq.size() <= spq.size()){
            gpq.push(num);
            return;
        }

        if(num < gpq.top()) {
            spq.push(num);
            return;
        }
        // move min of right into left
        spq.push(gpq.top());
        gpq.pop();
        gpq.push(num);
    }

    // O(1)
    double findMedian() {
        if(spq.size() == gpq.size()) {
            return (double)(spq.top() + gpq.top()) / 2.0;
        }

        if(spq.size() > gpq.size()) {
            return spq.top();
        }
        return gpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

