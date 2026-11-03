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
    ListNode* deleteMiddle(ListNode* head) {
        // if(!head) {
        //     return nullptr;
        // }

        // ListNode* slow = head;
        // ListNode* prev = nullptr;
        // ListNode* fast = head;

        // while(fast && fast->next) {
        //     prev = slow;
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }

        // prev->next = slow->next;
        // delete slow;

        // return head;

        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;          // 'slow' moves 1 step
            fast = fast->next->next;    // 'fast' moves 2 steps
        }

        // Unlink the middle node by bypassing it (DO NOT call delete)
        prev->next = slow->next;

        return head;
    }
};
