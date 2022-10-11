/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

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
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> out;
        if(root == nullptr) {
            return out;
        }
        out.push_back({root->val});

        queue<TreeNode*> current;
        if(root->left == nullptr && root->right == nullptr) {
            return out;
        }

        current.push(root->left);
        current.push(root->right);

        vector<int> curr;
        queue<TreeNode*> next;
        while(true) {
            while(!current.empty()) {
                TreeNode* t = current.front();
                if(t != nullptr) {
                    // add left and right children to process next
                    if(t->left != nullptr) {
                        next.push(t->left);
                    }
                    if(t->right != nullptr) {
                        next.push(t->right);
                    }
                    // finish processing current
                    curr.push_back(t->val);
                }
                current.pop();
            }
            out.push_back(curr);
            curr.clear();
            current = next;
            while(!next.empty()) next.pop(); // empty q
            if(current.size() == 0) {
                break;
            }
        }
        return out;
    }
};
// @lc code=end

