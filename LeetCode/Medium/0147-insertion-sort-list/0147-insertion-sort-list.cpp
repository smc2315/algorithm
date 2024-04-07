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
    void print(ListNode* head) {
        head = head->next;
        while(head) {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }

    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1e9, head);
        ListNode* cur = head;
        ListNode* pre = dummy;

        while(cur) {
            if(cur -> val < pre -> val) {
                ListNode* tmp = dummy;
                while(tmp -> next -> val < cur -> val) {
                    tmp = tmp -> next;
                }
                pre -> next = cur -> next;
                cur -> next = tmp -> next;
                tmp -> next = cur;
                cur = pre -> next;
                
            }
            else {
                pre = cur;
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};