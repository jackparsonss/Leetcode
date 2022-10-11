/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       long long lo = 0, hi = n;
       long long last_bad;
       while(lo <= hi) {
            long long mid = (hi + lo) / 2;
            if(isBadVersion(mid)) {
                hi = mid - 1;
                last_bad = mid;
            } else {
                lo = mid + 1;
            }
       }

       return last_bad;
    }
};
// @lc code=end

