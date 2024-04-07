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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* current = head->next;
        ListNode* prev = head;

        while (current) {
            if (current->val < prev->val) {
                ListNode* temp = dummy;
                while (temp->next->val < current->val) {
                    temp = temp->next;
                }
                prev->next = current->next;
                current->next = temp->next;
                temp->next = current;
                current = prev->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};