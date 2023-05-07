/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* second = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        
        while(second != nullptr) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        second = prev;
        while(second != nullptr) {
            ListNode* temp = head->next;
            ListNode* temp2 = second->next;

            head->next = second;
            second->next = temp;

            head = temp;
            second = temp2;
        }
    }
};
// @lc code=end

