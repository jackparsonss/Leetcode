/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<algorithm>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sol = INT_MIN;
        helper(root, sol);
        return sol;
    }

    int helper(TreeNode* node, int& sol) {
        if(!node){
            return 0;
        }

        int left = max(helper(node->left, sol), 0);
        int right = max(helper(node->right, sol), 0);

        // only join curr on the sol
        int curr = node->val + left + right;
        sol = max(sol, curr);

        // recurse on best path
        return node->val + max(left, right);
    }
};
// @lc code=end

