/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
struct node {
    unordered_map<char, node*> children;
    bool is_end;
    node() {
        is_end = false;
    }
};

class Trie {
private:
    node* root;
public:
    Trie() {
        root = new node();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
        node* curr = root;

        for(char c: word) {
            // if char doesn't exist, add to child
            if(curr->children.find(c) == curr->children.end()) {
                node* newNode = new node();
                curr->children[c] = newNode;
            }
            curr = curr->children[c];
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        node* curr = root;
        for(char c: word) {
            if(curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        } 
        return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        node* curr = root;
        for(char c: prefix) {
            if(curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        } 
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

