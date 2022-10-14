/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */
// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) {
            return 0;
        } 

        if(n < 3) {
            return 1;
        }

        vector<int> fib(n+1);
        fib[0] = 0; 
        fib[1] = 1; 
        fib[2] = 1; 
        for (int i = 3; i <= n; i++){
            fib[i] = fib[i-1] + fib[i-2] + fib[i-3];
        }
        return fib[n]; 
    }
};
// @lc code=end

