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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        auto* lastKept = &dummy;
        auto* curr = head;

        while(curr) {
            if(curr->next && curr->next->val == curr->val) {
                int duplicateVal = curr->val;

                while(curr && curr->val == duplicateVal) {
                    auto* toDelete = curr;
                    curr = curr->next;
                    delete toDelete;
                }

                lastKept->next = curr;
            }
            else {
                lastKept = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
