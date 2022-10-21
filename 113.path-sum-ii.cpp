/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> out;
        helper(root, targetSum, 0, {}, out);
        return out;
    }

    void helper(TreeNode* root, int target, int curr, vector<int> currTotal, vector<vector<int>>& out) {
        if(!root) {
            return;
        }

        curr += root->val;
        currTotal.push_back(root->val);
        if(!root->left && !root->right && curr == target) {
            out.push_back(currTotal);
            return;
        }
        helper(root->left, target, curr, currTotal, out);
        helper(root->right, target, curr, currTotal, out);
    }
};
// @lc code=end

