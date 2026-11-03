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
    void reorderList(ListNode* head) {
        auto* fast = head;
        auto* slow = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto* second = slow->next;
        auto* curr = second;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while(curr) {
            auto* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        auto* first = head;
        second = prev;

        while(second) {
            auto* tempFirst = first->next;
            auto* tempSecond = second->next;

            first->next = second;
            second->next = tempFirst;

            first = tempFirst;
            second = tempSecond;
        }
    }
};
