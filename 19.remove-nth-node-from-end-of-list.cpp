/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) {
            return nullptr;
        }
        int size = 0;
        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }

        int k = size - n;
        temp = head;
        for (int i = 0; i < k-1; i++){
            temp = temp->next;
        }

        if(temp->next && temp->next->next) {
            temp->next = temp->next->next;
            return head;
        }

        if(!temp->next->next) {
            temp->next = nullptr;
        }

        return head;
    }
};
// @lc code=end

