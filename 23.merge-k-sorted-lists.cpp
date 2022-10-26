/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include<vector>
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) {
            return nullptr;
        }
        while(n > 1) {
            for(int i = 0; i < n/2; i++) {
                lists[i] = merge(lists[i], lists[n-i-1]);
            }
            n = (n+1)/2;
        }
        return lists[0];
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL && right == NULL) {
            return NULL;
        }
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }

        ListNode* temp = nullptr;
        if(left->val < right->val) {
            temp = left;
            left = left->next;
        } else {
            temp = right;
            right = right->next;
        }
        ListNode* curr = temp;

        while(left != nullptr && right != nullptr) {
            if(left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        while(left != nullptr) {
            curr->next = left;
            left = left->next;
            curr = curr->next;
        }

        while(right != nullptr) {
            curr->next = right;
            right = right->next;
            curr = curr->next;
        }

        return temp;
    }
};
// @lc code=end

