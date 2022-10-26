/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
    
private:
    
    void encode(TreeNode* root, ostringstream& out) {
        if (root == NULL) {
            out << "N ";
            return;
        }
        
        out << root->val << " ";
        
        encode(root->left, out);
        encode(root->right, out);
    }
    
    TreeNode* decode(istringstream& in) {
        string value = "";
        in >> value;
        
        if (value == "N") {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(value));
        
        root->left = decode(in);
        root->right = decode(in);
        
        return root;
    }
    
};

// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string out;
//         out.reserve(100000);
//         preorder(root, out);
//         out.pop_back(); // remove last ','
//         return out;
//     }

//     void preorder(TreeNode* root, string& out) {
//         if(root) {
//             out.append(to_string(root->val).append(","));
//             preorder(root->left, out);
//             preorder(root->right, out);
//         } else {
//             out.append("N,");
//         }
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data.size() == 0) {
//             return nullptr;
//         }

//         vector<string> values;
//         string curr;
//         for(char c: data) {
//             if(c != ',') {
//                 curr += c;
//             } else {
//                 values.push_back(curr);
//                 curr = "";
//             }
//         }
//         values.push_back(curr);
//         int index = 0;
//         return helper(data, index, values);
//     }

//     TreeNode* helper(string data, int& index, vector<string> values) {
//         if(values[index] == "N") {
//             index++;
//             return nullptr;
//         }

//         TreeNode* root = new TreeNode(stoi(values[index]));
//         index++;
//         root->left = helper(data, index, values);
//         root->right = helper(data, index, values);
//         return root;
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

