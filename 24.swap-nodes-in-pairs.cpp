/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* out = head->next;
        ListNode* curr = head;
        while(curr && curr->next) {
            ListNode* first = curr;
            ListNode* second = curr->next;
            curr = curr->next->next;
            if(curr && curr->next) {
                first->next = curr->next;
            } else {
                first->next = curr;                 
            }

            second->next = first;
        }

        return out;   
    }
};
// @lc code=end

