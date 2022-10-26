/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return helper(preorder, inorder, index, 0, preorder.size()-1);
    }

    TreeNode* helper(vector<int> preorder, vector<int> inorder, int& index, int left, int right) {
        if(left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[index]);

        int idx = 0;
        for(int i = 0; i <= inorder.size(); i++) {
            if(inorder[i] == preorder[index]) {
                idx = i;
                break;
            }
        }
        index++;

        root->left = helper(preorder, inorder, index, left, idx-1);
        root->right = helper(preorder, inorder, index, idx+1, right);

        return root;
    }
};
// @lc code=end

