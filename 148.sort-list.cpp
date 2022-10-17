/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }   

        ListNode* midPrev = nullptr;
        ListNode* slow = head;
        while (slow && slow->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            slow = slow->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;

        return dummyHead.next; 
    }    
};
// @lc code=end

